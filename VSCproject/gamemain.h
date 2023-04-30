//
// Created by 金文泽 on 2023/4/11.
//

#ifndef VSCPROJECT_GAMEMAIN_H
#define VSCPROJECT_GAMEMAIN_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include "menu.h"
#include "GameLogic/GameState.h"
#include "GameLogic/config.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameMain; }
QT_END_NAMESPACE

class GameMain : public QWidget {
Q_OBJECT

public:
    explicit GameMain(QWidget *parent = nullptr);

    ~GameMain() override;

    void setWidgetParent(QWidget * in) { widget_parent = in;};

private:
    Ui::GameMain * ui;
    QWidget * widget_parent;
    QTimer m_Timer;
    GameState * game;

    void initScene();
    void playGame();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};


#endif //VSCPROJECT_GAMEMAIN_H
