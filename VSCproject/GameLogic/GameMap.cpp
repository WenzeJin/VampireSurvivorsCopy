//
// Created by 金文泽 on 2023/4/18.
//

#include "GameMap.h"

GameMap::GameMap(unsigned int map_style) {
    int target_height = 0;
    if(map_style == 1){
        map_bg.load(MAP_1_PATH);
        target_height = MAP_1_HEIGHT;
    }
    pos_range.second = target_height;
    map_bg = map_bg.scaledToHeight(pos_range.second);
    pos_range.first = map_bg.width();
    absolute_pos.first = 0;
    absolute_pos.second = 0;
}

std::vector<PaintInfo> GameMap::paint() {
    std::vector<PaintInfo> buffer;
    buffer.emplace_back(map_bg,absolute_pos.first,absolute_pos.second);
    return buffer;
}

int GameMap::getPosRangeX() {
    return pos_range.first;
}

int GameMap::getPosRangeY() {
    return pos_range.second;
}

void GameMap::setAbsolutePos(int x, int y) {
    absolute_pos.first = x;
    absolute_pos.second = y;
}
