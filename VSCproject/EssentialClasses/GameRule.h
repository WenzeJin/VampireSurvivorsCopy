//
// Created by 金文泽 on 2023/4/10.
//

#ifndef VSCPROJECT_GAMERULE_H
#define VSCPROJECT_GAMERULE_H


class GameRule {
public:
    enum PlayerCategories {};
    enum MapCategories {};
    enum EnemyCategories {};
    enum BulletCategories {};
    enum WeaponCategories {};

    static int judgeExp(int level);
};


#endif //VSCPROJECT_GAMERULE_H
