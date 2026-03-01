#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include "headers/main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.resize(400, 300);
    window.setWindowTitle("Calculator");
    window.show();

    return app.exec();
}
