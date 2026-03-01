#include <QApplication>

/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "测试111";

    return a.exec();
}
*/

// #include "headers/calculator_panel.h"
#include <QVBoxLayout>
#include <QLabel>

/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("演示一个自定义的 button");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // RoundButton *btn = new RoundButton("点击我");
    // QPushButton *btn = new QPushButton("点击我", &window);
    // btn->setFixedSize(120, 40);

    CalculatorPanel *calcPanel = new CalculatorPanel(&window);

    layout->addWidget(calcPanel, 0, Qt::AlignCenter);
    window.setLayout(layout);
    window.show();

    return app.exec();
}
*/

#include "headers/main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // QWidget window;
    MainWindow window; // 创建主窗口实例
    window.resize(400, 300);
    window.setWindowTitle("My App");
    window.show();

    return app.exec();
}
