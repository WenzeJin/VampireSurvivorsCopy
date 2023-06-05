//
// Created by 金文泽 on 2023/4/11.
//

#ifndef VSCPROJECT_GAMEMAIN_H
#define VSCPROJECT_GAMEMAIN_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include "GameLogic/GameState.h"
#include "GameLogic/config.h"

class Menu;

QT_BEGIN_NAMESPACE
namespace Ui { class GameMain; }
QT_END_NAMESPACE

class GameMain : public QWidget {
Q_OBJECT

public:
    explicit GameMain(QWidget *parent = nullptr);
    explicit GameMain(int hero_type, QWidget * parent = nullptr);

    ~GameMain() override;

    void setWidgetParent(Menu * in) { widget_parent = in;};
    GameState * game;

    void resumeGame();

private:
    Ui::GameMain * ui;
    Menu * widget_parent;
    QTimer m_Timer;
    int hero_type;
    bool game_paused;

    void initScene();
    void playGame();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void pauseButtonClicked();
};


#endif //VSCPROJECT_GAMEMAIN_H
