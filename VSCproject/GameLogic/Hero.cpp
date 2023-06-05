//
// Created by 金文泽 on 2023/4/18.
//

#include "Hero.h"
#include <cmath>
#include "GameState.h"
#include <iostream>

Hero::Hero() {
    _image.load(HERO_1_PATH);
    HP_MAX = 100;
    hp = HP_MAX;
    exp = 0;
    EXP_MAX = HERO_INIT_EXP;
    speed = 10;
    level = 1;
    widget_parent = nullptr;
    hp_bar = new QProgressBar();
    exp_bar = new QProgressBar();
    QSize pix_size(60,60);
    _image.scaled(pix_size);
    absolute_pos.first = GAME_WIDTH * 0.5 - _image.width()*0.5;
    absolute_pos.second = GAME_HEIGHT * 0.5 - _image.height()*0.5;

    absolute_rect.setWidth(_image.width());
    absolute_rect.setHeight(_image.height());
    absolute_rect.moveTo(absolute_pos.first, absolute_pos.second);

    map_parent = nullptr;
    real_pos.first = 0;
    real_pos.second = 0;
    real_rect.setWidth(_image.width());
    real_rect.setHeight(_image.height());
    real_rect.moveTo((int)real_pos.first,(int)real_pos.second);

    alive = true;

    _weapon = nullptr;
    weapon_type = 1;

    _game = nullptr;
}

Hero::Hero(int hero_style, QWidget *w_parent, GameMap *m_parent) {
    switch(hero_style){
        case 1:
            _image.load(HERO_1_PATH);
            HP_MAX = HERO_1_HEALTH; //TODO:后续这里要改成可以根据文件读写结果调整，实现升级效果
            weapon_type = 1;
            reduce = HERO_1_REDUCE;
            speed = HERO_1_SPEED;
            break;
        case 2:
            _image.load(HERO_1_PATH);
            HP_MAX = HERO_2_HEALTH;
            weapon_type = 2;
            reduce = HERO_2_REDUCE;
            speed = HERO_2_SPEED;
            break;
    }

    hp = HP_MAX;
    exp = 0;
    level = 1;
    EXP_MAX = HERO_INIT_EXP;
    widget_parent = w_parent;
    hp_bar = new QProgressBar();
    exp_bar = new QProgressBar();
    hp_bar->setParent(widget_parent);
    hp_bar->show();
    exp_bar->setParent(widget_parent);
    exp_bar->show();

    QSize pix_size(60,60);
    _image = _image.scaled(pix_size);

    absolute_pos.first = GAME_WIDTH * 0.5 - _image.width()*0.5;
    absolute_pos.second = GAME_HEIGHT * 0.5 - _image.height()*0.5;
    absolute_rect.setWidth(_image.width());
    absolute_rect.setHeight(_image.height());
    absolute_rect.moveTo(absolute_pos.first, absolute_pos.second);

    map_parent = m_parent;
    real_pos.first = map_parent->getPosRangeX() * 0.5 - _image.width()*0.5;
    real_pos.second = map_parent->getPosRangeY() * 0.5 - _image.height()*0.5;
    real_rect.setWidth(_image.width());
    real_rect.setHeight(_image.height());
    real_rect.moveTo((int)real_pos.first,(int)real_pos.second);

    healthChange();
    expChange();
    setHpBarPosition();
    setExpBarPosition();

    alive = true;

    _weapon = nullptr;

    map_parent->setAbsolutePos(absolute_pos.first - (int)real_pos.first,
                               absolute_pos.second - (int)real_pos.second);

    _game = nullptr;
}

void Hero::setWidgetParent(QWidget *parent) {
    widget_parent = parent;
    hp_bar->setParent(widget_parent);
    exp_bar->setParent(widget_parent);
    setHpBarPosition();
    setExpBarPosition();
}

void Hero::healthChange() {
    hp_bar->setRange(0,HP_MAX);
    hp_bar->setValue(hp);
}

void Hero::expChange() {
    exp_bar->setRange(0, EXP_MAX);
    exp_bar->setValue(exp);
}

void Hero::setExpBarPosition() {
    exp_bar->setGeometry(150,0,GAME_WIDTH-150,40);
}

void Hero::setHpBarPosition() {
    hp_bar->setGeometry(absolute_pos.first, absolute_pos.second - 20, absolute_rect.width(), 40);
}

void Hero::tick() {
    double x_bias = 0;
    double y_bias = 0;
    for(auto key : keys_pressed){
        switch (key) {
            case Qt::Key_W:
                y_bias -= 1;
                break;
            case Qt::Key_A:
                x_bias -= 1;
                break;
            case Qt::Key_S:
                y_bias += 1;
                break;
            case Qt::Key_D:
                x_bias += 1;
                break;
            default:
                break;
        }
    }
    double mod = sqrt(x_bias * x_bias + y_bias * y_bias);
    if(mod != 0){
        x_bias /= mod; y_bias /= mod;
    }
    x_bias *= speed;
    y_bias *= speed;

    if(attemptMove(x_bias, 0)){
        real_pos.first += x_bias;
    }
    if(attemptMove(0, y_bias)){
        real_pos.second += y_bias;
    }

    real_rect.moveTo((int)real_pos.first, (int)real_pos.second);
    map_parent->setAbsolutePos(absolute_pos.first - (int)real_pos.first,
                               absolute_pos.second - (int)real_pos.second);
    _weapon->tick();

    exp += _game->countExp(real_pos);
    std::cout << exp << std::endl;
    if(exp >= EXP_MAX){
        waiting_upgrade = true;
    }
    expChange();
}

void Hero::keyPressTick(QKeyEvent *event) {
    if(!event->isAutoRepeat())  //判断如果不是长按时自动触发的按下,就将key值加入容器
        keys_pressed.push_back(event->key());
}

void Hero::keyReleaseTick(QKeyEvent *event) {
    if(!event->isAutoRepeat())  //判断如果不是长按时自动触发的释放,就将key值从容器中删除
        keys_pressed.remove(event->key());
}

std::vector<PaintInfo> Hero::paint() {
    std::vector<PaintInfo> buffer;
    std::vector<PaintInfo> temp;
    temp = _weapon->paint();
    buffer.reserve(temp.size());
    for(auto& item: temp){
        buffer.push_back(item);
    }
    buffer.emplace_back(_image, absolute_pos.first, absolute_pos.second);
    return buffer;
}

void Hero::setRealPosition(double x, double y) {
    real_pos.first = x;
    real_pos.second = y;
    real_rect.moveTo((int)real_pos.first, (int)real_pos.second);
    //TODO：这里之后要加上使地图移动的部分
}

void Hero::giveWeapon() {
    switch(weapon_type){
        case 1:
            _weapon = new HeroStaticAOEWeapon(map_parent, (Hero *)this,
                                              WEAPON_1_DEFAULT_RANGE, (unsigned)WEAPON_1_BULLET_TYPE, WEAPON_1_DAMAGE);
            break;
        case 2:
            _weapon = new HeroDynamicWeapon(map_parent, (Hero *) this, WEAPON_2_CD,
                                            WEAPON_2_BULLET_TYPE, WEAPON_2_DAMAGE);
            break;
    }
}

bool Hero::judgeDamage(Enemy *e) {
    return _weapon->judgeDamage(e);
}

void Hero::damage(int h) {
    if(alive){
        hp -= int(h * (1 - reduce));
        if(hp < 0){
            alive = false;
        }
    }
    healthChange();
}

bool Hero::attemptMove(double x_bias, double y_bias) {
    QRect test(real_rect);
    test.moveTo(int(real_pos.first + x_bias), int(real_pos.second + y_bias));
    if(map_parent->checkPosition(test)){
        init_interact = false;
        return true;
    } else {
        return init_interact;
    }
}

void Hero::upgrade(int type) {
    switch(type){
        case 1: {
            int bias = HP_MAX - hp;
            HP_MAX = (int)((double) HP_MAX * HP_INC_RATE);
            hp = HP_MAX - bias;
            healthChange();
            break;
        }
        case 2:
            speed = (int)((double) speed * SPEED_INC_RATE);
            break;
        case 3:
            _weapon->upgrade();
            break;
    }
    keys_pressed.clear();
    waiting_upgrade = false;
    EXP_MAX *= 2;
    exp = 0;
    level ++;
    expChange();
}





