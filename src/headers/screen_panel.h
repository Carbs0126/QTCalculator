#ifndef SCREEN_PANEL_H
#define SCREEN_PANEL_H


#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

class ScreenPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenPanel(QWidget *parent = nullptr);
    // todo
    void inputInfo(const QString &info);

    // todo
    // 对外提供的启动动画接口
    void startAnimation();


private:

    QHBoxLayout *layoutH;

    QLineEdit *mLineEdit;
    // QLineEdit *normalEdit = new QLineEdit();
    // normalEdit->setPlaceholderText("请输入普通文本"); // 占位提示文字
    // layout->addWidget(normalEdit);

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
