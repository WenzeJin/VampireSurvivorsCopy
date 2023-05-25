//
// Created by 金文泽 on 2023/4/30.
//

#include "Enemy.h"
#include <cmath>
#include "EnemyController.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Enemy::Enemy(int enemy_style, QWidget *w_parent, EnemyController * controller, GameMap *m_parent, Hero * target, double real_X, double real_Y) {
    QSize pix_size;
    enemy_type = enemy_style;
    switch(enemy_style){
        case 1:
            _image.load(ENEMY_1_PATH);
            HP_MAX = ENEMY_1_HEALTH;
            speed = ENEMY_1_SPEED;
            pix_size.setWidth(40);
            pix_size.setHeight(40);
            break;
    }
    enabled = false;
    alive = false;

    hp = HP_MAX;
    widget_parent = w_parent;
    hp_bar = new QProgressBar();
    hp_bar->setParent(widget_parent);
    hp_bar->hide();

    _image = _image.scaled(pix_size);

    map_parent = m_parent;
    this->target = target;

    real_pos.first = real_X;
    real_pos.second = real_Y;
    real_rect.setWidth(_image.width());
    real_rect.setHeight(_image.height());
    real_rect.moveTo((int)real_pos.first,(int)real_pos.second);

    absolute_pos.first = (int)real_pos.first + m_parent->getAbsoluteX();
    absolute_pos.second = (int)real_pos.second + m_parent->getAbsoluteY();
    absolute_rect.setWidth(_image.width());
    absolute_rect.setHeight(_image.height());
    absolute_rect.moveTo(absolute_pos.first, absolute_pos.second);

    healthChange();
    setHpBarPosition();

    this->controller = controller;
}

PaintInfo Enemy::paint() {
    return {_image, absolute_pos.first, absolute_pos.second};
}

void Enemy::setRealPosition(double x, double y) {
    real_pos.first = x;
    real_pos.second = y;
    real_rect.moveTo((int)real_pos.first,(int)real_pos.second);

    absolute_pos.first = (int)real_pos.first + map_parent->getAbsoluteX();
    absolute_pos.second = (int)real_pos.second + map_parent->getAbsoluteY();
    absolute_rect.moveTo(absolute_pos.first, absolute_pos.second);
    setHpBarPosition();
}

void Enemy::damage(int d) {
    if(alive){
        hp -= d;
        hp_bar->show();
        healthChange();
        if(hp <= 0)
            die();
    }
}

void Enemy::die() {
    alive = false;
    disable();
    if(controller)
        controller->reportDeath(enemy_type);
}

void Enemy::enable(){
    alive = true;
    enabled = true;
    hp = HP_MAX;
    hp_bar->show();
    setHpBarPosition();
    healthChange();
    hp_bar->hide();
}

void Enemy::disable() {
    enabled = false;
    hp_bar->hide();
}

void Enemy::healthChange() {
    hp_bar->setRange(0,HP_MAX);
    hp_bar->setValue(hp);
}

void Enemy::setHpBarPosition() {
    hp_bar->setGeometry(absolute_pos.first, absolute_pos.second - 20, absolute_rect.width(), 40);
}

NoWeaponEnemy::NoWeaponEnemy(int enemy_style, QWidget *w_parent, EnemyController * controller, GameMap *m_parent, Hero *target,
                             double real_X, double real_Y) :
                             Enemy(enemy_style, w_parent,controller , m_parent, target, real_X, real_Y) {
    switch(enemy_style){
        case 1:
            power = ENEMY_1_POWER;
            CD = ENEMY_1_CD;
    }
    cdn = CD;
}

bool NoWeaponEnemy::judgeDamage() {
    if(cdn > 0){
        cdn --;
        return false;
    } else {
        cdn = CD;
    }
    if(real_rect.intersects(target->real_rect)){
        target->damage(power);
        return true;
    } else {
        return false;
    }
}

void NoWeaponEnemy::tick() {
    auto direction = getDirectionVector();
    double bias = (rand() % speed) * 0.6;
    direction.first *= speed;
    direction.second *= speed;
    direction.first += bias;
    direction.second += bias;
    setRealPosition(real_pos.first + direction.first,
                    real_pos.second + direction.second );
    judgeDamage();
}

std::pair<double, double> NoWeaponEnemy::getDirectionVector() {
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
