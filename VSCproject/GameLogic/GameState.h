//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_GAMESTATE_H
#define VSCPROJECT_GAMESTATE_H
#include "Hero.h"
#include "Enemy.h"
#include "PaintInfo.h"
#include "EnemyController.h"
#include "GameMap.h"
#include <QWidget>
#include <vector>
#include <QKeyEvent>

class EnemyController;

class GameState {
    QWidget * parent;
    GameMap * _map;
    Hero * player;
    EnemyController * enemy_control;
    std::vector<std::vector<Enemy *>> enemies;
public:
    GameState();
    explicit GameState(QWidget * parent);
    ~GameState();

    void tick();                        //无条件tick
    void keyPressTick(QKeyEvent * event);       //键盘事件tick
    void keyReleaseTick(QKeyEvent * event);

    std::vector<PaintInfo> paint();

    void initMap(unsigned map_style);
    void initHero(unsigned hero_style);
    void initEnemy(int stage);

    friend class EnemyController;
};


#endif //VSCPROJECT_GAMESTATE_H
