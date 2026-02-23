#include "../headers/round_button.h"

RoundButton::RoundButton(const QString &text, QWidget *parent):QPushButton(text, parent), mPressProgress(0.0)
{
    setCursor(Qt::PointingHandCursor);

    setAttribute(Qt::WA_Hover, true);

    mQPropertyAnimation = new QPropertyAnimation(this, "pressProgress", this);

    mQPropertyAnimation->setDuration(1000);

    // 以下两行可以
    // connect(this, &QPushButton::pressed, this, &RoundButton::onPress);
    // connect(this, &QPushButton::released, this, &RoundButton::onRelease);

    connect(this, &RoundButton::pressed, this, &RoundButton::onPress);
    connect(this, &RoundButton::released, this, &RoundButton::onRelease);

    // 设置初始样式
    setStyleSheet("QPushButton {"
                  "   border-radius: 10px;"           // 圆角半径
                  "   border: none;"
                  "   color: white;"
                  "   background-color: #4A90E2;"
                  "   font-size: 14px;"
                  "   font-weight: bold;"
                  "}"
                  // 注意：这里不需要设置 background-color，由 setPressProgress 动态生成
                  );
}

void RoundButton::setPressProgress(qreal progress)
{
    mPressProgress = progress;

    // 计算颜色插值
    // 起始色 (未按下): 蓝色 #4A90E2
    // 结束色 (按下): 深蓝色 #2C5AA0

    int r = 74 + static_cast<int>((44 - 74) * progress);
    int g = 144 + static_cast<int>((90 - 144) * progress);
    int b = 226 + static_cast<int>((160 - 226) * progress);

    QString bgColor = QString("rgb(%1, %2, %3)").arg(r).arg(g).arg(b);


    // 更新样式表背景色
    setStyleSheet(QString("QPushButton {"
                          "   border-radius: 10px;"
                          "   border: none;"
                          "   background-color: %1;"
                          "   color: white;"
                          "   font-size: 14px;"
                          "   font-weight: bold;"
                          "}").arg(bgColor));
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
    if (!isDown()) { // 确保按钮确实被释放了（没有被移出按钮区域）
        mQPropertyAnimation->stop();
        mQPropertyAnimation->setStartValue(mPressProgress);
        mQPropertyAnimation->setEndValue(0.0);
        mQPropertyAnimation->start();
    }
}

void RoundButton::enterEvent(QEnterEvent *event)
{
    // 鼠标进入时调用你的方法
    // onHoverEnter();
    QPushButton::enterEvent(event); // 调用父类

    // std::cout << "enter event" << std::endl;
    qDebug() << "鼠标进入按钮区域";

}

void RoundButton::leaveEvent(QEvent *event)
{
    // 鼠标离开时调用你的方法
    // onHoverLeave();
    QPushButton::leaveEvent(event);

    // std::cout << "leave event" << std::endl;
    qDebug() << "鼠标离开按钮区域";
}

