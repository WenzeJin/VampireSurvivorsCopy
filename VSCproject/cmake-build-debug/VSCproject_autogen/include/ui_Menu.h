/********************************************************************************
** Form generated from reading UI file 'Menu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *background;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(659, 449);
        pushButton = new QPushButton(Menu);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 340, 171, 32));
        pushButton_2 = new QPushButton(Menu);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 310, 171, 32));
        pushButton_3 = new QPushButton(Menu);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(250, 370, 171, 32));
        pushButton_4 = new QPushButton(Menu);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(250, 400, 171, 32));
        background = new QLabel(Menu);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 661, 451));
        background->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        pushButton->setText(QCoreApplication::translate("Menu", "\345\274\200\345\247\213\346\226\260\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Menu", "\347\273\247\347\273\255\346\270\270\346\210\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Menu", "\345\255\230\346\241\243\347\256\241\347\220\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Menu", "\345\225\206\345\272\227", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
