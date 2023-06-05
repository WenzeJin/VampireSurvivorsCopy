/********************************************************************************
** Form generated from reading UI file 'GameOverDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERDIALOG_H
#define UI_GAMEOVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameOverDialog
{
public:
    QLabel *enemy_cnt;
    QLabel *hp_percent;
    QLabel *soul_cnt;
    QPushButton *pushButton;

    void setupUi(QDialog *GameOverDialog)
    {
        if (GameOverDialog->objectName().isEmpty())
            GameOverDialog->setObjectName("GameOverDialog");
        GameOverDialog->resize(400, 300);
        enemy_cnt = new QLabel(GameOverDialog);
        enemy_cnt->setObjectName("enemy_cnt");
        enemy_cnt->setGeometry(QRect(40, 30, 251, 16));
        hp_percent = new QLabel(GameOverDialog);
        hp_percent->setObjectName("hp_percent");
        hp_percent->setGeometry(QRect(40, 70, 251, 16));
        soul_cnt = new QLabel(GameOverDialog);
        soul_cnt->setObjectName("soul_cnt");
        soul_cnt->setGeometry(QRect(40, 110, 291, 16));
        pushButton = new QPushButton(GameOverDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 200, 100, 32));

        retranslateUi(GameOverDialog);

        QMetaObject::connectSlotsByName(GameOverDialog);
    } // setupUi

    void retranslateUi(QDialog *GameOverDialog)
    {
        GameOverDialog->setWindowTitle(QCoreApplication::translate("GameOverDialog", "\346\270\270\346\210\217\347\273\223\347\256\227", nullptr));
        enemy_cnt->setText(QCoreApplication::translate("GameOverDialog", "\346\234\254\346\254\241\345\207\273\346\235\200\346\225\214\344\272\272\346\225\260\351\207\217\357\274\232", nullptr));
        hp_percent->setText(QCoreApplication::translate("GameOverDialog", "\345\211\251\344\275\231\347\224\237\345\221\275\345\200\274\347\231\276\345\210\206\346\257\224\357\274\232", nullptr));
        soul_cnt->setText(QCoreApplication::translate("GameOverDialog", "\347\273\223\347\256\227\350\216\267\345\276\227\351\255\202\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("GameOverDialog", "\345\233\236\345\210\260\344\270\273\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverDialog: public Ui_GameOverDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERDIALOG_H
