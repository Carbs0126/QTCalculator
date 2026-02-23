#include "../headers/main_window.h"
#include "../headers/calculator_panel.h"

#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("点击下方按键：", this);
    CalculatorPanel *calcPanel = new CalculatorPanel(this);

    connect(calcPanel, &CalculatorPanel::buttonClicked, [=](const QString &text) {
        label->setText("你按下了: " + text);
    });

    mainLayout->addWidget(label);
    mainLayout->addWidget(calcPanel);
    setCentralWidget(centralWidget);
}
