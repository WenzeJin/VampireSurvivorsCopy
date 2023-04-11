//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_ENEMY_H
#define VSCPROJECT_ENEMY_H
#include "Person.h"
#include "Player.h"

class Enemy : public Person {
    double direction;
    const Player * const target;
public:
    Enemy();
    Enemy(GameState * gs, QWidget * qp, int position_x, int position_y, Player * target);

};


#endif //VSCPROJECT_ENEMY_H
