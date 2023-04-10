//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_GAMESTATE_H
#define VSCPROJECT_GAMESTATE_H
#include <vector>
#include <list>
#include <memory>
#include "Person.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GameMap.h"
#include "GameRule.h"
#include "GlobalVariables.h"

#define INIT_DEFAULT_PLAYER
#define INIT_DEFAULT_MAP


class GameState {
    Player GS_players;              //用于保存玩家
    std::list<Enemy> GS_enemies;    //用于保存敌人
    std::list<Bullet> GS_bullets;   //用于保存场上的子弹信息
    GameMap GS_map;                 //用于指定地图
    GameRule GS_rule;               //用于指定游戏难度与规则

public:

    GameState();        //默认构造
    GameState(PlayerCategories pc, MapCategories mc);

    bool game_over();    //返回游戏是否结束（依赖GS_rule）
    void tick();        //运行游戏的一个时钟tick

    void add_enemy(EnemyCategories ec);     //向游戏中添加一个敌人
    void add_bullet(const Person &shooter, const Person &target);   //向游戏中添加一个子弹
    void set_gamerule(GameRule &temp);

};


#endif //VSCPROJECT_GAMESTATE_H
