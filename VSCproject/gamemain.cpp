//
// Created by 金文泽 on 2023/4/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameMain.h" resolved

#include "gamemain.h"
#include "ui_GameMain.h"


GameMain::GameMain(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameMain) {
    ui->setupUi(this);

    game = new GameState(this);
    game->initMap(1);
    game->initHero(1);
    game->initEnemy(1);
    initScene();
    m_Timer.setInterval(TIMER_RATE);

    playGame();
}

GameMain::~GameMain() {
    delete ui;
}

void GameMain::initScene() {
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
}

void GameMain::playGame() {
    m_Timer.start();

    connect(&m_Timer, &QTimer::timeout, [=](){
        game->tick();
        update();
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
