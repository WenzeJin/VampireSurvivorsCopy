//
// Created by 金文泽 on 2023/4/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameMain.h" resolved

#include "gamemain.h"
#include "ui_GameMain.h"
#include <QString>
#include <QPushButton>
#include <iostream>
#include "upgradedialog.h"
#include "menu.h"
#include "gameoverdialog.h"


GameMain::GameMain(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameMain) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    initScene();
    m_Timer.setInterval(TIMER_RATE);
    hero_type = 1;
    connect(ui->pause_button, &QPushButton::clicked, [&]()->void { pauseButtonClicked(); });
    ui->pause_button->setText("暂停");

    connect(ui->back_button, &QPushButton::clicked, [&]()->void {
        if(!game_paused) { pauseButtonClicked(); }
        this->hide();
        widget_parent->show();
        widget_parent->reportGamePaused();
    });

    connect(ui->end_button, &QPushButton::clicked, [&]()->void {
        if(!game_paused) { pauseButtonClicked(); }
        this->hide();
        widget_parent->reportGameOver();
        auto * new_dialog = new GameOverDialog(widget_parent, game->getEnemyDeathCnt(), game->getHPPercent());
        new_dialog->show();
        this->hide();
        delete this;
    });

    playGame();
}

GameMain::~GameMain() {
    this->hide();
    delete game;
    delete ui;
}

void GameMain::initScene() {
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    game = new GameState(this);
    game->initMap(1);
    game->initHero(hero_type);
    game->initEnemy(1);
    GAME_HALT = 0;
    FIRST_RESUME = 0;
}

void GameMain::playGame() {
    game_paused = false;
    m_Timer.start();

    connect(&m_Timer, &QTimer::timeout, [=](){
        game->tick();
        update();
        ui->enemy_cnt_label->setText("已清除敌人数量：" + QString::number(game->getEnemyDeathCnt()));
        ui->level_label->setText("当前等级："+QString::number(game->getPlayerLevel()));
        if(game->isGameStop()) {
            m_Timer.stop();
            game_paused = true;
            ui->pause_button->setEnabled(false);
            ui->back_button->setEnabled(false);
            ui->enemy_cnt_label->setText("游戏已结束，请点击结算：" + QString::number(game->getEnemyDeathCnt()));
        }
        if(game->isWaiting()) {
            UpgradeDialog * up_diag = new UpgradeDialog(this);
            pauseButtonClicked();
            ui->pause_button->setEnabled(false);
            up_diag->show();
        }
    });
}

void GameMain::paintEvent(QPaintEvent * event) {
    QPainter painter(this);

    std::vector<PaintInfo> buffer = game->paint();

    for(auto & item: buffer){
        painter.drawPixmap(item.getMX(), item.getMY(), item.getTarget());
    }
}

void GameMain::keyPressEvent(QKeyEvent *event) {
    game->keyPressTick(event);
}

void GameMain::keyReleaseEvent(QKeyEvent *event) {
    game->keyReleaseTick(event);
}

void GameMain::pauseButtonClicked() {
    if(game_paused){
        m_Timer.start();
        game_paused = false;
        ui->pause_button->setText("暂停");
    } else {
        m_Timer.stop();
        game_paused = true;
        ui->pause_button->setText("继续");
    }
}

void GameMain::resumeGame() {
    if(game_paused){
        pauseButtonClicked();
        ui->pause_button->setEnabled(true);
    }
}

GameMain::GameMain(int hero_type, QWidget *parent) :
        QWidget(parent), ui(new Ui::GameMain) , hero_type(hero_type){
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    initScene();
    m_Timer.setInterval(TIMER_RATE);

    connect(ui->pause_button, &QPushButton::clicked, [&]()->void { pauseButtonClicked(); });
    ui->pause_button->setText("暂停");

    connect(ui->back_button, &QPushButton::clicked, [&]()->void {
        if(!game_paused) { pauseButtonClicked(); }
        this->hide();
        widget_parent->show();
        widget_parent->reportGamePaused();
    });

    connect(ui->end_button, &QPushButton::clicked, [&]()->void {
        if(!game_paused) { pauseButtonClicked(); }
        this->hide();
        widget_parent->reportGameOver();
        auto * new_dialog = new GameOverDialog(widget_parent, game->getEnemyDeathCnt(), game->getHPPercent());
        new_dialog->show();
        this->hide();
        delete this;
    });

    playGame();
}

