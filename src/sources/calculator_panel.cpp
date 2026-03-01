#include "../headers/calculator_panel.h"
#include "../headers/round_button.h"
#include "../headers/button_info.h"

#include <QDebug>

CalculatorPanel::CalculatorPanel(QWidget *parent) : QWidget(parent)
{
    // 允许自定义的 QWidget 使用背景色
    setAttribute(Qt::WA_StyledBackground, true);
    // QVBoxLayout 构造函数中，没有传入 QWidget，后续使用 setLayout 函数主动设置layout
    layout = new QVBoxLayout();
    addButtons();
    setLayout(layout);
}

void CalculatorPanel::addButtons()
{

    QVector<ButtonInfo> buttonInfoList;

    // "C", "b", "%", "÷",
    // "7", "8", "9", "×",
    // "4", "5", "6", "-",
    // "1", "2", "3", "+",
    // "  0   ", ".", "="

    // white style
    int wsTextColor = 0x000000;
    int wsNormalBgColor = 0xFFFFFF;
    int wsPressedBgColor = 0xE0E0E0;

    // orange style
    int osTextColor = 0xFFFFFF;
    int osNormalBgColor = 0xF08B3A;
    int osPressedBgColor = 0xE08235;

    buttonInfoList.emplaceBack("C", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("", wsTextColor, wsNormalBgColor, wsPressedBgColor, ":/res/images/icon_delete.png");
    buttonInfoList.emplaceBack("%", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("÷", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("7", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("8", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("9", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("×", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("4", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("5", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("6", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("-", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("1", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("2", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("3", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("+", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("0", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack(".", wsTextColor, wsNormalBgColor, wsPressedBgColor);
    buttonInfoList.emplaceBack("=", osTextColor, osNormalBgColor, osPressedBgColor);

    for (const ButtonInfo &info : buttonInfoList)
    {
        RoundButton *btn = new RoundButton(info.mText, this);
        btn->setMinimumSize(72, 72);
        btn->setTextColor(info.mTextColor);
        btn->setNormalBgColor(info.mNormalBgColor);
        btn->setPressedBgColor(info.mPressedBgColor);
        if (info.mIcon.length() > 0)
        {
            QIcon icon(info.mIcon);
            btn->setIcon(icon);
            btn->setIconSize(QSize(32, 32));
        }
        btn->resetStyle();

        connect(btn, &QPushButton::clicked, this, &CalculatorPanel::onButtonClicked);

        buttons.append(btn);
    }

    // 1. 最外层：垂直布局（整个计算器的行）
    layout->setSpacing(12);
    layout->setContentsMargins(12, 12, 12, 12);

    // 2. 第一行：水平布局（C、±、%、/）
    QHBoxLayout *row1 = new QHBoxLayout();
    row1->setSpacing(12);
    row1->addWidget(buttons[0]);
    row1->addWidget(buttons[1]);
    row1->addWidget(buttons[2]);
    row1->addWidget(buttons[3]);
    layout->addLayout(row1);

    // 3. 第二行：水平布局（7、8、9、*）
    QHBoxLayout *row2 = new QHBoxLayout();
    row2->setSpacing(12);
    row2->addWidget(buttons[4]);
    row2->addWidget(buttons[5]);
    row2->addWidget(buttons[6]);
    row2->addWidget(buttons[7]);
    layout->addLayout(row2);

    // 4. 第三行：水平布局（4、5、6、-）
    QHBoxLayout *row3 = new QHBoxLayout();
    row3->setSpacing(12);
    row3->addWidget(buttons[8]);
    row3->addWidget(buttons[9]);
    row3->addWidget(buttons[10]);
    row3->addWidget(buttons[11]);
    layout->addLayout(row3);

    // 5. 第四行：水平布局（1、2、3、+）
    QHBoxLayout *row4 = new QHBoxLayout();
    row4->setSpacing(12);
    row4->addWidget(buttons[12]);
    row4->addWidget(buttons[13]);
    row4->addWidget(buttons[14]);
    row4->addWidget(buttons[15]);
    layout->addLayout(row4);

    // 6. 第五行：水平布局（嵌套子布局实现0按钮跨列）
    QHBoxLayout *row5 = new QHBoxLayout();
    row5->setSpacing(12);

    QHBoxLayout *row5Left = new QHBoxLayout();
    row5Left->setSpacing(0);
    row5Left->addWidget(buttons[16]);

    QHBoxLayout *row5Right = new QHBoxLayout();
    row5Left->setSpacing(12);
    row5Right->addWidget(buttons[17], 1);
    row5Right->addWidget(buttons[18], 1);

    row5->addLayout(row5Left, 1);
    row5->addLayout(row5Right, 1);
    layout->addLayout(row5);

    layout->addStretch();

}

void CalculatorPanel::onButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if (btn)
    {
        emit buttonClicked(btn->text());
    }
}
