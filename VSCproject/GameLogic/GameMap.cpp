//
// Created by 金文泽 on 2023/4/18.
//

#include "GameMap.h"
#include <fstream>
#include <string>

GameMap::GameMap(unsigned int map_style) : map_style(map_style){
    int target_height = 0;
    if(map_style == 1){
        map_bg.load(MAP_1_PATH);
        map_br.load(MAP_1_BR);
        target_height = MAP_1_HEIGHT;
        lattice.first = MAP_1_LATTICE_X;
        lattice.second = MAP_1_LATTICE_Y;
    }
    pos_range.second = target_height;
    map_bg = map_bg.scaledToHeight(pos_range.second);
    pos_range.first = map_bg.width();
    absolute_pos.first = 0;
    absolute_pos.second = 0;

    lattice_scale.first = pos_range.first / lattice.first;
    lattice_scale.second = pos_range.second / lattice.second;
    map_br = map_br.scaled(lattice_scale.first, lattice_scale.second);
}

std::vector<PaintInfo> GameMap::paint() {
    std::vector<PaintInfo> buffer;
    buffer.emplace_back(map_bg,absolute_pos.first,absolute_pos.second);
    for(auto & each : barriers){
        buffer.emplace_back(map_br, each.x() + absolute_pos.first, each.y() + absolute_pos.second);
    }
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

void GameMap::loadBarriers() {
    std::string target;
    switch (map_style) {
        case 1:
            target = MAP_1_CONFIG;
    }
    int x = 0;
    int i = 0;
    int y = 0;
    int j = 0;
    std::ifstream config_file(target, std::ios::in);
    std::string this_line;
    while(!config_file.fail()){
        std::getline(config_file, this_line);
        x = 0;
        i = 0;
        for (char c: this_line) {
            if(c == '1'){
                QRect temp;
                temp.setWidth(lattice_scale.first);
                temp.setHeight(lattice_scale.second);
                temp.moveTo(x, y);
                barriers.push_back(temp);
            }
            x += lattice_scale.first;
            i ++;
            if(i >= lattice.first){
                break;
            }
        }
        y += lattice_scale.second;
        j ++;
        if(j >= lattice.second){
            break;
        }
    }
}

bool GameMap::checkPosition(const QRect &object) {
    for(auto & each : barriers){
        if(object.intersects(each)){
            return false;
        }
    }
    if(object.x() + object.width() > pos_range.first){
        return false;
    }
    if(object.y() + object.height() > pos_range.second){
        return false;
    }
    if(object.x() < 0 || object.y() < 0){
        return false;
    }
    return true;
}
