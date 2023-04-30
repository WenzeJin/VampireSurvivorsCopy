//
// Created by 金文泽 on 2023/4/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Menu.h" resolved

#include "menu.h"
#include "ui_Menu.h"


Menu::Menu(QWidget *parent) :
        QWidget(parent), ui(new Ui::Menu) {
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(launch_game()));
}

Menu::~Menu() {
    delete ui;
}

void Menu::launch_game() {
    auto * new_game = new GameMain();
    new_game->show();
    new_game->setWidgetParent(this);
    this->hide();
}
