/********************************************************************************
** Form generated from reading UI file 'SelectDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDIALOG_H
#define UI_SELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *SelectDialog)
    {
        if (SelectDialog->objectName().isEmpty())
            SelectDialog->setObjectName("SelectDialog");
        SelectDialog->resize(668, 634);
        pushButton = new QPushButton(SelectDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 10, 311, 611));
        pushButton_2 = new QPushButton(SelectDialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(340, 10, 311, 611));

        retranslateUi(SelectDialog);

        QMetaObject::connectSlotsByName(SelectDialog);
    } // setupUi

    void retranslateUi(QWidget *SelectDialog)
    {
        SelectDialog->setWindowTitle(QCoreApplication::translate("SelectDialog", "\350\257\267\351\200\211\346\213\251\350\247\222\350\211\262", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectDialog: public Ui_SelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDIALOG_H
