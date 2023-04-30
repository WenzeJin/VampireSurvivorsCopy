//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_GAMESTATE_H
#define VSCPROJECT_GAMESTATE_H
#include "Hero.h"
#include "PaintInfo.h"
#include "GameMap.h"
#include <QWidget>
#include <vector>
#include <QKeyEvent>


class GameState {
    QWidget * parent;
    GameMap * _map;
    Hero * player;
public:
    GameState();
    explicit GameState(QWidget * parent);
    ~GameState();

    void tick();                        //无条件tick
    void tick(QKeyEvent * event);       //键盘事件tick

    std::vector<PaintInfo> paint();

    void initMap(unsigned map_style);
    void initHero(unsigned hero_style);
};


#endif //VSCPROJECT_GAMESTATE_H
