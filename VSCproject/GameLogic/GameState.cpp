//
// Created by 金文泽 on 2023/4/18.
//

#include "GameState.h"

void GameState::initMap(unsigned int map_style) {
    _map = new GameMap(map_style);
}

void GameState::initHero(unsigned int hero_style) {
    player = new Hero((int)hero_style, parent, _map);
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

    return buffer;
}

GameState::GameState() {
    parent = nullptr;
    _map = nullptr;
    player = nullptr;
}

GameState::GameState(QWidget *parent) :parent(parent){
    _map = nullptr;
    player = nullptr;
}

GameState::~GameState() {
    delete _map;
}

void GameState::tick() {
    player->tick();
}

void GameState::tick(QKeyEvent *event) {
    player->tick(event);
}

