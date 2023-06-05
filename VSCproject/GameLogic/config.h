//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_CONFIG_H
#define VSCPROJECT_CONFIG_H
#include <vector>
/*------游戏设置信息------*/
#define GAME_WIDTH 1000
#define GAME_HEIGHT 800
#define GAME_TITLE "吸血鬼幸存者"
#define GAME_VERSION "V0.1.0"
#define GAME_RATE 60
#define TIMER_RATE (1000 / GAME_RATE)

extern int SOUL;
extern int LEVEL;
extern int POWER;
extern int SPEED;
extern int LIVE;
extern int INTELLIGENCE;

/*------地图设置信息------*/
#define NUM_OF_MAPS 1
#define MAP_1_NAME "Grass"
#define MAP_1_PATH ":/image/Assets/map1_bg.png"
#define MAP_1_BR ":/image/Assets/map1_br.png"
#define MAP_1_CONFIG "MapConfigs/map1_br.txt"
#define MAP_1_HEIGHT 3000
#define MAP_1_LATTICE_X 30
#define MAP_1_LATTICE_Y 30

/*------玩家角色设置信息--*/
#define NUM_OF_HEROS 2
#define HERO_1_NAME "Link"
#define HERO_1_PATH ":/image/Assets/hero1.png"
#define HERO_1_HEALTH (50 + 40 * LIVE + 10 * POWER)
#define HERO_INIT_EXP 20
#define HERO_1_SPEED (2 + 3 * SPEED + LIVE)
#define HERO_1_REDUCE (0 + 0.01 * LIVE + 0.02 * POWER)

#define HERO_2_HEALTH (40 + 25 * LIVE + 10 * POWER + 5 * SPEED)
#define HERO_2_SPEED (3 + 4 * SPEED + POWER)
#define HERO_2_REDUCE (0 + 0.01 * LIVE)

#define INC_RATE (1.0 + 0.02 * SPEED + 0.02 * POWER + 0.02 * LIVE + 0.05 * INTELLIGENCE)
#define HP_INC_RATE INC_RATE
#define SPEED_INC_RATE INC_RATE
#define WEAPON_INC_RATE INC_RATE

/*------子弹相关设置信息--*/
#define NUM_OF_BULLETS 2
#define DYNAMIC_BULLETS_MAX 30
#define AOE_BULLET_1_PATH ":/image/Assets/aoebullet1.png"
#define AOE_BULLET_1_CD (32 - 2 * SPEED - INTELLIGENCE)

#define BULLET_2_PATH ":/image/Assets/bullet2.svg"
#define BULLET_2_SPEED 10
#define BULLET_2_SIZE 20

#define BULLET_3_PATH ":/image/Assets/enemybullet.png"
#define BULLET_3_SPEED 8
#define BULLET_3_SIZE 15

/*------武器相关设置信息--*/
#define NUM_OF_WEAPONS 1

#define WEAPON_1_NAME "电磁阵"
#define WEAPON_1_DAMAGE (3 + POWER)
#define WEAPON_1_DEFAULT_RANGE (130 + 10 * INTELLIGENCE)
#define WEAPON_1_BULLET_TYPE 1

#define WEAPON_2_DAMAGE (5 + 3 * POWER)
#define WEAPON_2_CD (42 - 2 * SPEED)
#define WEAPON_2_BULLET_TYPE 2

#define E_WEAPON_DAMAGE 5
#define E_WEAPON_CD 60

/*------怪物相关设置信息--*/
#define NUM_OF_ENEMIES 1

#define ENEMY_1_NAME "蝙蝠"
#define ENEMY_1_TYPE NoWeaponEnemy
#define ENEMY_1_POWER 5
#define ENEMY_1_HEALTH 20
#define ENEMY_1_SPEED 6
#define ENEMY_1_CD 60
#define ENEMY_1_PATH ":/image/Assets/pic3.gif"

#define ENEMY_2_NAME "青蛙"
#define ENEMY_2_TYPE NoWeaponEnemyGround
#define ENEMY_2_POWER 10
#define ENEMY_2_HEALTH 30
#define ENEMY_2_SPEED 3
#define ENEMY_2_CD 60
#define ENEMY_2_PATH ":/image/Assets/pic1.gif"

#define ENEMY_3_NAME "飞行炮塔"
#define ENEMY_3_TYPE WeaponEnemy
#define ENEMY_3_HEALTH 20
#define ENEMY_3_SPEED 5
#define ENEMY_3_PATH ":/image/Assets/pic2.gif"


#define EBALL_PATH ":/image/Assets/expball.png"
#define EBALL_SIZE 9
#define EBALL_CD 1200
#define EBALL_MAX 300

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
        {3, {{1,300,120,20,100},
                                    {2,100,120,20,100},
                                    {3,5,300,120,100},
        }},
};



#endif //VSCPROJECT_CONFIG_H
