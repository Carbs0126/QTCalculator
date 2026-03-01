#include "../headers/screen_panel.h"
#include "../headers/button_info.h"
#include <QEasingCurve>

ScreenPanel::ScreenPanel(QWidget *parent) : QWidget(parent),
    m_animatedLabel(nullptr),
    m_opacityAnim(nullptr),
    m_posAnim(nullptr),
    m_animationGroup(nullptr)
{

    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(QString("* {"
                          "   background-color: #00ff00;"
                          "}"));

    layoutH = new QHBoxLayout();
    layoutH->setContentsMargins(0, 0, 0, 0); // 清空布局外边框（上下左右）


    mLineEdit = new QLineEdit(this);
    mLineEdit->setPlaceholderText("请输入普通文本"); // 占位提示文字
    mLineEdit->setAlignment(Qt::AlignRight);

    // mLineEdit->setFixedHeight(40);
    // 或设置最小/最大高度
    mLineEdit->setMinimumHeight(60);
    // mLineEdit->setMaximumHeight(50);

    // 无边框（本质也是调用样式表）
    mLineEdit->setFrame(false);

    mLineEdit->setStyleSheet(QString("* {"
                          "   border-radius: 10px;"
                          "   border: none;"
                          "   background-color: #ff0000;"
                          "   color: #0000ff;"
                          "   font-size: 24px;"
                          "   font-weight: 500;"
                          "}"));



    layoutH->addWidget(mLineEdit);

    this->setLayout(layoutH);

    // 初始化UI和动画
    // initUI();

    // 设置显示文本
    // if (!text.isEmpty()) {
        // m_animatedLabel->setText(text);
    // }
}

void ScreenPanel::inputInfo(const QString &info)
{
    if (info == ButtonInfo::INFO_OPERATOR_EQUAL)
    {
        // this->calculate();
    }
    else
    {
        // this->appendInfo(text);
    }
    qDebug() << "screen panel --> 你按下了: " + info;
}

void ScreenPanel::initUI()
{
    // 创建内部的QLabel，父控件设为当前自定义Widget
    m_animatedLabel = new QLabel(this);
    // 初始样式和位置
    m_animatedLabel->setStyleSheet("color: red; font-size: 20px;");
    m_animatedLabel->setGeometry(50, 100, 200, 50); // 初始位置X=50,Y=100
    // 启用透明背景支持
    m_animatedLabel->setAttribute(Qt::WA_TranslucentBackground);
    m_animatedLabel->setWindowOpacity(0.0); // 初始透明度0
}

void ScreenPanel::initAnimation()
{
    // 如果动画已创建，先删除旧的（避免重复创建）
    if (m_animationGroup) {
        m_animationGroup->deleteLater();
        m_animationGroup = nullptr;
    }

    // 1. 透明度动画
    m_opacityAnim = new QPropertyAnimation(m_animatedLabel, "windowOpacity");
    m_opacityAnim->setDuration(1500); // 1.5秒
    m_opacityAnim->setStartValue(0.0);
    m_opacityAnim->setEndValue(1.0);
    m_opacityAnim->setEasingCurve(QEasingCurve::InOutQuad);

    // 2. 位置动画（Y从100到20，X保持50）
    m_posAnim = new QPropertyAnimation(m_animatedLabel, "pos");
    m_posAnim->setDuration(1500);
    m_posAnim->setStartValue(QPoint(50, 100));
    m_posAnim->setEndValue(QPoint(50, 20));
    m_posAnim->setEasingCurve(QEasingCurve::InOutQuad);

    // 3. 组合动画
    m_animationGroup = new QParallelAnimationGroup(this);
    m_animationGroup->addAnimation(m_opacityAnim);
    m_animationGroup->addAnimation(m_posAnim);

    // 动画结束后自动清理（可选）
    connect(m_animationGroup, &QParallelAnimationGroup::finished, this, [=]() {
        m_opacityAnim = nullptr;
        m_posAnim = nullptr;
    });
}

void ScreenPanel::startAnimation()
{
    // 每次启动前重新初始化动画（支持重复调用）
    initAnimation();
    // 启动动画，结束后不自动删除（因为要支持重复启动）
    m_animationGroup->start();
}
