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
#include <utility>
#include "ExpBall.h"

class EnemyController;

class GameState {
    QWidget * parent;
    GameMap * _map;
    Hero * player;
    EnemyController * enemy_control;
    std::vector<std::vector<Enemy *>> enemies;
    std::vector<ExpBall *> exp_balls;

    int exp_cnt;
    int exp_max;
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

    [[nodiscard]] int getEnemyDeathCnt() { return enemy_control->getEnemyDeathCnt(); };
    [[nodiscard]] int getPlayerLevel() const { return player->getLevel(); }

    bool isGameStop() { return player->isGameStop(); }

    void addExpBall(double x, double y, int value);
    void EBEnableNullSpace(double x, double y, int value, ExpBall * &space);
    void EBEnableUsedSpace(double x, double y, int value, ExpBall * &space);

    int countExp(std::pair<double, double> player_pos);

    void upgrade(int type) { player->upgrade(type); }
    double getHPPercent() { return player->get_hp_percent(); }

    bool isWaiting() { return player->isWaiting(); };


    friend class EnemyController;
    friend class Bullet;
    friend class HeroStaticAOEBullet;
    friend class HeroDynamicWeapon;

private:
    void judgeDamageEnemies();
};


#endif //VSCPROJECT_GAMESTATE_H

