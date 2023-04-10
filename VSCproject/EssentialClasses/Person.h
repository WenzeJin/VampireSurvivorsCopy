//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_PERSON_H
#define VSCPROJECT_PERSON_H
#include <QLabel>
#include <QWidget>
#include <QProgressBar>
#include "Weapon.h"


class Person {
    int HP;
    int position[2];
    bool alive;
    Weapon weapon;
    QLabel label;
    QProgressBar HP_bar;
    const QWidget * parent;

public:
    
};


#endif //VSCPROJECT_PERSON_H
