//
// Created by 金文泽 on 2023/4/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Menu.h" resolved

#include "menu.h"
#include "ui_Menu.h"
#include "storedialog.h"
#include "gamemain.h"
#include "selectdialog.h"
#include "savedialog.h"


Menu::Menu(QWidget *parent) :
        QWidget(parent), ui(new Ui::Menu) {
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(launch_game()));
    connect(ui->pushButton_4, &QPushButton::clicked, [&](){
        auto * store_dialog = new StoreDialog(this);
        store_dialog->show();
        this->hide();
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [&](){
        _game->show();
        _game->resumeGame();
        this->hide();
        ui->pushButton_2->setEnabled(false);

    });
    connect(ui->pushButton_3, &QPushButton::clicked, [&](){
        auto * save_dialog = new SaveDialog(this);
        save_dialog->show();
        this->hide();
    });
    _game = nullptr;

}

Menu::~Menu() {
    delete ui;
}

void Menu::launch_game() {
    auto * new_game = new SelectDialog(this);
    new_game->show();
    this->hide();
    _game = nullptr;
}

void Menu::reportGamePaused() {
    ui->pushButton_2->setEnabled(true);
}

void Menu::reportGameOver() {
    _game = nullptr;
    ui->pushButton_2->setEnabled(false);
}
