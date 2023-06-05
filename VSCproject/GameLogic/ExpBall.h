//
// Created by 金文泽 on 2023/6/5.
//

#ifndef VSCPROJECT_EXPBALL_H
#define VSCPROJECT_EXPBALL_H
#include <utility>
#include <QRect>
#include "PaintInfo.h"
#include <QPixmap>
#include <exception>

class GameMap;

class ExpBall {
    int value;
    int cdn;
    bool enabled;
    std::pair<double, double> absolute_pos;
    QPixmap _image;
    GameMap * map_parent;
public:
    QRect real_rect;
    std::pair<double, double> real_pos;
    ExpBall(double x, double y, int value, GameMap * m_parent);
    void disable() { enabled = false; }
    void enable(double x, double y, int value);
    [[nodiscard]] bool isEnabled() const { return enabled; }
    [[nodiscard]] int getValue() const { return value; }
    PaintInfo paint();

    void tick();
};

class TimeLimitExceeded : public std::exception{
    int type;
public:
    explicit TimeLimitExceeded(int t){ type = t; };
};

#endif //VSCPROJECT_EXPBALL_H
