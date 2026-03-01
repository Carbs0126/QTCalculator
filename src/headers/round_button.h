#ifndef ROUND_BUTTON_H
#define ROUND_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QDebug>

class RoundButton : public QPushButton
{
    Q_OBJECT
    // 声明一个用于动画的属性
    Q_PROPERTY(qreal pressProgress READ getPressProgress WRITE setPressProgress)

public:
    explicit RoundButton(const QString &text, QWidget *parent = nullptr);

    // 获取当前进度
    qreal getPressProgress() const
    {
        return mPressProgress;
    }

    // 设置进度并更新样式
    void setPressProgress(qreal progress);

    void setNormalBgColor(int color);

    void setPressedBgColor(int color);

    void setTextColor(int color);

    void resetStyle();

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private slots:
    void onPress();
    void onRelease();

private:
    // 当前动画进度(0.0 -> 1.0)
    qreal mPressProgress;
    QPropertyAnimation *mQPropertyAnimation;

    int mNormalBgColor;
    int mNormalBgColorR;
    int mNormalBgColorG;
    int mNormalBgColorB;

    int mPressedBgColor;
    int mPressedBgColorR;
    int mPressedBgColorG;
    int mPressedBgColorB;

    int mTextColorR;
    int mTextColorG;
    int mTextColorB;

    QString mTextColorStr;
};

#endif // ROUND_BUTTON_H
