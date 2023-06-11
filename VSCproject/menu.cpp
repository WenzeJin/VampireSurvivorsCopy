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
#include <QLabel>
#include <QPixmap>


Menu::Menu(QWidget *parent) :
        QWidget(parent), ui(new Ui::Menu) {
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);

    ui->background->setPixmap(QPixmap(":/image/Assets/bg.PNG").scaled(661,451));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(launch_game()));
    connect(ui->pushButton_4, &QPushButton::clicked, [&](){
        auto * store_dialog = new StoreDialog(this);
        store_dialog->show();
        this->hide();
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [&](){
        _game->show();
        _game->resumeGame();
        GAME_HALT = 0;
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
    if(!GAME_HALT || !FIRST_RESUME) {
        auto * new_game = new SelectDialog(this);
        new_game->show();
        this->hide();
        _game = nullptr;
    } else {
        if(_game){
            delete _game;
            _game = nullptr;
        }
        auto * new_game = new GameMain(HERO_TYPE);
        new_game->show();
        new_game->setWidgetParent(this);
        this->hide();
        _game = new_game;
    }
}

void Menu::reportGamePaused() {
    ui->pushButton_2->setEnabled(true);
    _game->game->gameHalt();
}

void Menu::reportGameOver() {
    _game = nullptr;
    ui->pushButton_2->setEnabled(false);
}

void Menu::disableResume() {
    ui->pushButton_2->setEnabled(false);
}
