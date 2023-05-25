//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_HERO_H
#define VSCPROJECT_HERO_H
#include <utility>
#include <QWidget>
#include <QProgressBar>
#include <QRect>
#include <QKeyEvent>
#include <list>
#include "PaintInfo.h"
#include "config.h"
#include "GameMap.h"
#include "Enemy.h"
#include "Weapon.h"

class Weapon;
class GameState;

class Hero {
    //基本属性
    int HP_MAX;
    int hp;
    int exp;
    int level;
    bool alive;
    int speed;
    //两个可视化显示条
    QProgressBar * hp_bar;
    QProgressBar * exp_bar;
    //用于设置显示进度条的指针
    QWidget * widget_parent;
    //绝对窗口坐标
    std::pair<int, int> absolute_pos;
    //相对地图坐标
    std::pair<double, double> real_pos;
    QPixmap _image;
    GameMap * map_parent;
    //武器部分
    int weapon_type;
    Weapon * _weapon;

    //处理键盘问题
    std::list<int> keys_pressed;
    GameState * _game;

    //处理生成在障碍物上的问题
    bool init_interact = true;

public:
    QRect absolute_rect; //碰撞箱
    QRect real_rect;

    Hero();
    explicit Hero(int hero_style, QWidget * w_parent, GameMap * m_parent); //一般使用这个
    void setGame(GameState * t) {_game = t;}

    void setWidgetParent(QWidget * parent);
    void giveWeapon();

    void tick(); //无条件tick
    void keyPressTick(QKeyEvent * event);
    void keyReleaseTick(QKeyEvent * event);
    bool judgeDamage(Enemy * e);
    std::vector<PaintInfo> paint();

    void damage(int h);

    bool isGameStop() { return !alive; }


    void setRealPosition(double x, double y);

    [[nodiscard]] double getRealX() const { return real_pos.first; };
    [[nodiscard]] double getRealY() const { return real_pos.second; };
    [[nodiscard]] int getAbsoluteX() const { return absolute_pos.first; };
    [[nodiscard]] int getAbsoluteY() const { return absolute_pos.second; };
    [[nodiscard]] GameState * getGame() const { return _game; }

private:
    void healthChange();
    void expChange();
    void setExpBarPosition();
    void setHpBarPosition();

    bool attemptMove(int x_bias, int y_bias);
};


#endif //VSCPROJECT_HERO_H
