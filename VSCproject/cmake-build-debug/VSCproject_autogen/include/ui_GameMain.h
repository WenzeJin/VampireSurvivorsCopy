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
    QLabel *level_label;
    QPushButton *back_button;
    QPushButton *end_button;

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
        enemy_cnt_label->setGeometry(QRect(20, 100, 221, 16));
        level_label = new QLabel(GameMain);
        level_label->setObjectName("level_label");
        level_label->setGeometry(QRect(20, 130, 221, 16));
        back_button = new QPushButton(GameMain);
        back_button->setObjectName("back_button");
        back_button->setGeometry(QRect(10, 30, 100, 32));
        end_button = new QPushButton(GameMain);
        end_button->setObjectName("end_button");
        end_button->setGeometry(QRect(10, 60, 100, 32));

        retranslateUi(GameMain);

        QMetaObject::connectSlotsByName(GameMain);
    } // setupUi

    void retranslateUi(QWidget *GameMain)
    {
        GameMain->setWindowTitle(QCoreApplication::translate("GameMain", "GameMain", nullptr));
        pause_button->setText(QCoreApplication::translate("GameMain", "PushButton", nullptr));
        enemy_cnt_label->setText(QCoreApplication::translate("GameMain", "TextLabel", nullptr));
        level_label->setText(QCoreApplication::translate("GameMain", "TextLabel", nullptr));
        back_button->setText(QCoreApplication::translate("GameMain", "\346\232\202\346\227\266\350\277\224\345\233\236", nullptr));
        end_button->setText(QCoreApplication::translate("GameMain", "\347\273\223\347\256\227\346\234\254\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMain: public Ui_GameMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMAIN_H
