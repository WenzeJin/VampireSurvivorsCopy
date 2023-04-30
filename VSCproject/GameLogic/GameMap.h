//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_GAMEMAP_H
#define VSCPROJECT_GAMEMAP_H
#include "config.h"
#include "PaintInfo.h"
#include <QPixmap>
#include <utility>
#include <exception>

class GameMap {
    unsigned map_style;
    QPixmap map_bg;
    std::pair<int, int> pos_range;
    std::pair<int, int> absolute_pos;

public:
    explicit GameMap(unsigned map_style);

    std::vector<PaintInfo> paint();

    int getPosRangeX();
    int getPosRangeY();

    void setAbsolutePos(int x, int y);
};


#endif //VSCPROJECT_GAMEMAP_H
