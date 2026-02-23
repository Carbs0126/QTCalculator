#ifndef ROUND_BUTTON_H
#define ROUND_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
// #include <iostream>
#include <QDebug>

class RoundButton : public QPushButton
{
    Q_OBJECT
    // 声明一个用于动画的属性
    Q_PROPERTY(qreal pressProgress READ getPressProgress WRITE setPressProgress)

public:
    explicit RoundButton(const QString &text, QWidget *parent = nullptr);

    // 获取当前进度
    qreal getPressProgress() const {
        return mPressProgress;
    }

    // 设置进度并更新样式
    void setPressProgress(qreal progress);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private slots:
    void onPress();
    void onRelease();

private:
    qreal mPressProgress;  // 当前动画进度(0.0 -> 1.0)
    QPropertyAnimation *mQPropertyAnimation;
};


#endif // ROUND_BUTTON_H
