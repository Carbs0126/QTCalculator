#include "../headers/main_window.h"
#include "../headers/calculator_panel.h"
#include "../headers/button_info.h"
#include "../headers/tinyexpr.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <cstring>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->mCentralWidget = new QWidget(this);
    this->mMainLayout = new QVBoxLayout();

    this->mScreenPanel = new ScreenPanel(this);
    this->mCalculatorPanel = new CalculatorPanel(this);

    connect(this->mCalculatorPanel, &CalculatorPanel::buttonClicked,
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

    this->mMainLayout->addWidget(this->mScreenPanel);
    this->mMainLayout->addWidget(this->mCalculatorPanel);

    this->mCentralWidget->setLayout(this->mMainLayout);

    setCentralWidget(this->mCentralWidget);

    this->mCentralWidget->setStyleSheet("background-color: #F7F7F7;");
    this->mScreenPanel->setStyleSheet("background-color: #6600FF00;");
    this->mCalculatorPanel->setStyleSheet("background-color: #66FF0000;");

    setFixedSize(sizeHint());
    // resize(sizeHint());
}

void MainWindow::appendInfo(const QString &text)
{
    this->mCurrentExpression.append(text);
}

void MainWindow::calculate()
{
    // this->label->setText("计算表达式 :" + this->mCurrentExpression);

    // QString exprStr = "sin(3.14/2)+2^3";
    // QByteArray byteArr = exprStr.toUtf8();
    // const char* cExpr = byteArr.constData();

    // qDebug() << "表达式内容长度：" << strlen(cExpr);
    // qDebug() << "表达式内容：" << cExpr;
    // qDebug("C 风格输出表达式：%s", cExpr);


    QByteArray exprByteArr = this->mCurrentExpression.toUtf8();
    const char *exprCharArr = exprByteArr.constData();

    // 使用TinyExpr解析并计算表达式


    qDebug()<< "this->mCurrentExpression: " << this->mCurrentExpression;

    qDebug()<< "expr: " << exprCharArr;

    int errorCode = 0;
    te_expr *parsedExpr = te_compile(exprCharArr, nullptr, 0, &errorCode);

    // 检查解析错误
    if (!parsedExpr) {
        QString errorMsg = QString("表达式解析错误！错误位置：%1，错误码：%2")
                               .arg(errorCode)
                               .arg(errorCode);
        QMessageBox::critical(this, "错误", errorMsg);
        // qDebug() << ;
        return;
    }

    // 计算结果
    double result = te_eval(parsedExpr);

    // 释放解析后的表达式资源（必须释放，避免内存泄漏）
    te_free(parsedExpr);

    QString resultQStr = QString::number(result);

    // 显示结果
    // this->label->setText("计算表达式 :" + this->mCurrentExpression + " = " + resultQStr);

    qDebug() << this->mCurrentExpression + " = " + resultQStr;







    this->mCurrentExpression = "";




}
