/**
 * @file AliasStore.h
 * @brief 别名持久化存储：JSON 文件读写，线程安全。
 *
 * 存储格式（JSON）：
 *   { "schema_version": 1, "aliases": [
 *       { "unit_id": "...", "alias": "...", "updated_at_ms": 1234567890123 }
 *   ] }
 *
 * 版本: 1.0
 */

#ifndef ALIAS_STORE_H
#define ALIAS_STORE_H

#include <QMutex>
#include <QString>
#include <QStringList>
#include <QVector>

class AliasStore {
public:
    /**
     * @brief 构造 AliasStore。
     * @param filePath JSON 文件路径；为空则使用 defaultFilePath()。
     */
    explicit AliasStore(const QString &filePath = QString());

    /** @brief 别名记录 */
    struct AliasRecord {
        QString unitId;      /**< 智能体 UID */
        QString alias;       /**< 已规范化的别名 */
        qint64 updatedAtMs = 0; /**< 更新时间（Unix 毫秒） */
    };

    /**
     * @brief 从 JSON 文件加载别名记录。
     * @return true 表示加载成功（含文件不存在时以空记录启动）。
     */
    bool load();

    /**
     * @brief 将当前别名记录原子写入 JSON 文件（使用 QSaveFile）。
     * @return true 表示写入成功。
     */
    bool save();

    /** @brief 获取所有别名记录 */
    QVector<AliasRecord> allAliases() const;

    /** @brief 按 unit_id 获取别名（空字符串表示未设置） */
    QString aliasForUnit(const QString &unitId) const;

    /** @brief 按规范化别名查找 unit_id（空字符串表示未找到） */
    QString unitForAlias(const QString &normalizedAlias) const;

    /**
     * @brief 设置或更新别名。
     * @param unitId 智能体 UID
     * @param alias 已规范化的别名
     * @param nowMs 当前时间戳（Unix 毫秒）
     * @return true 表示成功
     */
    bool setAlias(const QString &unitId, const QString &alias, qint64 nowMs);

    /**
     * @brief 移除某 unit_id 的别名记录。
     * @param unitId 智能体 UID
     * @return true 表示移除成功（含记录本来就不存在的情况）
     */
    bool removeAlias(const QString &unitId);

    /** @brief 检查规范化别名是否已被占用 */
    bool hasAlias(const QString &normalizedAlias) const;

    /** @brief 获取所有别名字符串列表 */
    QStringList allAliasStrings() const;

    /** @brief 获取所有 unit_id 字符串列表 */
    QStringList allUnitIds() const;

private:
    /** @brief 默认文件路径：QCoreApplication::applicationDirPath() + "/AgentAliases.json" */
    static QString defaultFilePath();

    QString filePath_;
    QVector<AliasRecord> records_;
    mutable QMutex mutex_;
};

#endif // ALIAS_STORE_H
