//
// Created by 金文泽 on 2023/4/30.
//

#ifndef VSCPROJECT_ENEMY_H
#define VSCPROJECT_ENEMY_H
#include <utility>
#include <QWidget>
#include <QProgressBar>
#include <QRect>
#include <QKeyEvent>
#include "PaintInfo.h"
#include "config.h"
#include "GameMap.h"
#include "Hero.h"
#include "Weapon.h"

class Weapon;
class Hero;
class EnemyController;

class Enemy {
protected:
    //基本属性
    int HP_MAX;
    int hp;
    bool alive;
    bool enabled;
    int speed = 10;

    int enemy_type;
    //血量显示
    QProgressBar * hp_bar;
    //用于设置显示进度条的指针
    QWidget * widget_parent;
    //绝对窗口坐标
    std::pair<int, int> absolute_pos;
    //相对地图坐标
    std::pair<double, double> real_pos;
    QPixmap _image;
    GameMap * map_parent;
    Hero * target;
    EnemyController * controller;

    virtual void die();
public:
    QRect absolute_rect; //碰撞箱
    QRect real_rect;

    Enemy(int enemy_style, QWidget * w_parent, EnemyController * controller, GameMap * m_parent,
          Hero * target, double real_X, double real_Y);

    virtual void tick() = 0;

    PaintInfo paint();

    void setRealPosition(double x, double y);

    virtual void enable();
    virtual void disable();

    virtual void damage(int d);

    [[nodiscard]] double getRealX() const { return real_pos.first; };
    [[nodiscard]] double getRealY() const { return real_pos.second; };
    [[nodiscard]] int getAbsoluteX() const { return absolute_pos.first; };
    [[nodiscard]] int getAbsoluteY() const { return absolute_pos.second; };
    [[nodiscard]] bool isEnabled() const { return enabled; };

protected:
    //TODO:bool attemptMove(int x_bias, int y_bias);

private:
    void healthChange();
    void setHpBarPosition();
};


class NoWeaponEnemy : public Enemy{
    int power;
    int CD;
    int cdn;
public:
    NoWeaponEnemy(int enemy_style, QWidget * w_parent, EnemyController * controller, GameMap * m_parent, Hero * target, double real_X, double real_Y);

    void tick() override;

private:
    bool judgeDamage();
    std::pair<double, double> getDirectionVector();
};


#endif //VSCPROJECT_ENEMY_H
