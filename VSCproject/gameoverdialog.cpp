//
// Created by 金文泽 on 2023/6/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameOverDialog.h" resolved

#include "gameoverdialog.h"
#include "ui_GameOverDialog.h"
#include "menu.h"

GameOverDialog::GameOverDialog(Menu * parent, int e_cnt, double h_percent, int s_cnt) :
        QDialog(nullptr), ui(new Ui::GameOverDialog), m(parent) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->enemy_cnt->setText("本次击杀敌人数量：" + QString::number(e_cnt));
    ui->hp_percent->setText("剩余血量百分比：" + QString::number((double)(int)(h_percent * 10000) / 100.0) + "%");
    int delta_soul = int(e_cnt * (h_percent * 0.5 + 0.5));
    SOUL += delta_soul;
    ui->soul_cnt->setText("本次结算魂：" + QString::number(delta_soul) + "(" + QString::number(SOUL) + ")");

    connect(ui->pushButton, &QPushButton::clicked, [&](){
        this->hide();
        if(m){
            m->show();
        }
    });
}

GameOverDialog::~GameOverDialog() {
    delete ui;
}
