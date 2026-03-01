#ifndef SCREEN_PANEL_H
#define SCREEN_PANEL_H


#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

class ScreenPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenPanel(QWidget *parent = nullptr);

    // 对外提供的启动动画接口
    void startAnimation();



private:
    // 内部管理的QLabel
    QLabel *m_animatedLabel;

    // 动画相关成员
    QPropertyAnimation *m_opacityAnim;
    QPropertyAnimation *m_posAnim;
    QParallelAnimationGroup *m_animationGroup;

    // 初始化UI和动画
    void initUI();
    void initAnimation();
};

#endif // SCREEN_PANEL_H
