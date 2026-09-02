#ifndef FORMATION_TOPOLOGY_VIEW_H
#define FORMATION_TOPOLOGY_VIEW_H

#include <QGraphicsView>

// 前向声明（避免在头文件中引入 ILU 类型）
struct Unit_Formation;

/**
 * @brief 编队拓扑可视化画布：渲染链式编队（节点=单元，边=follower→leader）。
 *
 * - AV 节点用蓝色、GV 节点用绿色，跨类型边（空地连接）用醒目黄色加粗。
 * - 仅做展示，不参与下发逻辑；由 MainWindow 在录入/发送/重置后调用 refreshFromFormation 刷新。
 */
class FormationTopologyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit FormationTopologyView(QWidget *parent = nullptr);

    void refreshFromFormation(const Unit_Formation *formation);

private:
    QGraphicsScene *scene_;
};

#endif // FORMATION_TOPOLOGY_VIEW_H
