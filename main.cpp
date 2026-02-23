#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "测试111";

    return a.exec();
}
