//
// Created by 金文泽 on 2023/4/18.
//

#include "GameState.h"
#include <assert.h>
#include <iostream>

void GameState::initMap(unsigned int map_style) {
    _map = new GameMap(map_style);
    _map->loadBarriers();
}

void GameState::initHero(unsigned int hero_style) {
    player = new Hero((int)hero_style, parent, _map);
    player->setGame(this);
    player->giveWeapon();

}

std::vector<PaintInfo> GameState::paint() {
    std::vector<PaintInfo> buffer;

    std::vector<PaintInfo> temp;
    //地图的信息
    temp = _map->paint();
    buffer.reserve(temp.size());
    for(auto& item: temp){
        buffer.push_back(item);
    }

    temp = player->paint();
    for(auto& item: temp){
        buffer.push_back(item);
    }

    for(auto& lst : enemies){
        for(auto& each : lst){
            if(each && each->isEnabled()) {
                std::vector<PaintInfo> temp_each = each->paint();
                for(auto& item : temp_each){
                    buffer.push_back(item);
                }
            }
        }
    }

    for(auto& each : exp_balls){
        if(each && each->isEnabled()){
            buffer.push_back(each->paint());
        }
    }

    return buffer;
}

GameState::GameState() {
    parent = nullptr;
    _map = nullptr;
    player = nullptr;
    enemy_control = nullptr;

    for(int i = 0; i < EBALL_MAX; i++){
        exp_balls.push_back(nullptr);
    }
    exp_cnt = 0;
    exp_max = EBALL_MAX;
}

GameState::GameState(QWidget *parent) :parent(parent){
    _map = nullptr;
    player = nullptr;
    enemy_control = nullptr;

    for(int i = 0; i < EBALL_MAX; i++){
        exp_balls.push_back(nullptr);
    }
    exp_cnt = 0;
    exp_max = EBALL_MAX;
}

GameState::~GameState() {
    delete _map;
    delete player;
    delete enemy_control;
    std::cerr << "到这还好" << std::endl;
//    for(auto & i : enemies){
//        for(auto & j : i){
//            delete j;
//        }
//    }
}

void GameState::tick() {
    std::cout << "掉落物数量" << exp_cnt << std::endl;
    player->tick();
    enemy_control->tick();
    for(auto& lst : enemies){
        for(auto& each : lst){
            if(each && each->isEnabled())
                each->tick();
        }
    }

    for(auto& each : exp_balls){
        if(each) {
            try {
                each->tick();
            }
            catch (TimeLimitExceeded &) {
                exp_cnt--;
            }
        }
    }

    judgeDamageEnemies();
}

void GameState::keyPressTick(QKeyEvent *event) {
    player->keyPressTick(event);
}

void GameState::keyReleaseTick(QKeyEvent *event) {
    player->keyReleaseTick(event);
}

void GameState::initEnemy(int stage) {
    enemy_control = new EnemyController(this, stage);
}

void GameState::judgeDamageEnemies() {
    for(auto & type : enemies){
        for(auto & each : type){
            player->judgeDamage(each);
        }
    }
}

void GameState::addExpBall(double x, double y, int value) {
    if(exp_cnt >= exp_max){
        return;
    }
    for(auto & space : exp_balls){
        if(space == nullptr){
            EBEnableNullSpace(x,y,value,space);
            return;
        } else if(!space->isEnabled()){
            EBEnableUsedSpace(x,y,value, space);
            return;
        }
    }
}

void GameState::EBEnableNullSpace(double x, double y, int value, ExpBall * &space) {
    assert(space == nullptr);
    space = new ExpBall(x,y,value,_map);
    exp_cnt ++;
}

void GameState::EBEnableUsedSpace(double x, double y, int value, ExpBall * &space) {
    assert(space && !space->isEnabled());
    space->enable(x,y,value);
    exp_cnt ++;
}

int GameState::countExp(std::pair<double, double> player_pos) {
    int cnt = 0;
    for(auto & each : exp_balls){
        if(each &&  each->isEnabled()){
            double x = each->real_pos.first;
            double y = each->real_pos.second;
            if(x >= player_pos.first && x <= player_pos.first + 60 &&
                y >= player_pos.second && y <= player_pos.second + 60){
                cnt += each->getValue();
                each->disable();
            }
        }
    }
    std::cout << "获得经验：" << cnt << std::endl;
    return cnt;
}

