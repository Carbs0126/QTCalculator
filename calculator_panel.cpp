#include "calculator_panel.h"

#include <QDebug>

CalculatorPanel::CalculatorPanel(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    createButtons();
    setLayout(layout);
}

void CalculatorPanel::createButtons()
{
    // 定义按钮文本（按计算器布局）
    QStringList buttonTexts = {
        "C", "±", "%", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "0", ".", "="
    };

    // 创建按钮并连接信号
    for (const QString &text : buttonTexts) {
        QPushButton *btn = new QPushButton(text, this);
        btn->setMinimumSize(60, 60);
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

void CalculatorPanel::onButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        emit buttonClicked(btn->text());
    }
}
