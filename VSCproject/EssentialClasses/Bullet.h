//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_BULLET_H
#define VSCPROJECT_BULLET_H
#include "Person.h"
#include <QLabel>
#include <QWidget>


class Bullet {
    const Person &shooter;
    const Person &target;
    unsigned speed;
    int position[2];
    QLabel label;
    const QWidget * QW_parent;

public:
    Bullet();
    void set_parent(const QWidget * p);

    void tick();    //进行一个tick
};


#endif //VSCPROJECT_BULLET_H
