//
// Created by 金文泽 on 2023/6/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SelectDialog.h" resolved

#include "selectdialog.h"
#include "ui_SelectDialog.h"
#include "gamemain.h"
#include "menu.h"

SelectDialog::SelectDialog(Menu * menu_parent, QWidget *parent) :
        QWidget(parent), ui(new Ui::SelectDialog) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    m_p = menu_parent;
    connect(ui->pushButton, &QPushButton::clicked,[&](){
        auto * new_game = new GameMain(1);
        new_game->show();
        new_game->setWidgetParent(m_p);
        this->hide();
        m_p->reportGameStart(new_game);
    });
    connect(ui->pushButton_2, &QPushButton::clicked,[&](){
        auto * new_game = new GameMain(2);
        new_game->show();
        new_game->setWidgetParent(m_p);
        this->hide();
        m_p->reportGameStart(new_game);
    });
}

SelectDialog::~SelectDialog() {
    this->hide();
    delete ui;
}
