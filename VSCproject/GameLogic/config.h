//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_CONFIG_H
#define VSCPROJECT_CONFIG_H
#include <vector>
//TODO：后续尽量都改成结构体
/*------游戏设置信息------*/
#define GAME_WIDTH 1000
#define GAME_HEIGHT 800
#define GAME_TITLE "吸血鬼幸存者"
#define GAME_VERSION "V0.0.1"
#define GAME_RATE 60
#define TIMER_RATE (1000 / GAME_RATE)

/*------地图设置信息------*/
#define NUM_OF_MAPS 1
#define MAP_1_NAME "Grass"
#define MAP_1_PATH ":/image/Assets/map1_bg.png"
#define MAP_1_HEIGHT 3000

/*------玩家角色设置信息--*/
#define NUM_OF_HEROS 1
#define HERO_1_NAME "Unsilence"
#define HERO_1_PATH ":/image/Assets/hero1.png"
#define HERO_1_HEALTH 100
#define HERO_1_SPEED 6

/*------子弹相关设置信息--*/
#define NUM_OF_BULLETS 1
#define AOE_BULLET_1_PATH ":/image/Assets/aoebullet1.png"

/*------武器相关设置信息--*/
#define NUM_OF_WEAPONS 1

#define WEAPON_1_NAME "电磁阵"
#define WEAPON_1_DAMAGE 10
#define WEAPON_1_DEFAULT_RANGE 150
#define WEAPON_1_BULLET_TYPE 1

/*------怪物相关设置信息--*/
#define NUM_OF_ENEMIES 1

#define ENEMY_1_NAME "青蛙"
#define ENEMY_1_TYPE NoWeaponEnemy
#define ENEMY_1_POWER 10
#define ENEMY_1_HEALTH 30
#define ENEMY_1_SPEED 3
#define ENEMY_1_PATH ":/image/Assets/pic1.gif"

/*-----难度相关设置------*/
#define NUM_OF_STAGES 1


struct StageInfo{
    int type_num;
    struct TypeInfo{
        int enemy_type;
        int max_nums;
        int cd_max;
        int cd_min;
        int reduce_rate;
    };
    std::vector<TypeInfo> type_info;
};

const StageInfo STAGE_INFOS[NUM_OF_STAGES] = {
        {1, {{1,50,240,60,100}}},
};



#endif //VSCPROJECT_CONFIG_H
