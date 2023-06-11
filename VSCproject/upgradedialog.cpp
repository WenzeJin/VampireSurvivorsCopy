//
// Created by 金文泽 on 2023/6/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UpgradeDialog.h" resolved

#include "upgradedialog.h"
#include "ui_UpgradeDialog.h"
#include "gamemain.h"

UpgradeDialog::UpgradeDialog(GameMain * game_widget, QWidget *parent) :
        QDialog(parent), ui(new Ui::UpgradeDialog), parent(game_widget) {
    ui->setupUi(this);

    connect(ui->choice1, &QPushButton::clicked, [&](){ choose1();});
    connect(ui->choice2, &QPushButton::clicked, [&](){ choose2();});
    connect(ui->choice3, &QPushButton::clicked, [&](){ choose3();});

    ui->choice1->setIcon(QIcon(QPixmap(":/image/Assets/bt5.PNG").scaled(191,361)));
    ui->choice1->setIconSize(QSize(191,361));
    ui->choice2->setIcon(QIcon(QPixmap(":/image/Assets/bt4.PNG").scaled(191,361)));
    ui->choice2->setIconSize(QSize(191,361));
    ui->choice3->setIcon(QIcon(QPixmap(":/image/Assets/bt3.PNG").scaled(191,361)));
    ui->choice3->setIconSize(QSize(191,361));

}

UpgradeDialog::~UpgradeDialog() {
    delete ui;
}

void UpgradeDialog::choose1() {
    parent->game->upgrade(1);
    parent->resumeGame();
    this->hide();
    delete this;
}

void UpgradeDialog::choose2() {
    parent->game->upgrade(2);
    parent->resumeGame();
    this->hide();
    delete this;
}

void UpgradeDialog::choose3() {
    parent->game->upgrade(3);
    parent->resumeGame();
    this->hide();
    delete this;
}