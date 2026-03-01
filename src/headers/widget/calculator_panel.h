#ifndef CALCULATOR_PANEL_H
#define CALCULATOR_PANEL_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>

class CalculatorPanel : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorPanel(QWidget *parent = nullptr);

signals:
    void buttonClicked(const QString &text); // 按键被点击时发出信号

private slots:
    void onButtonClicked();

private:
    QVBoxLayout *layout;
    // 泛型类型为指针；QVector 使用的是对象，而不是指针
    QVector<QPushButton *> buttons;

    void addButtons();
};

#endif // CALCULATOR_PANEL_H
