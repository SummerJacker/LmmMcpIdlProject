#include "FormationTopologyView.h"
#include "console.h"  // Unit_Formation

#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QVector>

FormationTopologyView::FormationTopologyView(QWidget *parent)
    : QGraphicsView(parent)
{
    scene_ = new QGraphicsScene(this);
    setScene(scene_);
    setRenderHint(QPainter::Antialiasing);
    setBackgroundBrush(QColor(248, 248, 248));
}

void FormationTopologyView::refreshFromFormation(const Unit_Formation *formation)
{
    scene_->clear();
    if (formation == nullptr || formation->robot_ids._length == 0)
        return;

    const int n = (int)formation->robot_ids._length;
    const double spacing = 150.0;
    const double centerY = 70.0;
    QVector<QPointF> positions;
    positions.reserve(n);
    for (int i = 0; i < n; ++i)
        positions.append(QPointF(50.0 + i * spacing, centerY));

    // 边：follower -> leader（跨类型边用醒目黄色加粗）
    for (int i = 1; i < n; ++i) {
        const short leaderIdx = formation->leader_ids._buffer[i];
        if (leaderIdx < 0 || leaderIdx >= n)
            continue;
        const char *fromUid = formation->robot_ids._buffer[i];
        const char *toUid = formation->robot_ids._buffer[leaderIdx];
        if (fromUid == nullptr || toUid == nullptr)
            continue;
        const bool crossType =
            (fromUid[0] != '\0' && toUid[0] != '\0' && fromUid[0] != toUid[0]);
        QPen pen(crossType ? QColor(200, 140, 20) : QColor(120, 120, 120));
        pen.setWidth(crossType ? 3 : 1);
        scene_->addLine(QLineF(positions[i], positions[leaderIdx]), pen);
    }

    // 节点：AV 蓝色、GV 绿色
    for (int i = 0; i < n; ++i) {
        const char *uid = formation->robot_ids._buffer[i];
        if (uid == nullptr)
            continue;
        const bool isAir = (uid[0] == 'A');
        const QColor color = isAir ? QColor(70, 130, 180) : QColor(60, 160, 90);
        const QPointF p = positions[i];

        scene_->addEllipse(p.x() - 24, p.y() - 24, 48, 48,
                           QPen(color.darker(120)), QBrush(color));
        QGraphicsTextItem *label = scene_->addText(QString::fromUtf8(uid));
        label->setDefaultTextColor(Qt::black);
        label->setPos(p.x() - 20, p.y() + 26);
    }

    setSceneRect(scene_->itemsBoundingRect().adjusted(-25, -25, 25, 25));
}
