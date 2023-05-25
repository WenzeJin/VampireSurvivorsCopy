//
// Created by 金文泽 on 2023/4/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameMain.h" resolved

#include "gamemain.h"
#include "ui_GameMain.h"
#include <QString>
#include <QPushButton>


GameMain::GameMain(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameMain) {
    ui->setupUi(this);

    initScene();
    m_Timer.setInterval(TIMER_RATE);

    connect(ui->pause_button, &QPushButton::clicked, [&]()->void { pauseButtonClicked(); });
    ui->pause_button->setText("暂停");

    playGame();
}

GameMain::~GameMain() {
    delete ui;
}

void GameMain::initScene() {
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    game = new GameState(this);
    game->initMap(1);
    game->initHero(1);
    game->initEnemy(1);
}

void GameMain::playGame() {
    game_paused = false;
    m_Timer.start();

    connect(&m_Timer, &QTimer::timeout, [=](){
        game->tick();
        update();
        ui->enemy_cnt_label->setText("已清除敌人数量：" + QString::number(game->getEnemyDeathCnt()));
        if(game->isGameStop()) {
            m_Timer.stop();
            game_paused = true;
            ui->pause_button->setEnabled(false);
            ui->enemy_cnt_label->setText("游戏已结束，""已清除敌人数量：" + QString::number(game->getEnemyDeathCnt()));
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

