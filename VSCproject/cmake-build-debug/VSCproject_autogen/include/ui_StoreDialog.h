/********************************************************************************
** Form generated from reading UI file 'StoreDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREDIALOG_H
#define UI_STOREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreDialog
{
public:
    QLabel *soul_label;
    QLabel *level_label;
    QLabel *budget_label;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *box_power;
    QSpinBox *box_speed;
    QSpinBox *box_live;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *health10;
    QLabel *health11;
    QLabel *speed10;
    QLabel *speed11;
    QLabel *damage10;
    QLabel *damage11;
    QLabel *cd10;
    QLabel *cd11;
    QLabel *reduce10;
    QLabel *reduce11;
    QLabel *inc10;
    QLabel *inc11;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *health20;
    QLabel *health21;
    QLabel *speed20;
    QLabel *speed21;
    QLabel *damage20;
    QLabel *damage21;
    QLabel *cd20;
    QLabel *cd21;
    QLabel *reduce20;
    QLabel *reduce21;
    QLabel *inc20;
    QLabel *inc21;
    QPushButton *pushButton;
    QLabel *label_22;
    QSpinBox *box_intelligence;

    void setupUi(QDialog *StoreDialog)
    {
        if (StoreDialog->objectName().isEmpty())
            StoreDialog->setObjectName("StoreDialog");
        StoreDialog->resize(662, 453);
        soul_label = new QLabel(StoreDialog);
        soul_label->setObjectName("soul_label");
        soul_label->setGeometry(QRect(30, 40, 221, 21));
        level_label = new QLabel(StoreDialog);
        level_label->setObjectName("level_label");
        level_label->setGeometry(QRect(30, 70, 211, 16));
        budget_label = new QLabel(StoreDialog);
        budget_label->setObjectName("budget_label");
        budget_label->setGeometry(QRect(30, 100, 211, 16));
        label = new QLabel(StoreDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 190, 41, 16));
        label_2 = new QLabel(StoreDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 220, 51, 16));
        label_3 = new QLabel(StoreDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 250, 51, 16));
        box_power = new QSpinBox(StoreDialog);
        box_power->setObjectName("box_power");
        box_power->setGeometry(QRect(80, 190, 42, 22));
        box_speed = new QSpinBox(StoreDialog);
        box_speed->setObjectName("box_speed");
        box_speed->setGeometry(QRect(80, 220, 42, 22));
        box_live = new QSpinBox(StoreDialog);
        box_live->setObjectName("box_live");
        box_live->setGeometry(QRect(80, 250, 42, 22));
        gridLayoutWidget = new QWidget(StoreDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(330, 10, 311, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 4, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 6, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 5, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName("label_12");

        gridLayout->addWidget(label_12, 7, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        health10 = new QLabel(gridLayoutWidget);
        health10->setObjectName("health10");

        gridLayout->addWidget(health10, 2, 2, 1, 1);

        health11 = new QLabel(gridLayoutWidget);
        health11->setObjectName("health11");

        gridLayout->addWidget(health11, 2, 3, 1, 1);

        speed10 = new QLabel(gridLayoutWidget);
        speed10->setObjectName("speed10");

        gridLayout->addWidget(speed10, 3, 2, 1, 1);

        speed11 = new QLabel(gridLayoutWidget);
        speed11->setObjectName("speed11");

        gridLayout->addWidget(speed11, 3, 3, 1, 1);

        damage10 = new QLabel(gridLayoutWidget);
        damage10->setObjectName("damage10");

        gridLayout->addWidget(damage10, 4, 2, 1, 1);

        damage11 = new QLabel(gridLayoutWidget);
        damage11->setObjectName("damage11");

        gridLayout->addWidget(damage11, 4, 3, 1, 1);

        cd10 = new QLabel(gridLayoutWidget);
        cd10->setObjectName("cd10");

        gridLayout->addWidget(cd10, 5, 2, 1, 1);

        cd11 = new QLabel(gridLayoutWidget);
        cd11->setObjectName("cd11");

        gridLayout->addWidget(cd11, 5, 3, 1, 1);

        reduce10 = new QLabel(gridLayoutWidget);
        reduce10->setObjectName("reduce10");

        gridLayout->addWidget(reduce10, 6, 2, 1, 1);

        reduce11 = new QLabel(gridLayoutWidget);
        reduce11->setObjectName("reduce11");

        gridLayout->addWidget(reduce11, 6, 3, 1, 1);

        inc10 = new QLabel(gridLayoutWidget);
        inc10->setObjectName("inc10");

        gridLayout->addWidget(inc10, 7, 2, 1, 1);

        inc11 = new QLabel(gridLayoutWidget);
        inc11->setObjectName("inc11");

        gridLayout->addWidget(inc11, 7, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(StoreDialog);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(330, 230, 311, 201));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 3, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_2);
        label_14->setObjectName("label_14");

        gridLayout_2->addWidget(label_14, 0, 3, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName("label_15");

        gridLayout_2->addWidget(label_15, 4, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName("label_16");

        gridLayout_2->addWidget(label_16, 0, 2, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_2);
        label_17->setObjectName("label_17");

        gridLayout_2->addWidget(label_17, 6, 1, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_2);
        label_18->setObjectName("label_18");

        gridLayout_2->addWidget(label_18, 5, 1, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_2);
        label_19->setObjectName("label_19");

        gridLayout_2->addWidget(label_19, 7, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_2);
        label_20->setObjectName("label_20");

        gridLayout_2->addWidget(label_20, 2, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName("label_21");

        gridLayout_2->addWidget(label_21, 0, 1, 1, 1);

        health20 = new QLabel(gridLayoutWidget_2);
        health20->setObjectName("health20");

        gridLayout_2->addWidget(health20, 2, 2, 1, 1);

        health21 = new QLabel(gridLayoutWidget_2);
        health21->setObjectName("health21");

        gridLayout_2->addWidget(health21, 2, 3, 1, 1);

        speed20 = new QLabel(gridLayoutWidget_2);
        speed20->setObjectName("speed20");

        gridLayout_2->addWidget(speed20, 3, 2, 1, 1);

        speed21 = new QLabel(gridLayoutWidget_2);
        speed21->setObjectName("speed21");

        gridLayout_2->addWidget(speed21, 3, 3, 1, 1);

        damage20 = new QLabel(gridLayoutWidget_2);
        damage20->setObjectName("damage20");

        gridLayout_2->addWidget(damage20, 4, 2, 1, 1);

        damage21 = new QLabel(gridLayoutWidget_2);
        damage21->setObjectName("damage21");

        gridLayout_2->addWidget(damage21, 4, 3, 1, 1);

        cd20 = new QLabel(gridLayoutWidget_2);
        cd20->setObjectName("cd20");

        gridLayout_2->addWidget(cd20, 5, 2, 1, 1);

        cd21 = new QLabel(gridLayoutWidget_2);
        cd21->setObjectName("cd21");

        gridLayout_2->addWidget(cd21, 5, 3, 1, 1);

        reduce20 = new QLabel(gridLayoutWidget_2);
        reduce20->setObjectName("reduce20");

        gridLayout_2->addWidget(reduce20, 6, 2, 1, 1);

        reduce21 = new QLabel(gridLayoutWidget_2);
        reduce21->setObjectName("reduce21");

        gridLayout_2->addWidget(reduce21, 6, 3, 1, 1);

        inc20 = new QLabel(gridLayoutWidget_2);
        inc20->setObjectName("inc20");

        gridLayout_2->addWidget(inc20, 7, 2, 1, 1);

        inc21 = new QLabel(gridLayoutWidget_2);
        inc21->setObjectName("inc21");

        gridLayout_2->addWidget(inc21, 7, 3, 1, 1);

        pushButton = new QPushButton(StoreDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 340, 100, 32));
        label_22 = new QLabel(StoreDialog);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(30, 280, 51, 16));
        box_intelligence = new QSpinBox(StoreDialog);
        box_intelligence->setObjectName("box_intelligence");
        box_intelligence->setGeometry(QRect(80, 280, 42, 22));

        retranslateUi(StoreDialog);

        QMetaObject::connectSlotsByName(StoreDialog);
    } // setupUi

    void retranslateUi(QDialog *StoreDialog)
    {
        StoreDialog->setWindowTitle(QCoreApplication::translate("StoreDialog", "\345\225\206\345\272\227", nullptr));
        soul_label->setText(QCoreApplication::translate("StoreDialog", "\346\213\245\346\234\211\347\232\204\351\255\202\357\274\232", nullptr));
        level_label->setText(QCoreApplication::translate("StoreDialog", "\345\205\250\345\261\200\347\255\211\347\272\247\357\274\232", nullptr));
        budget_label->setText(QCoreApplication::translate("StoreDialog", "\345\215\207\347\272\247\346\211\200\351\234\200\351\255\202\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("StoreDialog", "\345\212\233\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("StoreDialog", "\346\225\217\346\215\267", nullptr));
        label_3->setText(QCoreApplication::translate("StoreDialog", "\347\224\237\345\221\275\345\212\233", nullptr));
        label_8->setText(QCoreApplication::translate("StoreDialog", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("StoreDialog", "\345\215\207\347\272\247\345\220\216\345\261\236\346\200\247\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("StoreDialog", "\346\255\246\345\231\250\344\274\244\345\256\263\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("StoreDialog", "\345\275\223\345\211\215\345\261\236\346\200\247\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("StoreDialog", "\344\274\244\345\256\263\346\212\227\346\200\247\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("StoreDialog", "\344\274\244\345\256\263CD\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("StoreDialog", "\345\215\207\347\272\247\346\217\220\345\215\207\346\257\224\344\276\213\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("StoreDialog", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("StoreDialog", "\345\215\240\346\230\237\345\270\210\345\261\236\346\200\247\357\274\232", nullptr));
        health10->setText(QString());
        health11->setText(QString());
        speed10->setText(QString());
        speed11->setText(QString());
        damage10->setText(QString());
        damage11->setText(QString());
        cd10->setText(QString());
        cd11->setText(QString());
        reduce10->setText(QString());
        reduce11->setText(QString());
        inc10->setText(QString());
        inc11->setText(QString());
        label_13->setText(QCoreApplication::translate("StoreDialog", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("StoreDialog", "\345\215\207\347\272\247\345\220\216\345\261\236\346\200\247\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("StoreDialog", "\346\255\246\345\231\250\344\274\244\345\256\263\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("StoreDialog", "\345\275\223\345\211\215\345\261\236\346\200\247\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("StoreDialog", "\344\274\244\345\256\263\346\212\227\346\200\247\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("StoreDialog", "\346\255\246\345\231\250CD\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("StoreDialog", "\345\215\207\347\272\247\346\217\220\345\215\207\346\257\224\344\276\213\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("StoreDialog", "\347\224\237\345\221\275\345\200\274\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("StoreDialog", "\351\242\204\350\250\200\345\256\266\345\261\236\346\200\247\357\274\232", nullptr));
        health20->setText(QString());
        health21->setText(QString());
        speed20->setText(QString());
        speed21->setText(QString());
        damage20->setText(QString());
        damage21->setText(QString());
        cd20->setText(QString());
        cd21->setText(QString());
        reduce20->setText(QString());
        reduce21->setText(QString());
        inc20->setText(QString());
        inc21->setText(QString());
        pushButton->setText(QCoreApplication::translate("StoreDialog", "\345\272\224\347\224\250\345\215\207\347\272\247", nullptr));
        label_22->setText(QCoreApplication::translate("StoreDialog", "\346\231\272\345\212\233", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreDialog: public Ui_StoreDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREDIALOG_H
