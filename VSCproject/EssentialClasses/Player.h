//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_PLAYER_H
#define VSCPROJECT_PLAYER_H
#include "Person.h"


class Player : public Person {
    int EXP;
    int level;
    QProgressBar EXP_bar;

public:
    Player();
    Player(GameState * gs, QWidget * qp, int position_x, int position_y);
};


#endif //VSCPROJECT_PLAYER_H
