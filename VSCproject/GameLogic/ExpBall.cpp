//
// Created by 金文泽 on 2023/6/5.
//

#include "ExpBall.h"
#include "config.h"
#include "GameMap.h"

PaintInfo ExpBall::paint() {
    return {_image, (int)absolute_pos.first, (int)absolute_pos.second};
}

ExpBall::ExpBall(double x, double y, int value, GameMap * m_parent) {
    map_parent = m_parent;
    real_pos.first = x;
    real_pos.second = y;
    absolute_pos.first = real_pos.first + map_parent->getAbsoluteX();
    absolute_pos.second = real_pos.second + map_parent->getAbsoluteY();
    this->value = value;
    _image.load(EBALL_PATH);
    _image = _image.scaled(EBALL_SIZE, EBALL_SIZE);
    real_rect.setHeight(EBALL_SIZE);
    real_rect.setWidth(EBALL_SIZE);
    real_rect.moveTo(real_pos.first, real_pos.second);
    enabled = true;
    cdn = EBALL_CD;
}

void ExpBall::enable(double x, double y, int value) {
    real_pos.first = x;
    real_pos.second = y;
    absolute_pos.first = real_pos.first + map_parent->getAbsoluteX();
    absolute_pos.second = real_pos.second + map_parent->getAbsoluteY();
    this->value = value;
    enabled = true;
    cdn = EBALL_CD;
}

void ExpBall::tick() {
    if(enabled) {
        if (cdn <= 0) {
            disable();
            throw TimeLimitExceeded(0);
        } else {
            cdn--;
            absolute_pos.first = real_pos.first + map_parent->getAbsoluteX();
            absolute_pos.second = real_pos.second + map_parent->getAbsoluteY();
        }
    }
}
