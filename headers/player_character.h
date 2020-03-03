#ifndef PLAYER_CHARACTER_H_INCLUDED
#define PLAYER_CHARACTER_H_INCLUDED
#include <string.h>
class class_stats{
    public:
        char nume_clasa[10];
        float hp, dmg_r, ad, crit,life_s,crit_dmg = 2,armor_pen = 0;// hp= viata; dmg_r= damage reduction; ad= attack damage; crit= sansa la o lovitura critica; life_s= life steal


};


class player_profile{
    public:
        char nume_player[21],gender;
        int gold=0,skill_points=1,xp=0,level=1,kills=0,deaths=0,potions=0;


};

#endif // PLAYER_CHARACTER_H_INCLUDED
