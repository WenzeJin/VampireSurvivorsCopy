/********************************************************************************
** Form generated from reading UI file 'GameMain.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMAIN_H
#define UI_GAMEMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMain
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *GameMain)
    {
        if (GameMain->objectName().isEmpty())
            GameMain->setObjectName("GameMain");
        GameMain->resize(514, 286);
        pushButton = new QPushButton(GameMain);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 0, 100, 32));

        retranslateUi(GameMain);

        QMetaObject::connectSlotsByName(GameMain);
    } // setupUi

    void retranslateUi(QWidget *GameMain)
    {
        GameMain->setWindowTitle(QCoreApplication::translate("GameMain", "GameMain", nullptr));
        pushButton->setText(QCoreApplication::translate("GameMain", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMain: public Ui_GameMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMAIN_H
