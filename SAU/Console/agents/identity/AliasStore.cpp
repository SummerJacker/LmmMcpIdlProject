/**
 * @file AliasStore.cpp
 * @brief 别名持久化存储实现：JSON 文件读写，原子写入，损坏恢复。
 */

#include "AliasStore.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QMutexLocker>
#include <QString>
#include <QStringList>
#include <QVector>

// ---------------------------------------------------------------------------
// 构造
// ---------------------------------------------------------------------------

AliasStore::AliasStore(const QString &filePath)
    : filePath_(filePath)
{
}

// ---------------------------------------------------------------------------
// defaultFilePath
// ---------------------------------------------------------------------------

QString AliasStore::defaultFilePath()
{
    return QCoreApplication::applicationDirPath() + QStringLiteral("/AgentAliases.json");
}

// ---------------------------------------------------------------------------
// load
// ---------------------------------------------------------------------------

bool AliasStore::load()
{
    QMutexLocker locker(&mutex_);

    const QString path = filePath_.isEmpty() ? defaultFilePath() : filePath_;
    if (path.isEmpty()) {
        records_.clear();
        return false;
    }

    // Resolve early so save() writes to the same canonical path
    filePath_ = path;

    QFile file(path);
    if (!file.exists()) {
        records_.clear();
        return true; // no file yet, start empty
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("AliasStore: cannot open %s for reading", qPrintable(path));
        records_.clear();
        return true; // start empty rather than failing
    }

    const QByteArray raw = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(raw, &parseError);

    if (parseError.error != QJsonParseError::NoError || !doc.isObject()) {
        // Corrupted file: copy to timestamped backup, then start fresh
        const QString timestamp =
            QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMdd_HHmmss"));
        const QString backupPath = path + QStringLiteral(".corrupted.") + timestamp;
        QFile::copy(path, backupPath);
        qWarning("AliasStore: JSON parse error in %s: %s. Backup saved to %s",
                 qPrintable(path),
                 qPrintable(parseError.errorString()),
                 qPrintable(backupPath));
        records_.clear();
        return true;
    }

    const QJsonObject root = doc.object();
    const int schemaVersion = root.value(QStringLiteral("schema_version")).toInt(1);
    Q_UNUSED(schemaVersion);

    const QJsonArray aliases = root.value(QStringLiteral("aliases")).toArray();
    records_.clear();
    records_.reserve(aliases.size());

    for (const QJsonValue &val : aliases) {
        if (!val.isObject())
            continue;
        const QJsonObject obj = val.toObject();
        AliasRecord rec;
        rec.unitId = obj.value(QStringLiteral("unit_id")).toString();
        rec.alias = obj.value(QStringLiteral("alias")).toString();
        rec.updatedAtMs = static_cast<qint64>(obj.value(QStringLiteral("updated_at_ms")).toDouble());

        // Skip malformed entries
        if (!rec.unitId.isEmpty() && !rec.alias.isEmpty())
            records_.append(rec);
    }

    return true;
}

// ---------------------------------------------------------------------------
// save
// ---------------------------------------------------------------------------

bool AliasStore::save()
{
    QMutexLocker locker(&mutex_);

    const QString path = filePath_.isEmpty() ? defaultFilePath() : filePath_;
    if (path.isEmpty())
        return false;

    QJsonArray aliases;
    for (const AliasRecord &rec : records_) {
        QJsonObject obj;
        obj.insert(QStringLiteral("unit_id"), QJsonValue(rec.unitId));
        obj.insert(QStringLiteral("alias"), QJsonValue(rec.alias));
        obj.insert(QStringLiteral("updated_at_ms"),
                   QJsonValue(static_cast<double>(rec.updatedAtMs)));
        aliases.append(QJsonValue(obj));
    }

    QJsonObject root;
    root.insert(QStringLiteral("schema_version"), QJsonValue(1));
    root.insert(QStringLiteral("aliases"), QJsonValue(aliases));

    QJsonDocument doc(root);

    // Ensure parent directory exists
    QFileInfo fi(path);
    QDir().mkpath(fi.absolutePath());

    // Atomic save: write to temp file, then rename
    const QString tmpPath = path + QStringLiteral(".tmp");
    QFile tmpFile(tmpPath);
    if (!tmpFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning("AliasStore: cannot open %s for writing", qPrintable(tmpPath));
        return false;
    }

    const QByteArray data = doc.toJson(QJsonDocument::Indented);
    qint64 written = tmpFile.write(data);
    tmpFile.close();

    if (written != data.size()) {
        qWarning("AliasStore: write to %s incomplete (%lld/%d bytes)",
                 qPrintable(tmpPath), written, data.size());
        QFile::remove(tmpPath);
        return false;
    }

    // Remove old file, then rename temp to target
    QFile::remove(path);
    if (!QFile::rename(tmpPath, path)) {
        qWarning("AliasStore: failed to rename %s -> %s",
                 qPrintable(tmpPath), qPrintable(path));
        QFile::remove(tmpPath);
        return false;
    }

    return true;
}

// ---------------------------------------------------------------------------
// 查询
// ---------------------------------------------------------------------------

QVector<AliasStore::AliasRecord> AliasStore::allAliases() const
{
    QMutexLocker locker(&mutex_);
    return records_;
}

QString AliasStore::aliasForUnit(const QString &unitId) const
{
    QMutexLocker locker(&mutex_);
    for (const AliasRecord &rec : records_) {
        if (rec.unitId == unitId)
            return rec.alias;
    }
    return QString();
}

QString AliasStore::unitForAlias(const QString &normalizedAlias) const
{
    QMutexLocker locker(&mutex_);
    const QString cmpKey = normalizedAlias.toCaseFolded();
    for (const AliasRecord &rec : records_) {
        if (rec.alias.toCaseFolded() == cmpKey)
            return rec.unitId;
    }
    return QString();
}

// ---------------------------------------------------------------------------
// 修改
// ---------------------------------------------------------------------------

bool AliasStore::setAlias(const QString &unitId, const QString &alias, qint64 nowMs)
{
    QMutexLocker locker(&mutex_);

    // Update or insert
    for (int i = 0; i < records_.size(); ++i) {
        if (records_[i].unitId == unitId) {
            records_[i].alias = alias;
            records_[i].updatedAtMs = nowMs;
            return true;
        }
    }

    AliasRecord rec;
    rec.unitId = unitId;
    rec.alias = alias;
    rec.updatedAtMs = nowMs;
    records_.append(rec);
    return true;
}

bool AliasStore::removeAlias(const QString &unitId)
{
    QMutexLocker locker(&mutex_);
    for (int i = 0; i < records_.size(); ++i) {
        if (records_[i].unitId == unitId) {
            records_.removeAt(i);
            return true;
        }
    }
    return true; // idempotent: removing a non-existent record is not an error
}

// ---------------------------------------------------------------------------
// 存在性检查
// ---------------------------------------------------------------------------

bool AliasStore::hasAlias(const QString &normalizedAlias) const
{
    QMutexLocker locker(&mutex_);
    const QString cmpKey = normalizedAlias.toCaseFolded();
    for (const AliasRecord &rec : records_) {
        if (rec.alias.toCaseFolded() == cmpKey)
            return true;
    }
    return false;
}

QStringList AliasStore::allAliasStrings() const
{
    QMutexLocker locker(&mutex_);
    QStringList list;
    list.reserve(records_.size());
    for (const AliasRecord &rec : records_) {
        list.append(rec.alias);
    }
    return list;
}

QStringList AliasStore::allUnitIds() const
{
    QMutexLocker locker(&mutex_);
    QStringList list;
    list.reserve(records_.size());
    for (const AliasRecord &rec : records_) {
        list.append(rec.unitId);
    }
    return list;
}
