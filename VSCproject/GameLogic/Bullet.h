//
// Created by 金文泽 on 2023/4/30.
//

#ifndef VSCPROJECT_BULLET_H
#define VSCPROJECT_BULLET_H
#include "GameMap.h"
#include <utility>
#include <QPixmap>
#include <exception>
#include "PaintInfo.h"



class Hero;
class Enemy;

class Bullet {

    bool enabled = false;
    unsigned bullet_style;

public:
    Bullet(unsigned bullet_style, int damage, GameMap * map_p);
    virtual void tick() = 0;
    virtual void enable() { enabled = true; }
    virtual void disable() { enabled = false; }
    virtual bool judge_damage(Enemy *) = 0;
    virtual bool judge_damage(Hero *) = 0;
    virtual void enable(Enemy *) { enabled = true; }
    virtual void upgrade() {};

    virtual void setRealPosition(double x, double y);

    void setDamage(int d) { damage = d; }


    PaintInfo paint();

    [[nodiscard]] double getRealX() const { return real_pos.first; }
    [[nodiscard]] double getRealY() const { return real_pos.second; }
    [[nodiscard]] int getAbsoluteX() const { return absolute_pos.first; }
    [[nodiscard]] int getAbsoluteY() const { return absolute_pos.second; }
    [[nodiscard]] bool isEnabled() const { return enabled; }

protected:
    std::pair<double, double> real_pos;
    GameMap * map_parent = nullptr;
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

    void upgrade() override {
        CD = (int)((double)CD / WEAPON_INC_RATE);
        if(CD <= 20){
            CD = 20;
        }
    }
private:
    void update_pos();
};

class HeroDynamicBullet : public Bullet {
    QRect real_rect;
    Enemy * target;
    int speed;
    Hero * user;
public:
    HeroDynamicBullet(GameMap * map_parent, Hero * user, Enemy * target, unsigned bullet_style, int damage);
    void tick() override;
    void setRealPosition(double x, double y) override;
    void enable(Enemy * e) override;
    bool judge_damage(Enemy *) override;
    bool judge_damage(Hero *) override { return false; }
private:
    std::pair<double, double> getDirectionVector();
};

class TargetLossError : public std::exception{
    int type;
public:
    explicit TargetLossError(int t) { type = t; };
};

class TargetHit : public std::exception{
    int type;
public:
    explicit TargetHit(int t) { type = t; };
};

class EnemyDynamicBullet : public Bullet {
    QRect real_rect;
    Hero * target;
    std::pair<double, double> direction_vector;
    int speed;
    Enemy * user;
public:
    EnemyDynamicBullet(GameMap * map_parent, Hero * target, Enemy * user, int damage);
    void tick() override;
    void setRealPosition(double x, double y) override;
    void enable() override;
    bool judge_damage(Enemy *) override { return false; };
    bool judge_damage(Hero *) override;
};

class OutOfRange : public std::exception{
    int type;
public:
    explicit OutOfRange(int t) {type = t; };
};

#endif //VSCPROJECT_BULLET_H
