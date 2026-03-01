#ifndef BUTTON_INFO_H
#define BUTTON_INFO_H

#include <QString>

class ButtonInfo
{
public:
    ButtonInfo(const QString &text,
               const int textColor,
               const int normalBgColor,
               const int pressedBgColor,
               const QString &icon = "")
        : mText(text), mIcon(icon), mTextColor(textColor), mNormalBgColor(normalBgColor), mPressedBgColor(pressedBgColor)
    {
    }

    QString mText;
    QString mIcon;
    int mTextColor;
    int mNormalBgColor;
    int mPressedBgColor;
};

#endif // BUTTON_INFO_H
