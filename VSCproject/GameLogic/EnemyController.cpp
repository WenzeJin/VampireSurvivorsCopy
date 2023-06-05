//
// Created by 金文泽 on 2023/5/7.
//

#include "EnemyController.h"
#include "GameState.h"
#include "Enemy.h"
#include "config.h"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

EnemyController::EnemyController(GameState *g, int stage) : game(g), game_stage(stage){
    StageInfo this_stage = STAGE_INFOS[stage - 1];
    type_num = this_stage.type_num;

    for(auto & each : g->enemies){
        each.clear();
    }
    g->enemies.clear();

    int vector_pos = 0;
    for(auto& each : this_stage.type_info){
        TypeController temp = {};
        temp.max_cds = each.cd_max;
        temp.enemy_type = each.enemy_type;
        temp.max_nums = each.max_nums;
        temp.num_counters = 0;
        temp.cds = each.cd_max;
        temp.min_cds = each.cd_min;
        temp.reduce_cds = each.reduce_rate;
        temp.reduce_counters = each.reduce_rate;
        temp.vector_pos = vector_pos;
        types.push_back(temp);
        std::vector<Enemy *> t(each.max_nums);
        g->enemies.push_back(t);
        vector_pos ++;
    }

    enemy_death_cnt = 0;

    srand(time(nullptr));
}

void EnemyController::addEnemy(int enemy_type, std::vector<Enemy *> &buffer) {
    for(auto & space : buffer){
        if(space == nullptr){
            enableNullSpace(enemy_type, space);
            return;
        } else if(!space->isEnabled()){
            enableUsedSpace(enemy_type, space);
            return;
        }
    }
}

void EnemyController::reportDeath(int type) {
    for(auto & each : types){
        if(each.enemy_type == type) {
            each.num_counters --;
            assert(each.num_counters >= 0);
            break;
        }
    }

    switch(type){
        case 1:
            enemy_death_cnt ++;
    }
}

void EnemyController::enableNullSpace(int enemy_type, Enemy *&space) {
    std::pair<double, double> real_pos = generatePosition();
    switch(enemy_type){
        case 1:
            space = new ENEMY_1_TYPE(1, game->parent, this, game->_map,
                                     game->player, real_pos.first, real_pos.second);
            break;
        case 2:
            space = new ENEMY_2_TYPE(2, game->parent, this, game->_map,
                                     game->player, real_pos.first, real_pos.second);
            break;
        case 3:
            space = new ENEMY_3_TYPE(3, game->parent, this, game->_map,
                                     game->player, real_pos.first, real_pos.second);
            break;
    }
    space->enable();
}

void EnemyController::enableUsedSpace(int enemy_type, Enemy *&space) {
    std::pair<double, double> real_pos = generatePosition();
    space->setRealPosition(real_pos.first, real_pos.second);
    space->enable();
}

std::pair<double, double> EnemyController::generatePosition() {
    bool left_or_right;
    bool up_or_down;
    if(game->_map->getAbsoluteX() > 0){
        left_or_right = true;
    } else if(game->_map->getAbsoluteX() + game->_map->getPosRangeX() <= GAME_WIDTH){
        left_or_right = false;
    } else {
        left_or_right = rand() % 2;
    }

    if(game->_map->getAbsoluteY() > 0){
        up_or_down = true;
    } else if(game->_map->getAbsoluteY() + game->_map->getPosRangeY() <= GAME_HEIGHT){
        up_or_down = false;
    } else {
        up_or_down = rand() % 2;
    }


    double x;
    double y;

    if(left_or_right){
        x = (double)(0 - game->_map->getAbsoluteX() + GAME_WIDTH);
    } else {
        x = (double)(0 - game->_map->getAbsoluteX());
    }

    if(up_or_down){ 
        y = (double)(0 - game->_map->getAbsoluteY() + GAME_HEIGHT);
    } else {
        y = (double)(0 - game->_map->getAbsoluteY());
    }


    return {x, y};

}

void EnemyController::tick() {
    //先处理reduce_cd
    for(auto & each : types){
        if(each.reduce_counters == 0 && each.max_cds > each.min_cds){
            each.max_cds --;
            each.reduce_counters = each.reduce_cds;
        } else if(each.reduce_counters == 0){
            each.reduce_counters = each.reduce_cds;
        } else {
            each.reduce_counters --;
        }
    }

    //再处理敌人生成
    for(auto & each : types){
        if(each.cds <= 0 && each.num_counters < each.max_nums){
            addEnemy(each.enemy_type, game->enemies[each.vector_pos]);
            each.num_counters ++;
            each.cds = each.max_cds;
        } else if(each.num_counters < each.max_nums){
            each.cds --;
        }
    }
}

void EnemyController::reportDeath(int type, double rx, double ry) {
    for(auto & each : types){
        if(each.enemy_type == type) {
            each.num_counters --;
            assert(each.num_counters >= 0);
            break;
        }
    }

    int value;
    switch(type){
        case 1:
            enemy_death_cnt ++;
            value = 10;
            break;
        case 2:
            enemy_death_cnt ++;
            value = 10;
            break;
        case 3:
            enemy_death_cnt += 2;
            value = 20;
            break;
    }

    game->addExpBall(rx,ry, value);
}
