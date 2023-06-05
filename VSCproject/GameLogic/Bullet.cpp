//
// Created by 金文泽 on 2023/4/30.
//

#include "Bullet.h"
#include "Enemy.h"
#include "Hero.h"
#include "GameState.h"
#include <cmath>
#include <iostream>

void Bullet::setRealPosition(double x, double y) {
    real_pos.first = x;
    real_pos.second = y;
    absolute_pos.first = map_parent->getAbsoluteX() + (int)real_pos.first;
    absolute_pos.second = map_parent->getAbsoluteY() + (int)real_pos.second;
}

Bullet::Bullet(unsigned int bullet_style, int damage, GameMap * map_p) :
bullet_style(bullet_style), damage(damage), map_parent(map_p){
    switch(bullet_style){
        case 1:
            _image.load(AOE_BULLET_1_PATH);
            break;
        case 2:
            _image.load(BULLET_2_PATH);
            break;
        case 3:
            _image.load(BULLET_3_PATH);
            break;
    }
}

PaintInfo Bullet::paint() {
    return {_image, absolute_pos.first, absolute_pos.second};
}

HeroStaticAOEBullet::HeroStaticAOEBullet(GameMap *map_parent, Hero *user, int range,
                                         unsigned int bullet_style,int damage) :
        Bullet(bullet_style, damage, map_parent),
        user(user), range(range){
    switch(bullet_style){
        case 1:
            CD = AOE_BULLET_1_CD;
    }
    cds = CD;
    center_real_pos.first = user->getRealX() + user->real_rect.width() * 0.5;
    center_real_pos.second = user->getRealY() + user->real_rect.height() * 0.5;
    real_pos.first = center_real_pos.first - range;
    real_pos.second = center_real_pos.second - range;
    absolute_pos.first = user->getAbsoluteX() + user->absolute_rect.width() / 2 - range;
    absolute_pos.second = user->getAbsoluteY() + user->absolute_rect.height() / 2 - range;
    _image = _image.scaled(2 * range, 2 * range);
}

void HeroStaticAOEBullet::tick() {
    if(isEnabled()) {
        update_pos();
        -- cds;
        if(cds < 0){
            cds = CD;
        }
    }
}

bool HeroStaticAOEBullet::judge_damage(Enemy * e) {
    if(cds > 0){
        return false;
    }
    if(!e || !e->isEnabled()){
        return false;
    }
    std::pair<double, double> enemy_real_center;
    enemy_real_center.first = e->getRealX() + e->real_rect.width() * 0.5;
    enemy_real_center.second = e->getRealY() + e->real_rect.height() * 0.5;
    double delta_x = abs(enemy_real_center.first - center_real_pos.first);
    double delta_y = abs(enemy_real_center.second - center_real_pos.second);
    if(delta_x <= range || delta_y <= range){
        double r = sqrt(delta_x * delta_x + delta_y * delta_y);
        if(r <= range){
            e->damage(damage);
            return true;
        }
    }
    return false;
}

void HeroStaticAOEBullet::update_pos() {
    center_real_pos.first = user->getRealX() + user->real_rect.width() * 0.5;
    center_real_pos.second = user->getRealY() + user->real_rect.height() * 0.5;
    real_pos.first = center_real_pos.first - range;
    real_pos.second = center_real_pos.second - range;
    absolute_pos.first = user->getAbsoluteX() + user->absolute_rect.width() / 2 - range;
    absolute_pos.second = user->getAbsoluteY() + user->absolute_rect.height() / 2 - range;
}

HeroDynamicBullet::HeroDynamicBullet(GameMap *map_parent, Hero * user, Enemy *target,
                                     unsigned int bullet_style, int damage) :
        Bullet(bullet_style, damage, map_parent), target(target), user(user){
    switch(bullet_style){
        case 2:
            speed = BULLET_2_SPEED;
            _image = _image.scaled(BULLET_2_SIZE, BULLET_2_SIZE);
    }
    real_pos.first = user->getRealX();
    real_pos.second = user->getRealY();
    _image = _image.scaled(20,20);
    real_rect.moveTo((int)real_pos.first, (int)real_pos.second);
    real_rect.setWidth(20); real_rect.setHeight(20);
    absolute_pos.first = map_parent->getAbsoluteX() + (int)real_pos.first;
    absolute_pos.second = map_parent->getAbsoluteY() + (int)real_pos.second;

}

void HeroDynamicBullet::tick() {
    if(isEnabled()){
        if(!target->isEnabled()){
            disable();
            throw TargetLossError(0);
        }
        if(judge_damage(target)){
            disable();
            throw TargetHit(0);
        } else {
            std::pair<double, double> direction = getDirectionVector();
            direction.first *= speed;
            direction.second *= speed;
            setRealPosition(real_pos.first + direction.first, real_pos.second + direction.second);
        }
    }
}

std::pair<double, double> HeroDynamicBullet::getDirectionVector() {
    std::pair<double, double> temp;
    temp.first = target->getRealX() - real_pos.first;
    temp.second = target->getRealY() - real_pos.second;
    if(abs(temp.first) < speed / 2.0 && abs(temp.second) < speed / 2.0){
        return {0,0};
    }
    double mod = sqrt(temp.first * temp.first + temp.second * temp.second);
    temp.first /= mod;
    temp.second /= mod;
    return temp;
}

bool HeroDynamicBullet::judge_damage(Enemy * e) {
    if(e && real_rect.intersects(e->real_rect)){
        e->damage(damage);
        return true;
    } else { return false; }
}

void HeroDynamicBullet::setRealPosition(double x, double y) {
    Bullet::setRealPosition(x, y);
    real_rect.moveTo((int)real_pos.first, (int)real_pos.second);
}

void HeroDynamicBullet::enable(Enemy *e) {
    Bullet::enable(e);
    std::cout << "子弹被启用 " << isEnabled() << std::endl;
    target = e;
    setRealPosition(user->getRealX(), user->getRealY());
}

EnemyDynamicBullet::EnemyDynamicBullet(GameMap *map_parent, Hero *target, Enemy *user, int damage) :
        Bullet(3, damage, map_parent), target(target), user(user){
    speed = BULLET_3_SPEED;
    _image = _image.scaled(BULLET_3_SIZE, BULLET_3_SIZE);
    real_pos.first = user->getRealX();
    real_pos.second = user->getRealY();
    _image = _image.scaled(20,20);
    real_rect.moveTo((int)real_pos.first, (int)real_pos.second);
    real_rect.setWidth(20); real_rect.setHeight(20);
    absolute_pos.first = map_parent->getAbsoluteX() + (int)real_pos.first;
    absolute_pos.second = map_parent->getAbsoluteY() + (int)real_pos.second;

    std::pair<double, double> temp;
    temp.first = target->getRealX() - real_pos.first;
    temp.second = target->getRealY() - real_pos.second;
    if(temp.first == 0){
        temp.first = 0.1;
    }
    if(temp.second == 0){
        temp.second = 0.1;
    }
    double mod = sqrt(temp.first * temp.first + temp.second * temp.second);
    temp.first /= mod;
    temp.second /= mod;
    direction_vector = temp;
}

void EnemyDynamicBullet::setRealPosition(double x, double y) {
    Bullet::setRealPosition(x, y);
    real_rect.moveTo((int)real_pos.first, (int)real_pos.second);
}

void EnemyDynamicBullet::enable() {
    Bullet::enable();
    setRealPosition(user->getRealX(), user->getRealY());
    std::pair<double, double> temp;
    temp.first = target->getRealX() - real_pos.first;
    temp.second = target->getRealY() - real_pos.second;
    double mod = sqrt(temp.first * temp.first + temp.second * temp.second);
    temp.first /= mod;
    temp.second /= mod;
    direction_vector = temp;
}

bool EnemyDynamicBullet::judge_damage(Hero *e) {
    if(e && real_rect.intersects(e->real_rect)){
        e->damage(damage);
        return true;
    } else { return false; }
}

void EnemyDynamicBullet::tick() {
    if(isEnabled()){
        if(judge_damage(target)){
            disable();
            throw TargetHit(0);
        } else {
            std::pair<double, double> direction = direction_vector;
            direction.first *= speed;
            direction.second *= speed;
            setRealPosition(real_pos.first + direction.first, real_pos.second + direction.second);
            if(real_pos.first > map_parent->getPosRangeX() ||
                    real_pos.first < 0 ||
                    real_pos.second > map_parent->getPosRangeY() ||
                    real_pos.second < 0){
                disable();
                throw OutOfRange(0);
            }
        }
    }
}
