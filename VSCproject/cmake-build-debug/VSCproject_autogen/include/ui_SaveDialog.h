/********************************************************************************
** Form generated from reading UI file 'SaveDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDIALOG_H
#define UI_SAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveDialog
{
public:
    QComboBox *comboBox;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *f_soul;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *f_level;
    QLabel *f_power;
    QLabel *f_speed;
    QLabel *f_live;
    QLabel *f_intelligence;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *c_soul;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *c_level;
    QLabel *c_power;
    QLabel *c_speed;
    QLabel *c_live;
    QLabel *c_intelligence;

    void setupUi(QDialog *SaveDialog)
    {
        if (SaveDialog->objectName().isEmpty())
            SaveDialog->setObjectName("SaveDialog");
        SaveDialog->resize(479, 320);
        comboBox = new QComboBox(SaveDialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 10, 451, 32));
        pushButton = new QPushButton(SaveDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 170, 100, 32));
        gridLayoutWidget = new QWidget(SaveDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 80, 441, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 4, 1, 1);

        f_soul = new QLabel(gridLayoutWidget);
        f_soul->setObjectName("f_soul");

        gridLayout->addWidget(f_soul, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 5, 1, 1);

        f_level = new QLabel(gridLayoutWidget);
        f_level->setObjectName("f_level");

        gridLayout->addWidget(f_level, 1, 1, 1, 1);

        f_power = new QLabel(gridLayoutWidget);
        f_power->setObjectName("f_power");

        gridLayout->addWidget(f_power, 1, 2, 1, 1);

        f_speed = new QLabel(gridLayoutWidget);
        f_speed->setObjectName("f_speed");

        gridLayout->addWidget(f_speed, 1, 3, 1, 1);

        f_live = new QLabel(gridLayoutWidget);
        f_live->setObjectName("f_live");

        gridLayout->addWidget(f_live, 1, 4, 1, 1);

        f_intelligence = new QLabel(gridLayoutWidget);
        f_intelligence->setObjectName("f_intelligence");

        gridLayout->addWidget(f_intelligence, 1, 5, 1, 1);

        lineEdit = new QLineEdit(SaveDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 40, 321, 31));
        pushButton_2 = new QPushButton(SaveDialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 40, 100, 32));
        pushButton_3 = new QPushButton(SaveDialog);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 170, 100, 32));
        gridLayoutWidget_2 = new QWidget(SaveDialog);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 220, 441, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 0, 4, 1, 1);

        c_soul = new QLabel(gridLayoutWidget_2);
        c_soul->setObjectName("c_soul");

        gridLayout_2->addWidget(c_soul, 1, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 0, 3, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 0, 5, 1, 1);

        c_level = new QLabel(gridLayoutWidget_2);
        c_level->setObjectName("c_level");

        gridLayout_2->addWidget(c_level, 1, 1, 1, 1);

        c_power = new QLabel(gridLayoutWidget_2);
        c_power->setObjectName("c_power");

        gridLayout_2->addWidget(c_power, 1, 2, 1, 1);

        c_speed = new QLabel(gridLayoutWidget_2);
        c_speed->setObjectName("c_speed");

        gridLayout_2->addWidget(c_speed, 1, 3, 1, 1);

        c_live = new QLabel(gridLayoutWidget_2);
        c_live->setObjectName("c_live");

        gridLayout_2->addWidget(c_live, 1, 4, 1, 1);

        c_intelligence = new QLabel(gridLayoutWidget_2);
        c_intelligence->setObjectName("c_intelligence");

        gridLayout_2->addWidget(c_intelligence, 1, 5, 1, 1);


        retranslateUi(SaveDialog);

        QMetaObject::connectSlotsByName(SaveDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveDialog)
    {
        SaveDialog->setWindowTitle(QCoreApplication::translate("SaveDialog", "SaveDialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SaveDialog", "\350\257\273\345\217\226\345\255\230\346\241\243", nullptr));
        label->setText(QCoreApplication::translate("SaveDialog", "\351\255\202", nullptr));
        label_4->setText(QCoreApplication::translate("SaveDialog", "\345\212\233\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("SaveDialog", "\347\255\211\347\272\247", nullptr));
        label_6->setText(QCoreApplication::translate("SaveDialog", "\347\224\237\345\221\275\345\212\233", nullptr));
        f_soul->setText(QString());
        label_5->setText(QCoreApplication::translate("SaveDialog", "\351\200\237\345\272\246", nullptr));
        label_7->setText(QCoreApplication::translate("SaveDialog", "\346\231\272\345\212\233", nullptr));
        f_level->setText(QString());
        f_power->setText(QString());
        f_speed->setText(QString());
        f_live->setText(QString());
        f_intelligence->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("SaveDialog", "\346\226\260\345\273\272\345\255\230\346\241\243\346\226\207\344\273\266", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SaveDialog", "\345\206\231\345\205\245\345\255\230\346\241\243", nullptr));
        label_3->setText(QCoreApplication::translate("SaveDialog", "\351\255\202", nullptr));
        label_8->setText(QCoreApplication::translate("SaveDialog", "\345\212\233\351\207\217", nullptr));
        label_9->setText(QCoreApplication::translate("SaveDialog", "\347\255\211\347\272\247", nullptr));
        label_10->setText(QCoreApplication::translate("SaveDialog", "\347\224\237\345\221\275\345\212\233", nullptr));
        c_soul->setText(QString());
        label_11->setText(QCoreApplication::translate("SaveDialog", "\351\200\237\345\272\246", nullptr));
        label_12->setText(QCoreApplication::translate("SaveDialog", "\346\231\272\345\212\233", nullptr));
        c_level->setText(QString());
        c_power->setText(QString());
        c_speed->setText(QString());
        c_live->setText(QString());
        c_intelligence->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SaveDialog: public Ui_SaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDIALOG_H
