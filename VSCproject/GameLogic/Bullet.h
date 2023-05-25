//
// Created by 金文泽 on 2023/4/30.
//

#ifndef VSCPROJECT_BULLET_H
#define VSCPROJECT_BULLET_H
#include "GameMap.h"
#include <utility>
#include <QPixmap>
#include "PaintInfo.h"



class Hero;
class Enemy;

class Bullet {
    GameMap * map_parent = nullptr;
    bool enabled = false;
    unsigned bullet_style;

public:
    Bullet(unsigned bullet_style, int damage, GameMap * map_p);
    virtual void tick() = 0;
    virtual void enable() { enabled = true; }
    virtual void disable() { enabled = false; }
    virtual bool judge_damage(Enemy *) = 0;
    virtual bool judge_damage(Hero *) = 0;

    void setRealPosition(int x, int y);

    PaintInfo paint();

    [[nodiscard]] double getRealX() const { return real_pos.first; }
    [[nodiscard]] double getRealY() const { return real_pos.second; }
    [[nodiscard]] int getAbsoluteX() const { return absolute_pos.first; }
    [[nodiscard]] int getAbsoluteY() const { return absolute_pos.second; }
    [[nodiscard]] bool isEnabled() const { return enabled; }

protected:
    std::pair<double, double> real_pos;
    std::pair<int, int> absolute_pos;
    int damage;
    QPixmap _image;
};

class HeroStaticAOEBullet : public Bullet{
    int range;
    int CD;
    int cds;
    std::pair<double, double> center_real_pos;
    Hero * user;
public:
    HeroStaticAOEBullet(GameMap * map_parent, Hero * user, int range, unsigned bullet_style, int damage);
    void tick() override;
    bool judge_damage(Enemy *) override;
    bool judge_damage(Hero *) override { return false; }
private:
    void update_pos();
};

class HeroDynamicBullet : public Bullet {
    QRect real_rect;
    Enemy * target;
    int speed;
public:
    HeroDynamicBullet(GameMap * map_parent, Hero * user, Enemy * target, unsigned bullet_style, int damage);
    void tick() override;
    bool judge_damage(Enemy *) override;
    bool judge_damage(Hero *) override { return false; }
private:
    void update_pos();
    std::pair<double, double> getDirectionVector();
};

#endif //VSCPROJECT_BULLET_H
