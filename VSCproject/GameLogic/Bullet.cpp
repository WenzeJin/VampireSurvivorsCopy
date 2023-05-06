//
// Created by 金文泽 on 2023/4/30.
//

#include "Bullet.h"

void Bullet::setRealPosition(int x, int y) {
    real_pos.first = x;
    real_pos.second = y;
}

Bullet::Bullet(unsigned int bullet_style, int damage, GameMap * map_p) :
bullet_style(bullet_style), damage(damage), map_parent(map_p){
    switch(bullet_style){
        case 1:
            _image.load(AOE_BULLET_1_PATH);
    }
}

PaintInfo Bullet::paint() {
    return {_image, absolute_pos.first, absolute_pos.second};
}

HeroStaticAOEBullet::HeroStaticAOEBullet(GameMap *map_parent, Hero *user, int range,
                                         unsigned int bullet_style,int damage) :
        Bullet(bullet_style, damage, map_parent),
        user(user), range(range){
    center_real_pos.first = user->getRealX() + user->real_rect.width() * 0.5;
    center_real_pos.second = user->getRealY() + user->real_rect.height() * 0.5;
    real_pos.first = center_real_pos.first - range;
    real_pos.second = center_real_pos.second - range;
    absolute_pos.first = user->getAbsoluteX() + user->absolute_rect.width() / 2 - range;
    absolute_pos.second = user->getAbsoluteY() + user->absolute_rect.height() / 2 - range;
    _image = _image.scaled(2 * range, 2 * range);
}

void HeroStaticAOEBullet::tick() {
    update_pos();
    //TODO:伤害待做
}

bool HeroStaticAOEBullet::judge_damage(Enemy *) {
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
