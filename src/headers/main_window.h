#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);
    // todo 改成 screen
    QLabel *label;

private:
    void appendInfo(const QString &text);
    void calculate();

private:
    QString mCurrentExpression;
};

#endif // MAIN_WINDOW_H
