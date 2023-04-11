//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_WEAPON_H
#define VSCPROJECT_WEAPON_H
#include "Bullet.h"
#include "GameRule.h"
#include "Person.h"



class Weapon {
    int damage;
    int CD;
    int cool_down;
    GameRule::BulletCategories bullet_cate;
    const Person * target;
    const Person * user;

public:
    Weapon();
    Weapon(int dg, int cd, GameRule::BulletCategories bc, const Person * us);

    void tick();

private:
    Person * find_target();
};


#endif //VSCPROJECT_WEAPON_H
