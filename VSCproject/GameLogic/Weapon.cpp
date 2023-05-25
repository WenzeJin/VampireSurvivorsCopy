//
// Created by 金文泽 on 2023/4/29.
//

#include "Weapon.h"


Weapon::Weapon(unsigned int bullet_style, int damage, Hero * user, GameMap *map_p) :
bullet_style(bullet_style), damage(damage), map_parent(map_p), user(user), bullet_tot(0)
{}

std::vector<PaintInfo> Weapon::paint() {
    std::vector<PaintInfo> buffer;
    for(auto item : bullet_buffer){
        if(item->isEnabled()){
            buffer.push_back(item->paint());
        }
    }
    return buffer;
}

bool Weapon::judgeDamage(Enemy * e) {
    bool check = false;
    for(auto & each: bullet_buffer){
        if(each && each->isEnabled()){
            if(each->judge_damage(e)){
                check = true;
            }
        }
    }
    return check;
}

HeroStaticAOEWeapon::HeroStaticAOEWeapon(GameMap *map_p, Hero *user, int range, unsigned int bullet_style, int damage) :
Weapon(bullet_style, damage, user, map_p), range(range){
    bullet_tot = 1;
    Bullet * temp = new HeroStaticAOEBullet(map_p, user, range, bullet_style, damage);
    bullet_buffer.push_back(temp);
}

void HeroStaticAOEWeapon::tick() {
    if(!bullet_enabled){
        bullet_buffer[0]->enable();
        bullet_enabled = true;
    }

    bullet_buffer[0]->tick();
}
