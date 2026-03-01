#include "../../headers/widget/round_button.h"

RoundButton::RoundButton(const QString &text, QWidget *parent) : QPushButton(text, parent), mPressProgress(0.0)
{
    setCursor(Qt::PointingHandCursor);

    setAttribute(Qt::WA_Hover, true);

    mQPropertyAnimation = new QPropertyAnimation(this, "pressProgress", this);

    mQPropertyAnimation->setDuration(200);

    // 以下两行可以
    // connect(this, &QPushButton::pressed, this, &RoundButton::onPress);
    // connect(this, &QPushButton::released, this, &RoundButton::onRelease);

    connect(this, &RoundButton::pressed, this, &RoundButton::onPress);
    connect(this, &RoundButton::released, this, &RoundButton::onRelease);
}

void RoundButton::setPressProgress(qreal progress)
{
    mPressProgress = progress;

    int r = mNormalBgColorR + static_cast<int>((mPressedBgColorR - mNormalBgColorR) * progress);
    int g = mNormalBgColorG + static_cast<int>((mPressedBgColorG - mNormalBgColorG) * progress);
    int b = mNormalBgColorB + static_cast<int>((mPressedBgColorB - mNormalBgColorB) * progress);

    QString bgColor = QString("rgb(%1, %2, %3)").arg(r).arg(g).arg(b);

    // 更新样式表背景色
    setStyleSheet(QString("* {"
                          "   border-radius: 10px;"
                          "   border: none;"
                          "   background-color: %1;"
                          "   color: %2;"
                          "   font-size: 24px;"
                          "   font-weight: 500;"
                          "}")
                      .arg(bgColor)
                      .arg(this->mTextColorStr));
}

void RoundButton::onPress()
{
    mQPropertyAnimation->stop();
    mQPropertyAnimation->setStartValue(mPressProgress);
    mQPropertyAnimation->setEndValue(1.0);
    mQPropertyAnimation->start();
}

void RoundButton::onRelease()
{
    if (!isDown())
    {
        // 确保按钮确实被释放了（没有被移出按钮区域）
        mQPropertyAnimation->stop();
        mQPropertyAnimation->setStartValue(mPressProgress);
        mQPropertyAnimation->setEndValue(0.0);
        mQPropertyAnimation->start();
    }
}

void RoundButton::enterEvent(QEnterEvent *event)
{
    // 鼠标进入时调用你的方法
    QPushButton::enterEvent(event); // 调用父类
    // qDebug() << "鼠标进入按钮区域";
}

void RoundButton::leaveEvent(QEvent *event)
{
    // 鼠标离开时调用你的方法
    QPushButton::leaveEvent(event);

    // qDebug() << "鼠标离开按钮区域";
}

void RoundButton::setNormalBgColor(int color)
{
    this->mNormalBgColor = color;
    this->mNormalBgColorR = (color >> 16) & 0xFF;
    this->mNormalBgColorG = (color >> 8) & 0xFF;
    this->mNormalBgColorB = (color >> 0) & 0xFF;
}

void RoundButton::setPressedBgColor(int color)
{
    this->mPressedBgColor = color;
    this->mPressedBgColorR = (color >> 16) & 0xFF;
    this->mPressedBgColorG = (color >> 8) & 0xFF;
    this->mPressedBgColorB = (color >> 0) & 0xFF;
}

void RoundButton::setTextColor(int color)
{
    this->mTextColorR = (color >> 16) & 0xFF;
    this->mTextColorG = (color >> 8) & 0xFF;
    this->mTextColorB = (color >> 0) & 0xFF;
    this->mTextColorStr = QString("rgb(%1, %2, %3)")
                              .arg(this->mTextColorR)
                              .arg(this->mTextColorG)
                              .arg(this->mTextColorB);
}

void RoundButton::resetStyle()
{
    this->setPressProgress(0);
}

void RoundButton::setInfo(const QString &info)
{
    this->mInfo = info;
}

QString RoundButton::getInfo()
{
    return this->mInfo;
}
