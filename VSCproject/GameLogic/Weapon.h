//
// Created by 金文泽 on 2023/4/29.
//

#ifndef VSCPROJECT_WEAPON_H
#define VSCPROJECT_WEAPON_H
#include "Bullet.h"
#include "Hero.h"
#include <vector>
#include "PaintInfo.h"

class Hero;
class Bullet;

class Weapon {
    GameMap * map_parent = nullptr;
    unsigned bullet_style;
protected:
    Hero * user;
    int bullet_tot;
    std::vector<Bullet *> bullet_buffer;
    int damage;
public:
    Weapon(unsigned bullet_style, int damage, Hero * user, GameMap * map_p);
    virtual void tick() = 0;

    std::vector<PaintInfo> paint();
    [[nodiscard]] Hero * getUser() const { return user; }
};

class HeroStaticAOEWeapon : public Weapon{
    bool bullet_enabled = false;
    int range;
public:
    HeroStaticAOEWeapon(GameMap * map_p, Hero * user, int range, unsigned bullet_style, int damage);

    void tick() override;
};


#endif //VSCPROJECT_WEAPON_H
