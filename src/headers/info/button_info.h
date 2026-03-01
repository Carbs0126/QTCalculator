#ifndef BUTTON_INFO_H
#define BUTTON_INFO_H

#include <QString>

class ButtonInfo
{
public:
    ButtonInfo(const QString &text,
               const QString &info,
               const int textColor,
               const int normalBgColor,
               const int pressedBgColor,
               const QString &icon = "")
        : mText(text), mInfo(info), mTextColor(textColor), mNormalBgColor(normalBgColor), mPressedBgColor(pressedBgColor), mIcon(icon)
    {
    }

    QString mText;
    QString mInfo;
    QString mIcon;
    int mTextColor;
    int mNormalBgColor;
    int mPressedBgColor;

    static const QString INFO_DIGIT_0;
    static const QString INFO_DIGIT_1;
    static const QString INFO_DIGIT_2;
    static const QString INFO_DIGIT_3;
    static const QString INFO_DIGIT_4;
    static const QString INFO_DIGIT_5;
    static const QString INFO_DIGIT_6;
    static const QString INFO_DIGIT_7;
    static const QString INFO_DIGIT_8;
    static const QString INFO_DIGIT_9;
    static const QString INFO_DIGIT_POINT;
    static const QString INFO_OPERATOR_ADD;
    static const QString INFO_OPERATOR_MINUS;
    static const QString INFO_OPERATOR_MULTIPLE;
    static const QString INFO_OPERATOR_DIVIDE;
    static const QString INFO_OPERATOR_EQUAL;
    static const QString INFO_OPERATOR_PERCENT;
    static const QString INFO_CMD_CLEAR;
    static const QString INFO_CMD_DELETE;

};

#endif // BUTTON_INFO_H
