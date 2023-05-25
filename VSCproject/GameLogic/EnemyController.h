//
// Created by 金文泽 on 2023/5/7.
//

#ifndef VSCPROJECT_ENEMYCONTROLLER_H
#define VSCPROJECT_ENEMYCONTROLLER_H
#include <vector>

class GameState;
class Enemy;

class EnemyController {
    GameState * game;
    int game_stage;
    int type_num;
    int enemy_death_cnt;

    struct TypeController{
        int enemy_type;
        int max_nums;
        int num_counters;
        int max_cds;
        int cds;
        int min_cds;
        int reduce_cds;
        int reduce_counters;
        int vector_pos;
    };
    std::vector<TypeController> types;

public:
    EnemyController(GameState * g, int stage);

    void tick();

    void reportDeath(int type);

    [[nodiscard]] int getEnemyDeathCnt() const { return enemy_death_cnt; }

private:

    void addEnemy(int enemy_type, std::vector<Enemy *> &buffer);

    void enableNullSpace(int enemy_type, Enemy * & space);
    void enableUsedSpace(int enemy_type, Enemy * & space);

    std::pair<double, double> generatePosition();

};


#endif //VSCPROJECT_ENEMYCONTROLLER_H
