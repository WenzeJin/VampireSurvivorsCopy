//
// Created by 金文泽 on 2023/6/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StoreDialog.h" resolved

#include "storedialog.h"
#include "ui_StoreDialog.h"
#include "GameLogic/config.h"


StoreDialog::StoreDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::StoreDialog) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    ui->level_label->setText("当前等级：" + QString::number(LEVEL));
    next_level = LEVEL + 1;
    temp_level = LEVEL;
    temp_soul = SOUL;
    ui->soul_label->setText("拥有的魂：" + QString::number(SOUL));
    ui->budget_label->setText("下一级所需的魂：" + QString::number(calculate_soul(next_level) - calculate_soul(LEVEL)));
    next_available = hasNext();
    ui->box_intelligence->setMinimum(INTELLIGENCE);
    ui->box_power->setMinimum(POWER);
    ui->box_live->setMinimum(LIVE);
    ui->box_speed->setMinimum(SPEED);
    temp_intelligence = INTELLIGENCE;
    temp_live = LIVE;
    temp_power = POWER;
    temp_speed = SPEED;
    if(next_available){
        ui->box_intelligence->setMaximum(temp_intelligence + 1);
        ui->box_power->setMaximum(temp_power + 1);
        ui->box_live->setMaximum(temp_live + 1);
        ui->box_speed->setMaximum(temp_speed + 1);
        ui->budget_label->setStyleSheet("color:green;");
    } else {
        ui->box_intelligence->setMaximum(temp_intelligence);
        ui->box_power->setMaximum(temp_power);
        ui->box_live->setMaximum(temp_live);
        ui->box_speed->setMaximum(temp_speed);
        ui->budget_label->setStyleSheet("color:red;");
    }
    refresh_table();

    connect(ui->box_intelligence, &QSpinBox::valueChanged, [&](){
        refresh_next_level();
        refresh_table();
    });
    connect(ui->box_power, &QSpinBox::valueChanged, [&](){
        refresh_next_level();
        refresh_table();
    });
    connect(ui->box_live, &QSpinBox::valueChanged, [&](){
        refresh_next_level();
        refresh_table();
    });
    connect(ui->box_speed, &QSpinBox::valueChanged, [&](){
        refresh_next_level();
        refresh_table();
    });
    connect(ui->pushButton, &QPushButton::clicked, [&](){
        apply();
    });
}

StoreDialog::~StoreDialog() {
    this->hide();
    parentWidget()->show();
    delete ui;
}

int StoreDialog::calculate_soul(int lv) {
    lv += 12;
    return (int)(0.0200002737 * lv * lv * lv + 3.1199 * lv * lv + 111.79 * lv - 787);
}

bool StoreDialog::hasNext() const {
    return temp_soul > calculate_soul(LEVEL + 1) - calculate_soul(LEVEL);
}

void StoreDialog::refresh_table() {
    ui->health10->setText(QString::number(HERO_1_HEALTH));
    ui->health20->setText(QString::number(HERO_2_HEALTH));
    ui->speed10->setText(QString::number(HERO_1_SPEED));
    ui->speed20->setText(QString::number(HERO_2_SPEED));
    ui->damage10->setText(QString::number(WEAPON_1_DAMAGE));
    ui->damage20->setText(QString::number(WEAPON_2_DAMAGE));
    ui->cd10->setText(QString::number(AOE_BULLET_1_CD));
    ui->cd20->setText(QString::number(WEAPON_2_CD));
    ui->reduce10->setText(QString::number(HERO_1_REDUCE));
    ui->reduce20->setText(QString::number(HERO_2_REDUCE));
    ui->inc10->setText(QString::number(INC_RATE));
    ui->inc20->setText(QString::number(INC_RATE));

    int t1 = INTELLIGENCE, t2 = POWER, t3 = SPEED, t4 = LIVE;
    INTELLIGENCE = temp_intelligence; POWER = temp_power; SPEED = temp_speed; LIVE = temp_live;

    ui->health11->setText(QString::number(HERO_1_HEALTH));
    ui->health21->setText(QString::number(HERO_2_HEALTH));
    ui->speed11->setText(QString::number(HERO_1_SPEED));
    ui->speed21->setText(QString::number(HERO_2_SPEED));
    ui->damage11->setText(QString::number(WEAPON_1_DAMAGE));
    ui->damage21->setText(QString::number(WEAPON_2_DAMAGE));
    ui->cd11->setText(QString::number(AOE_BULLET_1_CD));
    ui->cd21->setText(QString::number(WEAPON_2_CD));
    ui->reduce11->setText(QString::number(HERO_1_REDUCE));
    ui->reduce21->setText(QString::number(HERO_2_REDUCE));
    ui->inc11->setText(QString::number(INC_RATE));
    ui->inc21->setText(QString::number(INC_RATE));

    if(ui->health11->text().toInt() > ui->health10->text().toInt()){
        ui->health11->setStyleSheet("color:green;");
    } else {
        ui->health11->setStyleSheet("color:black;");
    }
    if(ui->health21->text().toInt() > ui->health20->text().toInt()){
        ui->health21->setStyleSheet("color:green;");
    } else {
        ui->health21->setStyleSheet("color:black;");
    }
    if(ui->speed11->text().toInt() > ui->speed10->text().toInt()){
        ui->speed11->setStyleSheet("color:green;");
    } else {
        ui->speed11->setStyleSheet("color:black;");
    }
    if(ui->speed21->text().toInt() > ui->speed20->text().toInt()){
        ui->speed21->setStyleSheet("color:green;");
    } else {
        ui->speed21->setStyleSheet("color:black;");
    }
    if(ui->damage11->text().toInt() > ui->damage10->text().toInt()){
        ui->damage11->setStyleSheet("color:green;");
    } else {
        ui->damage11->setStyleSheet("color:black;");
    }
    if(ui->damage21->text().toInt() > ui->damage20->text().toInt()){
        ui->damage21->setStyleSheet("color:green;");
    } else {
        ui->damage21->setStyleSheet("color:black;");
    }
    if(ui->cd11->text().toInt() < ui->cd10->text().toInt()){
        ui->cd11->setStyleSheet("color:green;");
    } else {
        ui->cd11->setStyleSheet("color:black;");
    }
    if(ui->cd21->text().toInt() < ui->cd20->text().toInt()){
        ui->cd21->setStyleSheet("color:green;");
    } else {
        ui->cd21->setStyleSheet("color:black;");
    }
    if(ui->reduce11->text().toDouble() > ui->reduce10->text().toDouble()){
        ui->reduce11->setStyleSheet("color:green;");
    } else {
        ui->reduce11->setStyleSheet("color:black;");
    }
    if(ui->reduce21->text().toDouble() > ui->reduce20->text().toDouble()){
        ui->reduce21->setStyleSheet("color:green;");
    } else {
        ui->reduce21->setStyleSheet("color:black;");
    }
    if(ui->inc11->text().toDouble() > ui->inc10->text().toDouble()){
        ui->inc11->setStyleSheet("color:green;");
    } else {
        ui->inc11->setStyleSheet("color:black;");
    }
    if(ui->inc21->text().toDouble() > ui->inc20->text().toDouble()){
        ui->inc21->setStyleSheet("color:green;");
    } else {
        ui->inc21->setStyleSheet("color:black;");
    }

    INTELLIGENCE = t1; POWER = t2; SPEED = t3; LIVE = t4;
}

void StoreDialog::refresh_next_level() {
    temp_speed = ui->box_speed->value();
    temp_live = ui->box_live->value();
    temp_intelligence = ui->box_intelligence->value();
    temp_power = ui->box_power->value();
    temp_level = temp_power - POWER + temp_intelligence - INTELLIGENCE + temp_speed - SPEED + temp_live - LIVE + LEVEL;
    next_level = temp_level + 1;
    temp_soul = SOUL - (calculate_soul(temp_level) - calculate_soul(LEVEL));
    ui->level_label->setText("当前等级：" + QString::number(temp_level));
    ui->soul_label->setText("拥有的魂：" + QString::number(temp_soul));
    ui->budget_label->setText("下一级所需的魂：" + QString::number(calculate_soul(next_level) - calculate_soul(temp_level)));
    next_available = hasNext();
    if(next_available){
        ui->box_intelligence->setMaximum(temp_intelligence + 1);
        ui->box_power->setMaximum(temp_power + 1);
        ui->box_live->setMaximum(temp_live + 1);
        ui->box_speed->setMaximum(temp_speed + 1);
        ui->budget_label->setStyleSheet("color:green;");
    } else {
        ui->box_intelligence->setMaximum(temp_intelligence);
        ui->box_power->setMaximum(temp_power);
        ui->box_live->setMaximum(temp_live);
        ui->box_speed->setMaximum(temp_speed);
        ui->budget_label->setStyleSheet("color:red;");
    }
}

void StoreDialog::apply() {
    POWER = temp_power;
    SPEED = temp_speed;
    LIVE = temp_live;
    INTELLIGENCE = temp_intelligence;
    SOUL = temp_soul;
    next_available = hasNext();
    ui->box_intelligence->setMinimum(INTELLIGENCE);
    ui->box_power->setMinimum(POWER);
    ui->box_live->setMinimum(LIVE);
    ui->box_speed->setMinimum(SPEED);
    LEVEL = temp_level;
    next_level = temp_level + 1;
    refresh_next_level();
    refresh_table();
}
