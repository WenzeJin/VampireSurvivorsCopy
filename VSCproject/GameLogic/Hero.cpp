//
// Created by 金文泽 on 2023/4/18.
//

#include "Hero.h"

Hero::Hero() {
    _image.load(HERO_1_PATH);
    HP_MAX = 100;
    hp = HP_MAX;
    exp = 0;
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
}

Hero::Hero(int hero_style, QWidget *w_parent, GameMap *m_parent) {
    switch(hero_style){
        case 1:
            _image.load(HERO_1_PATH);
            HP_MAX = HERO_1_HEALTH; //TODO:后续这里要改成可以根据文件读写结果调整，实现升级效果
            weapon_type = 1;
            speed = HERO_1_SPEED;
            break;
    }

    hp = HP_MAX;
    exp = 50;
    level = 1;
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
    //TODO:这里以后要适配升级exp更新
    exp_bar->setRange(0, 100);
    exp_bar->setValue(exp);
}

void Hero::setExpBarPosition() {
    exp_bar->setGeometry(150,0,GAME_WIDTH-150,40);
}

void Hero::setHpBarPosition() {
    hp_bar->setGeometry(absolute_pos.first, absolute_pos.second - 20, absolute_rect.width(), 40);
}

void Hero::tick() {
    for(auto key : keys_pressed){
        switch (key) {
            case Qt::Key_W:
                real_pos.second -= speed;
                break;
            case Qt::Key_A:
                real_pos.first -= speed;
                break;
            case Qt::Key_S:
                real_pos.second += speed;
                break;
            case Qt::Key_D:
                real_pos.first += speed;
                break;
            default:
                break;
        }
    }


    map_parent->setAbsolutePos(absolute_pos.first - (int)real_pos.first,
                               absolute_pos.second - (int)real_pos.second);
    _weapon->tick();
}

void Hero::keyPressTick(QKeyEvent *event) {
    if(!event->isAutoRepeat())  //判断如果不是长按时自动触发的按下,就将key值加入容器
        keys_pressed.push_back(event->key());
//    switch(event->key()){
//        case Qt::Key_W:
//            real_pos.second -= speed;
//            break;
//        case Qt::Key_A:
//            real_pos.first -= speed;
//            break;
//        case Qt::Key_S:
//            real_pos.second += speed;
//            break;
//        case Qt::Key_D:
//            real_pos.first += speed;
//            break;
//    }
//    map_parent->setAbsolutePos(absolute_pos.first - (int)real_pos.first,
//                               absolute_pos.second - (int)real_pos.second);
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
    }
}





