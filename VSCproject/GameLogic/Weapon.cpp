//
// Created by 金文泽 on 2023/4/29.
//

#include "Weapon.h"
#include <assert.h>
#include <iostream>
#include <cmath>
#include "GameState.h"
#include "Enemy.h"
#include "config.h"


Weapon::Weapon(unsigned int bullet_style, int damage, Hero * user, GameMap *map_p) :
bullet_style(bullet_style), damage(damage), map_parent(map_p), user(user), bullet_tot(0)
{
    if(GAME_HALT){
        this->damage = DAMAGE;
    }
}

std::vector<PaintInfo> Weapon::paint() {
    std::vector<PaintInfo> buffer;
    for(auto item : bullet_buffer){
        if(item && item->isEnabled()){
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

void Weapon::upgrade() {
    damage = (int)((double)damage * WEAPON_INC_RATE);
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

void HeroStaticAOEWeapon::upgrade() {
    Weapon::upgrade();
    bullet_buffer[0]->upgrade();
}


HeroDynamicWeapon::HeroDynamicWeapon(GameMap *map_p, Hero *user, int CD, unsigned int bullet_style, int damage) :
Weapon(bullet_style, damage, user, map_p), CD(CD), cdn(CD){
    bullet_tot = DYNAMIC_BULLETS_MAX;
    if(GAME_HALT){
        this->CD = HALT_CD;
        this->cdn = CD;
    }
    curr_bullet_cnt = 0;
    _game = user->getGame();
    for(int i = 0; i < bullet_tot; i++){
        bullet_buffer.push_back(nullptr);
    }
}

void HeroDynamicWeapon::tick() {
    if(cdn <= 0){
        addBullet();
        std::cout << "当前活动子弹数量：" << curr_bullet_cnt << std::endl;
        cdn = CD;
    } else {
        cdn --;
    }

    for(auto & each_b : bullet_buffer){
        if(each_b && each_b->isEnabled()){
            try{
                each_b->tick();
            }
            catch (TargetLossError &){
                curr_bullet_cnt --;
            }
            catch (TargetHit &){
                curr_bullet_cnt --;
            }
        }
    }
}

void HeroDynamicWeapon::addBullet() {
    if(curr_bullet_cnt >= bullet_tot) {
        return;
    }
    for(auto & space: bullet_buffer){
        if(space == nullptr){
            enableNullSpace(space);
            return;
        } else if(!space->isEnabled()){
            enableUsedSpace(space);
            return;
        }
    }
}

void HeroDynamicWeapon::enableNullSpace(Bullet * & space) {
    std::cout << "准备启用空指针" << std::endl;
    assert(space == nullptr);
    Enemy * t;
    try{
        t = findTarget();
    }
    catch(TargetNotFoundError &){
        return;
    }

    space = new HeroDynamicBullet(map_parent, user, t, bullet_style, damage);
    space->enable(t);
    std::cout << space->isEnabled() << std::endl;
    curr_bullet_cnt ++;
}

void HeroDynamicWeapon::enableUsedSpace(Bullet * & space) {
    std::cout << "准备重启指针" << std::endl;
    assert(space);
    Enemy * t;
    try{
        t = findTarget();
    }
    catch(TargetNotFoundError &){
        return;
    }

    space->enable(t);
    space->setDamage(damage);
    curr_bullet_cnt ++;
}

Enemy * HeroDynamicWeapon::findTarget() {
    Enemy * target = nullptr;
    double min_distance = 500;
    for(auto & each_type : _game->enemies){
        for(auto & each : each_type){
            if(each && each->isEnabled()) {
                double x_bias = each->getRealX() - user->getRealX();
                double y_bias = each->getRealY() - user->getRealY();
                double distance = sqrt(x_bias * x_bias + y_bias * y_bias);
                if (distance < min_distance) {
                    min_distance = distance;
                    target = each;
                }
            }
        }
    }
    if(target){
        return target;
    } else {
        std::cout << "没找到目标" << std::endl;
        throw TargetNotFoundError(0);
    }
}

void HeroDynamicWeapon::upgrade() {
    Weapon::upgrade();
    CD = (int)((double)CD / WEAPON_INC_RATE);
    if(CD <= 10){
        CD = 10;
    }
}


EnemyDynamicWeapon::EnemyDynamicWeapon(GameMap *map_p, Enemy *user, Hero * target, int CD, int damage) :
        Weapon(3, damage, nullptr, map_p), CD(CD), cdn(CD), _user(user), target(target){
    bullet_tot = DYNAMIC_BULLETS_MAX;
    curr_bullet_cnt = 0;
    for(int i = 0; i < bullet_tot; i++){
        bullet_buffer.push_back(nullptr);
    }
}

void EnemyDynamicWeapon::addBullet() {
    if(curr_bullet_cnt >= bullet_tot) {
        return;
    }
    for(auto & space: bullet_buffer){
        if(space == nullptr){
            enableNullSpace(space);
            return;
        } else if(!space->isEnabled()){
            enableUsedSpace(space);
            return;
        }
    }
}

void EnemyDynamicWeapon::enableNullSpace(Bullet *&space) {
    assert(space == nullptr);
    space = new EnemyDynamicBullet(map_parent, target, _user, damage);
    space->enable();
    curr_bullet_cnt ++;
}

void EnemyDynamicWeapon::enableUsedSpace(Bullet *&space) {
    assert(space);
    space->enable();
    curr_bullet_cnt ++;
}

void EnemyDynamicWeapon::tick() {
    if(cdn <= 0){
        addBullet();
        cdn = CD;
    } else {
        cdn --;
    }

    for(auto & each_b : bullet_buffer){
        if(each_b && each_b->isEnabled()){
            try{
                each_b->tick();
            }
            catch (OutOfRange &){
                curr_bullet_cnt --;
            }
            catch (TargetHit &){
                curr_bullet_cnt --;
            }
        }
    }
}
