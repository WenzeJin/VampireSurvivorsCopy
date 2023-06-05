/********************************************************************************
** Form generated from reading UI file 'UpgradeDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPGRADEDIALOG_H
#define UI_UPGRADEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UpgradeDialog
{
public:
    QPushButton *choice1;
    QPushButton *choice2;
    QPushButton *choice3;

    void setupUi(QDialog *UpgradeDialog)
    {
        if (UpgradeDialog->objectName().isEmpty())
            UpgradeDialog->setObjectName("UpgradeDialog");
        UpgradeDialog->resize(611, 378);
        choice1 = new QPushButton(UpgradeDialog);
        choice1->setObjectName("choice1");
        choice1->setGeometry(QRect(10, 10, 191, 361));
        choice1->setAutoDefault(false);
        choice1->setFlat(false);
        choice2 = new QPushButton(UpgradeDialog);
        choice2->setObjectName("choice2");
        choice2->setGeometry(QRect(210, 10, 191, 361));
        choice2->setAutoDefault(false);
        choice3 = new QPushButton(UpgradeDialog);
        choice3->setObjectName("choice3");
        choice3->setGeometry(QRect(410, 10, 191, 361));
        choice3->setAutoDefault(false);

        retranslateUi(UpgradeDialog);

        choice1->setDefault(false);


        QMetaObject::connectSlotsByName(UpgradeDialog);
    } // setupUi

    void retranslateUi(QDialog *UpgradeDialog)
    {
        UpgradeDialog->setWindowTitle(QCoreApplication::translate("UpgradeDialog", "\345\215\207\347\272\247\357\274\201", nullptr));
        choice1->setText(QString());
        choice2->setText(QString());
        choice3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UpgradeDialog: public Ui_UpgradeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPGRADEDIALOG_H
