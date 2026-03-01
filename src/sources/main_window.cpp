#include "../headers/main_window.h"
#include "../headers/calculator_panel.h"
#include "../headers/button_info.h"

#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    this->label = new QLabel("点击下方按键：", this);
    CalculatorPanel *calcPanel = new CalculatorPanel(this);

    // calcPanel->setMinimumSize(300, 400);

    connect(calcPanel, &CalculatorPanel::buttonClicked,
            [=](const QString &text)
            {
                if (text == ButtonInfo::INFO_OPERATOR_EQUAL)
                {
                    this->calculate();
                }
                else
                {
                    this->appendInfo(text);
                }
                qDebug() << "你按下了: " + text;
                // this->mCurrentExpression =
                // label->setText("你按下了: " + text);
            });

    mainLayout->addWidget(label);
    mainLayout->addWidget(calcPanel);

    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet("background-color: #F7F7F7;");
    label->setStyleSheet("background-color: #6600FF00;");
    calcPanel->setStyleSheet("background-color: #66FF0000;");

    setFixedSize(sizeHint());
    // resize(sizeHint());
}

void MainWindow::appendInfo(const QString &text)
{
    this->mCurrentExpression.append(text);
}

void MainWindow::calculate()
{
    this->label->setText("计算表达式 :" + this->mCurrentExpression);
    this->mCurrentExpression = "";
}
