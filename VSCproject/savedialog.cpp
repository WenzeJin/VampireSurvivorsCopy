//
// Created by 金文泽 on 2023/6/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SaveDialog.h" resolved

#include "savedialog.h"
#include "ui_SaveDialog.h"
#include "GameLogic/config.h"
#include <fstream>
#include <iostream>
#include "menu.h"

SaveDialog::SaveDialog(Menu * m, QWidget *parent) :
        QDialog(parent), ui(new Ui::SaveDialog), m_p(m) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    ui->c_soul->setText(QString::number(SOUL));
    ui->c_level->setText(QString::number(LEVEL));
    ui->c_intelligence->setText(QString::number(INTELLIGENCE));
    ui->c_live->setText(QString::number(LIVE));
    ui->c_speed->setText(QString::number(SPEED));
    ui->c_power->setText(QString::number(POWER));
    ui->c_halt->setText(GAME_HALT ? "是" : "否");

    connect(ui->pushButton_2, &QPushButton::clicked, [&](){
        QString temp = ui->lineEdit->text();
        new_file(temp);
    });
    connect(ui->pushButton, &QPushButton::clicked, [&](){
        SOUL = ui->f_soul->text().toInt();
        LEVEL = ui->f_level->text().toInt();
        POWER = ui->f_power->text().toInt();
        SPEED = ui->f_speed->text().toInt();
        LIVE = ui->f_live->text().toInt();
        INTELLIGENCE = ui->f_intelligence->text().toInt();
        GAME_HALT = ui->f_halt->text() == "是";
        std::cout << GAME_HALT << std::endl;
        if(GAME_HALT){
            FIRST_RESUME = 1;
            HERO_TYPE = temp_halt.hero_type;
            HALT_HP = temp_halt.halt_hp;
            HALT_HPM = temp_halt.halt_hpm;
            GAME_LEVEL = temp_halt.game_level;
            HALT_EXP = temp_halt.halt_exp;
            HALT_EXPM = temp_halt.halt_expm;
            HERO_SPEED = temp_halt.hero_speed;
            HERO_REDUCE = temp_halt.hero_reduce;
            DAMAGE = temp_halt.d;
            HALT_CD = temp_halt.halt_cd;
            HERO_X = temp_halt.hero_x;
            HERO_Y = temp_halt.hero_y;
            m_p->disableResume();
        }

        ui->c_soul->setText(QString::number(SOUL));
        ui->c_level->setText(QString::number(LEVEL));
        ui->c_intelligence->setText(QString::number(INTELLIGENCE));
        ui->c_live->setText(QString::number(LIVE));
        ui->c_speed->setText(QString::number(SPEED));
        ui->c_power->setText(QString::number(POWER));
        ui->c_halt->setText(GAME_HALT ? "是" : "否");
    });
    connect(ui->pushButton_3, &QPushButton::clicked, [&](){
        if(!file_name.empty()){
            QString path = ui->comboBox->currentText();
            store(path);
        }
    });

    refresh_file_list();
    if(!file_name.empty())
        refresh_file_display();
}

SaveDialog::~SaveDialog() {
    this->hide();
    if(m_p){
        m_p->show();
    }
    delete ui;
}

void SaveDialog::refresh_file_list() {
    ui->comboBox->disconnect();
    ui->comboBox->clear();
    file_name.clear();
    std::ifstream saves_file("Saves/saves.txt", std::ios::in);
    saves_file >> file_cnt;
    while(!saves_file.fail()){
        std::string temp;
        saves_file >> temp;
        file_name.push_back(temp);
    }
    saves_file.close();

    for(auto &each: file_name){
        ui->comboBox->addItem(QString::fromStdString(each));
    }

    connect(ui->comboBox, &QComboBox::currentTextChanged, [&](){
        refresh_file_display();
    });
}

void SaveDialog::refresh_file_display() {
    int temp[7] = {};
    std::string f_name = ui->comboBox->currentText().toStdString();
    f_name = "Saves/" + f_name;
    std::ifstream f(f_name, std::ios::in);
    if(f.is_open()){
        for (auto &x: temp)
            f >> x;
    }
    ui->f_soul->setText(QString::number(temp[0]));
    ui->f_level->setText(QString::number(temp[1]));
    ui->f_power->setText(QString::number(temp[2]));
    ui->f_speed->setText(QString::number(temp[3]));
    ui->f_live->setText(QString::number(temp[4]));
    ui->f_intelligence->setText(QString::number(temp[5]));
    ui->f_halt->setText(temp[6] ? "是" : "否");

    f >> temp_halt.hero_type >> temp_halt.halt_hp >> temp_halt.halt_hpm >> temp_halt.game_level >> temp_halt.halt_exp >> temp_halt.halt_expm;
    f >> temp_halt.hero_speed >> temp_halt.hero_reduce >> temp_halt.d >> temp_halt.halt_cd >> temp_halt.hero_x >> temp_halt.hero_y;
    int test = 0;
}

void SaveDialog::new_file(QString &file) {
    if(!file_name.empty()){
        std::ofstream saves("Saves/saves.txt");
        saves << file_cnt + 1 << std::endl;
        for(auto & each: file_name){
            saves << each << std::endl;
        }
        bool flag = true;
        for(auto & each: file_name){
            if(each == file.toStdString()){
                flag = false;
            }
        }
        if(flag)
            saves << file.toStdString() << std::endl;
        saves.close();
        std::ofstream f("Saves/" + file.toStdString(), std::ios::out);
        f << "0 1 1 1 1 1" << std::endl;
        f << "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" << std::endl;
        f << "soul level power speed live intelligence \nline 2:game_halt_info" << std::endl;
        f.close();
        refresh_file_list();
        refresh_file_display();
    }
}

void SaveDialog::store(QString &file) {
    if(!file_name.empty()){
        std::ofstream f("Saves/" + file.toStdString(), std::ios::out);
        f << SOUL << " " << LEVEL << " " << POWER << " " << SPEED << " " << LIVE << " " << INTELLIGENCE << std::endl;
        f << GAME_HALT << " " << HERO_TYPE << " " << HALT_HP << " " << HALT_HPM << " " << GAME_LEVEL << " " << HALT_EXP << " " << HALT_EXPM << " " << HERO_SPEED << " " << HERO_REDUCE;
        f << " " << DAMAGE << " " << HALT_CD << " " << HERO_X << " " << HERO_Y << std::endl;
        f << "line 1: soul level power speed live intelligence \nline 2:game_halt_info" << std::endl;
        f.close();
        refresh_file_display();
    }
}
