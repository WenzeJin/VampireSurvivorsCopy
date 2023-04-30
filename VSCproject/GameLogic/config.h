//
// Created by 金文泽 on 2023/4/18.
//

#ifndef VSCPROJECT_CONFIG_H
#define VSCPROJECT_CONFIG_H
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

#endif //VSCPROJECT_CONFIG_H
