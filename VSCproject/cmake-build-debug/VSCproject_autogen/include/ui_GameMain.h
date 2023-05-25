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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMain
{
public:
    QPushButton *pause_button;
    QLabel *enemy_cnt_label;

    void setupUi(QWidget *GameMain)
    {
        if (GameMain->objectName().isEmpty())
            GameMain->setObjectName("GameMain");
        GameMain->resize(514, 286);
        pause_button = new QPushButton(GameMain);
        pause_button->setObjectName("pause_button");
        pause_button->setGeometry(QRect(10, 0, 100, 32));
        enemy_cnt_label = new QLabel(GameMain);
        enemy_cnt_label->setObjectName("enemy_cnt_label");
        enemy_cnt_label->setGeometry(QRect(20, 50, 151, 16));

        retranslateUi(GameMain);

        QMetaObject::connectSlotsByName(GameMain);
    } // setupUi

    void retranslateUi(QWidget *GameMain)
    {
        GameMain->setWindowTitle(QCoreApplication::translate("GameMain", "GameMain", nullptr));
        pause_button->setText(QCoreApplication::translate("GameMain", "PushButton", nullptr));
        enemy_cnt_label->setText(QCoreApplication::translate("GameMain", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMain: public Ui_GameMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMAIN_H
