//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_PERSON_H
#define VSCPROJECT_PERSON_H
#include <QLabel>
#include <QWidget>
#include <QProgressBar>
#include "Weapon.h"
#include "GameState.h"
#include "GameRule.h"


class Person {
    int HP;
    int position[2];
    bool alive;
    Weapon weapon;
    QLabel label;
    QProgressBar HP_bar;
    const QWidget * parent;
    GameState * const GS;
    GameRule * const GR;
    GameRule::WeaponCategories weapon_cate;

public:
    static int max_HP;
    Person();
    Person(GameState * gs, QWidget * qp, int position_x, int position_y);

    void tick();
    void damage();

};


#endif //VSCPROJECT_PERSON_H
