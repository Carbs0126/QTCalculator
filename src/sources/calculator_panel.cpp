#include "../headers/calculator_panel.h"
#include "../headers/round_button.h"
#include "../headers/button_info.h"

#include <QDebug>

CalculatorPanel::CalculatorPanel(QWidget *parent) : QWidget(parent)
{
    // setAutoFillBackground(true);
    setAttribute(Qt::WA_StyledBackground, true);  // 关键！允许样式表绘制背景

    // layout = new QGridLayout(this);
    // layout->setHorizontalSpacing(12);
    // layout->setVerticalSpacing(12);

    // createButtons();

    layout = new QVBoxLayout();
    addButtons();
    setLayout(layout);
}

/*
void CalculatorPanel::createButtons()
{
    // 定义按钮文本（按计算器布局）
    QStringList buttonTexts = {
        "C", "b", "%", "÷",
        "7", "8", "9", "×",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "0", ".", "="
    };

    // 创建按钮并连接信号
    for (const QString &text : buttonTexts) {
        RoundButton *btn = new RoundButton(text, this);
        btn->setMinimumSize(60, 60);
        if (text == "=") {
            btn->setTextColor(0xFFFFFF);
            btn->setNormalBgColor(0xF08B3A);
            btn->setPressedBgColor(0xE08235);
        } else if (text == "b") {
            btn->setText("");
            QIcon deleteIcon(":/res/images/icon_delete.png");
            btn->setIcon(deleteIcon);
            btn->setIconSize(QSize(32, 32));
            btn->setNormalBgColor(0xFFFFFF);
            btn->setPressedBgColor(0xE0E0E0);
        } else {
            btn->setTextColor(0x000000);
            btn->setNormalBgColor(0xFFFFFF);
            btn->setPressedBgColor(0xE0E0E0);
        }
        btn->resetStyle();
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // 水平/垂直都扩展


        connect(btn, &QPushButton::clicked, this, &CalculatorPanel::onButtonClicked);
        buttons.append(btn);
    }

    // 添加到网格布局（注意“0”占两列）
    layout->addWidget(buttons[0], 0, 0);  // C
    layout->addWidget(buttons[1], 0, 1);  // ±
    layout->addWidget(buttons[2], 0, 2);  // %
    layout->addWidget(buttons[3], 0, 3);  // /

    layout->addWidget(buttons[4], 1, 0);  // 7
    layout->addWidget(buttons[5], 1, 1);  // 8
    layout->addWidget(buttons[6], 1, 2);  // 9
    layout->addWidget(buttons[7], 1, 3);  // *

    layout->addWidget(buttons[8], 2, 0);  // 4
    layout->addWidget(buttons[9], 2, 1);  // 5
    layout->addWidget(buttons[10], 2, 2); // 6
    layout->addWidget(buttons[11], 2, 3); // -

    layout->addWidget(buttons[12], 3, 0); // 1
    layout->addWidget(buttons[13], 3, 1); // 2
    layout->addWidget(buttons[14], 3, 2); // 3
    layout->addWidget(buttons[15], 3, 3); // +

    layout->addWidget(buttons[16], 4, 0, 1, 2); // 0，跨两列
    layout->addWidget(buttons[17], 4, 2);       // .
    layout->addWidget(buttons[18], 4, 3);       // =
}
*/

void CalculatorPanel::addButtons() {

    QVector<ButtonInfo> buttonInfoList;

    // "C", "b", "%", "÷",
    // "7", "8", "9", "×",
    // "4", "5", "6", "-",
    // "1", "2", "3", "+",
    // "0", ".", "="

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


    // return;
    for (const ButtonInfo &info : buttonInfoList) {
        RoundButton *btn = new RoundButton(info.mText, this);
        btn->setMinimumSize(72, 72);
        btn->setTextColor(info.mTextColor);
        btn->setNormalBgColor(info.mNormalBgColor);
        btn->setPressedBgColor(info.mPressedBgColor);
        if (info.mIcon.length() > 0) {
             QIcon icon(info.mIcon);
             btn->setIcon(icon);
             btn->setIconSize(QSize(32, 32));
        }
        btn->resetStyle();

        connect(btn, &QPushButton::clicked, this, &CalculatorPanel::onButtonClicked);

        buttons.append(btn);
    }

    // return;

    // 改用 水平竖直方向布局


    // 1. 最外层：垂直布局（整个计算器的行）

    layout->setSpacing(12); // 行之间无间距
    layout->setContentsMargins(12, 12, 12, 12);

    // 2. 第一行：水平布局（C、±、%、/）
    QHBoxLayout* row1 = new QHBoxLayout();
    // row1->setContentsMargins(0, 0, 0, 0);
    row1->setSpacing(12);

    row1->addWidget(buttons[0]);
    row1->addWidget(buttons[1]);
    row1->addWidget(buttons[2]);
    row1->addWidget(buttons[3]);

    layout->addLayout(row1); // 把行1加入垂直布局



    // 3. 第二行：水平布局（7、8、9、*）
    QHBoxLayout* row2 = new QHBoxLayout();
    row2->setSpacing(12);

    row2->addWidget(buttons[4]);
    row2->addWidget(buttons[5]);
    row2->addWidget(buttons[6]);
    row2->addWidget(buttons[7]);

    layout->addLayout(row2);



    // 4. 第三行：水平布局（4、5、6、-）
    QHBoxLayout* row3 = new QHBoxLayout();
    row3->setSpacing(12);

    row3->addWidget(buttons[8]);
    row3->addWidget(buttons[9]);
    row3->addWidget(buttons[10]);
    row3->addWidget(buttons[11]);

    layout->addLayout(row3);

    // 5. 第四行：水平布局（1、2、3、+）
    QHBoxLayout* row4 = new QHBoxLayout();
    row4->setSpacing(12);

    row4->addWidget(buttons[12]);
    row4->addWidget(buttons[13]);
    row4->addWidget(buttons[14]);
    row4->addWidget(buttons[15]);

    layout->addLayout(row4);

    // 6. 第五行：水平布局（嵌套子布局实现0按钮跨列）
    QHBoxLayout* row5 = new QHBoxLayout();
    row5->setSpacing(12);

    QHBoxLayout* row5Left = new QHBoxLayout();
    row5Left->setSpacing(0);
    row5Left->addWidget(buttons[16]);

    QHBoxLayout* row5Right = new QHBoxLayout();
    row5Left->setSpacing(12);
    row5Right->addWidget(buttons[17], 1);
    row5Right->addWidget(buttons[18], 1);


    row5->addLayout(row5Left, 1);
    row5->addLayout(row5Right, 1);

    layout->addLayout(row5);

    layout->addStretch();

    return;


/*
    // 0按钮：占2列（用一个水平布局装0按钮，拉伸因子设为2）
    QPushButton* btn0 = new QPushButton("0");
    btn0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    row5->addWidget(btn0, 2); // 拉伸因子2（占2份空间）

    // .按钮：占1列
    QPushButton* btnDot = new QPushButton(".");
    btnDot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    row5->addWidget(btnDot, 1); // 拉伸因子1

    // =按钮：占1列（如果想让=按钮跨行，可单独用垂直布局）
    QPushButton* btnEqual = new QPushButton("=");
    btnEqual->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    row5->addWidget(btnEqual, 1); // 拉伸因子1

    layout->addLayout(row5);

    // 设置所有按钮的尺寸策略（自适应拉伸）
    QList<QPushButton*> btns = this->findChildren<QPushButton*>();
    for (QPushButton* btn : btns) {
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        btn->setMinimumSize(60, 60);
        btn->setStyleSheet("font-size: 24px;");
    }

*/




}

void CalculatorPanel::onButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        emit buttonClicked(btn->text());
    }
}
