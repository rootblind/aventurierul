#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include "utility.h"


void afisare_combat_hp(class_stats stats,class_stats stats_total,class_stats inamic,class_stats creep_t)
{
    cout<<endl<<"====================";
    cout<<"\nTu: \nHP:"<<stats.hp<<"/"<<stats_total.hp;
    cout<<"\nAD: "<<stats.ad;
    cout<<"\nDMGr: "<<stats.dmg_r * 100<<"%";
    cout<<"\nInamicul: \nHP:"<<inamic.hp<<"/"<<creep_t.hp;
    cout<<"\nAD: "<<inamic.ad;
    cout<<"\nDMGr: "<<inamic.dmg_r * 100<<"%";
    cout<<endl<<"===================="<<endl;
}

void win_lose(player_profile &profile,unsigned win,int xp,int gold,class_stats &stats_total,class_stats &stats)
{
    system("cls");
    if(win == 0)
    {
        cout<<"Ai murit! D:";
        cout<<"\nPenalizarea: -50G";
        profile.gold -= 50;
        profile.deaths++;
        next();
    }
    else
    {
        cout<<"Ai invins!";
        cout<<"\nRecompensa: +"<<xp<<"xp | +"<<gold<<"G";
        levelup(xp,profile,stats_total,stats);
        profile.gold += gold;
        profile.kills++;
        next();
    }
    stats = stats_total;
}

void abilitate1(class_stats &stats,player_profile profile,unsigned &cooldown,class_stats &inamic,unsigned &turn,class_stats stats_total,class_stats creep_t)
{
    unsigned clasa;
    if(strcmp(stats.nume_clasa,"Tank") == 0)
        clasa = 0;
    else
        if(strstr(stats.nume_clasa,"Bruiser"))
            clasa = 1;
            if(strstr(stats.nume_clasa,"Teemo"))
                clasa = 2;
                else
                    if(strstr(stats.nume_clasa,"Varus"))
                    clasa = 3;
                else
                    if(strstr(stats.nume_clasa,"Morde"))
                    clasa = 4;
                else
                    if(strstr(stats.nume_clasa,"Rhaast"))
                    clasa = 5;
                else
                    if(strstr(stats.nume_clasa,"Aatrox"))
                    clasa = 6;
                else
                    if(strstr(stats.nume_clasa,"Assassin"))
                    clasa = 7;

    switch(clasa)
    {
    case 0:
        inamic.hp -= ((stats.dmg_r * 200 + 5 * profile.skill_points + stats.ad) - (stats.dmg_r * 200 + 5 * profile.skill_points + stats.ad) * inamic.dmg_r);
        cout<<"\nAi dat "<<(stats.dmg_r * 200 + 5 * profile.skill_points + stats.ad) - (stats.dmg_r * 200 + 5 * profile.skill_points +  stats.ad) * inamic.dmg_r<<" normal damage!";
        cooldown = 3;
        turn = 1;
        break;
    case 1:
        {int crit = rand() % 100;
        if(crit && crit <= stats.crit * 100)
        {
            if(stats.hp <= stats_total.hp * 0.3 + 1)
        {
            stats.hp += (((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * stats.crit_dmg) * (0.6 + stats.life_s);
            cout<<"\n+"<<(((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * stats.crit_dmg) * (0.6 + stats.life_s)<<"HP";
        }
        stats.hp += (((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * stats.crit_dmg) * stats.life_s;
        inamic.hp -= ((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * stats.crit_dmg;
        cout<<"\nAi dat "<<((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * stats.crit_dmg<<" CRIT normal damage!";
        }
        else
        {
            if(stats.hp <= stats_total.hp * 0.3 + 1)
        {
            stats.hp += ((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * 0.6;
            cout<<"\n+"<<((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * (stats.life_s + 0.6)<<"HP";
        }
        stats.hp += ((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r) * stats.life_s;
        inamic.hp -= ((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r);
        cout<<"\nAi dat "<<((10 * profile.skill_points + stats.ad * 1) - (10 * profile.skill_points + stats.ad * 1) * inamic.dmg_r)<<" normal damage!";
        }

        cooldown = 2;
        turn = 1;
        break;}
    case 2:
        {
            inamic.hp -= ((260 + 0.8 * stats.ad) - (260 + 0.8 * stats.ad) * inamic.dmg_r);
            cout<<"\nDevil teemo a dat "<<(260 + 0.8 * stats.ad) - (260 + 0.8 * stats.ad) * inamic.dmg_r<<" normal damage!";
            cout<<"\nEsti sub efect de ametire!";
            cooldown = 2;
        }
        break;
    case 3:
        inamic.dmg_r -= inamic.dmg_r * 0.02;
        stats.life_s += 0.01;
        stats.crit += 0.05;
        stats.dmg_r -= 0.01;
        cout<<"\nVarus pierde 1% din armura sa pentru a primi: +2% Armor pen, +1% Life Steal si +5% Crit";
        cooldown = 2;
        break;
    case 4:
        inamic.hp -= ((300 + 0.03 * creep_t.hp) - (300 + 0.03 * creep_t.hp) * inamic.dmg_r);
        cout<<"\nMordekaiser a dat "<<((300 + 0.03 * creep_t.hp) - (300 + 0.03 * creep_t.hp) * inamic.dmg_r)<<" normal damage!";
        cooldown = 1;
        turn = 0;
        break;
    case 5:
        inamic.hp -= ((stats.ad * 1.3 + 270) - (stats.ad * 1.3 + 270) * inamic.dmg_r);
        stats.hp += ((stats.ad * 1.3 + 270) - (stats.ad * 1.3 + 270) * inamic.dmg_r);
        cout<<"\nRhaast a dat "<<((stats.ad * 1.3 + 270) - (stats.ad * 1.3 + 270) * inamic.dmg_r)<<" normal damage si s-a vindecat cu aceeasi valoare de HP";
        cooldown = 5;
        turn = 0;
        break;
    case 6:
        {int crits = rand() % 100;
        if(crits && crits <= stats.crit * 100)
        {
            inamic.hp -= ((200 + stats.ad * 1.2) - (200 + stats.ad * 1.2) * inamic.dmg_r) * stats.crit_dmg;
            cout<<"\nAatrox a dat dat "<<((200 + stats.ad * 1.2) - (200 + stats.ad * 1.2) * inamic.dmg_r) * stats.crit_dmg<<" CRIT normal damage!";
            stats.hp += stats.life_s * ((200 + stats.ad * 1.2) - (200 + stats.ad * 1.2) * inamic.dmg_r) * stats.crit_dmg;
        }
        else
        {
            inamic.hp -= ((100 + stats.ad) - (100 + stats.ad) * inamic.dmg_r);
            cout<<"\nAatrox a dat "<<((100 + stats.ad) - (100 + stats.ad) * inamic.dmg_r)<<" normal damage!";
            stats.hp += stats.life_s * ((100 + stats.ad) - (100 + stats.ad) * inamic.dmg_r);
        }
        cooldown = 1;
        turn = 0;}
        break;
    case 7:
        if(inamic.hp >= creep_t.hp * 0.5)
        {
            inamic.hp -= ((65 + 20 * profile.skill_points + 0.9 * stats.ad) - (65 + 20 * profile.skill_points + 0.9 * stats.ad) * inamic.dmg_r);
            cout<<"\nAi dat "<<((65 + 20 * profile.skill_points + 0.9 * stats.ad) - (65 + 20 * profile.skill_points + 0.9 * stats.ad) * inamic.dmg_r)<<" normal damage!";
        }
        else
        {
            inamic.hp -= ((65 + 20 * profile.skill_points + 0.9 * stats.ad) - (65 + 20 * profile.skill_points + 0.9 * stats.ad) * inamic.dmg_r) * stats.crit_dmg;
            cout<<"\nAi dat "<<((65 + 20 * profile.skill_points + 0.9 * stats.ad) - (65 + 20 * profile.skill_points + 0.9 * stats.ad) * inamic.dmg_r) * stats.crit<<" crit normal damage!";
        }
        cooldown = 3;
        turn = 1;
        break;

    }
}

void abilitate2(class_stats &stats,player_profile profile,unsigned &cooldown,class_stats &inamic,unsigned &turn,class_stats creep_t,class_stats stats_total)
{
    unsigned clasa;
    if(strcmp(stats.nume_clasa,"Tank") == 0)
        clasa = 0;
    else
        if(strstr(stats.nume_clasa,"Bruiser"))
            clasa = 1;
            if(strstr(stats.nume_clasa,"Teemo"))
                clasa = 2;
                else
                    if(strstr(stats.nume_clasa,"Varus"))
                    clasa = 3;
                else
                    if(strstr(stats.nume_clasa,"Morde"))
                    clasa = 4;
                else
                    if(strstr(stats.nume_clasa,"Rhaast"))
                    clasa = 5;
                else
                    if(strstr(stats.nume_clasa,"Aatrox"))
                    clasa = 6;
                else
                    if(strstr(stats.nume_clasa,"Assassin"))
                    clasa = 7;
    switch(clasa)
    {
    case 0:
        inamic.hp -= ((40 + 10 * profile.skill_points + stats.dmg_r * 200) - (40 + 10 * profile.skill_points + stats.dmg_r * 200) * inamic.dmg_r);
        cout<<"\nAi dat "<<(40 + 10 * profile.skill_points + stats.dmg_r * 200) - (40 + 10 * profile.skill_points + stats.dmg_r * 200) * inamic.dmg_r<<" normal damage!";
        cout<<"\nInamicul este sub efect de ametire pentru o tura!";
        cooldown = 6;
        break;
    case 1:
        if(stats.hp <= stats_total.hp * 0.3 + 1)
        {
            inamic.hp -= (40 + 5 * profile.skill_points + stats.ad * 1 + 0.2 * (creep_t.hp - inamic.hp));
            cout<<"\nAi dat "<<(40 + 5 * profile.skill_points + stats.ad * 1)<<" magic damage!";
            cooldown = 2;
        }
        else
        {
            inamic.hp -= ((50 + 5 * profile.skill_points + stats.ad * 0.3) - (50 + 5 * profile.skill_points + stats.ad * 0.3) * inamic.dmg_r);
            cout<<"\nAi dat "<<((50 + 5 * profile.skill_points + stats.ad * 0.3) - (50 + 5 * profile.skill_points + stats.ad * 0.3) * inamic.dmg_r)<<" normal damage!";
            cooldown = 4;
        }
        turn = 1;
        break;
    case 2:
        {
            if(inamic.hp >= creep_t.hp * 0.5)
                {
                    cout<<"\nDevil Teemo a dat "<<(stats.ad * 0.7 + profile.level * 20 + (creep_t.hp - inamic.hp) * 0.1) - (stats.ad * 0.7 + profile.level * 20 + (creep_t.hp - inamic.hp) * 0.1) * inamic.dmg_r<<" normal damage";
                    inamic.hp -= (profile.level * 20 + (creep_t.hp - inamic.hp) * 0.1);
                }
                else
                {
                    cout<<"\nDevil Teemo a dat "<<stats.ad * 0.7 + profile.level * 20 + (creep_t.hp - inamic.hp) * 0.2<<" Magic damage!";
                    inamic.hp -= (stats.ad * 0.7 +  profile.level * 20 + (creep_t.hp - inamic.hp) * 0.2);
                }
            cooldown = 3;
            turn = 0;
        }
        break;
    case 3:
        stats.ad += 0.1 * (stats_total.hp - stats.hp);
        cout<<"\nVarus isi creste AD-ul in functie de viata lipsa!";
        cooldown = 2;
        break;
    case 4:
        cout<<"\nMordekaiser si-a refacut "<<(stats_total.hp - stats.hp) * 0.25<<"HP!";
        stats.hp += (stats_total.hp - stats.hp) * 0.25;
        cooldown = 4;
        break;
    case 5:
        cout<<"Rhaast si-a consumat "<<stats.hp * 0.2<<"HP pentru a primi "<<stats.hp * 0.1<<" AD!";
        stats.ad += stats.hp * 0.1;
        stats.hp -= stats.hp * 0.2;
        cooldown = 4;
        turn = 0;
        break;
    case 6:
        cout<<"\nAatrox primeste +30% Life Steal si 5% Armor Pen";
        stats.life_s += 0.3;
        inamic.dmg_r -= inamic.dmg_r * 0.05;
        cooldown = 5;
        break;
    case 7:
        {int crit = rand() % 100;
        if(crit && crit <= stats.crit * 100)
        {
            inamic.hp -= (stats.ad - stats.ad * inamic.dmg_r) * stats.crit_dmg;
            stats.hp += (stats.ad - stats.ad * inamic.dmg_r) * stats.crit_dmg * stats.life_s;
            cout<<"\nAi dat "<<(stats.ad - stats.ad * inamic.dmg_r) * stats.crit_dmg<<" crit damage!";
        }
        else
        {
            inamic.hp -= (stats.ad - stats.ad * inamic.dmg_r);
            stats.hp += (stats.ad - stats.ad * inamic.dmg_r) * stats.life_s;
            cout<<"\nAi dat "<<(stats.ad - stats.ad * inamic.dmg_r)<<" normal damage!";
        }
        if(inamic.hp >= creep_t.hp * 0.5)
        {
            cout<<"\nInamicul pierde 5% din armura sa!";
            inamic.dmg_r -= inamic.dmg_r * 0.05;
        }
        else
        {
            cout<<"\nInamicul pierde 10% din armura sa!";
            inamic.dmg_r -= inamic.dmg_r * 0.1;
        }
        cooldown = 4;
        turn = 1;
        break;}
    }
}

void ultimata(class_stats &stats,player_profile profile,unsigned &cooldown,class_stats &inamic,unsigned &turn,class_stats creep_t,class_stats stats_total)
{
    unsigned clasa;
    if(strcmp(stats.nume_clasa,"Tank") == 0)
        clasa = 0;
    else
        if(strstr(stats.nume_clasa,"Bruiser"))
            clasa = 1;
            else
            if(strstr(stats.nume_clasa,"Teemo"))
                clasa = 2;
                else
                    if(strstr(stats.nume_clasa,"Varus"))
                    clasa = 3;
                else
                    if(strstr(stats.nume_clasa,"Morde"))
                    clasa = 4;
                else
                    if(strstr(stats.nume_clasa,"Rhaast"))
                    clasa = 5;
                else
                    if(strstr(stats.nume_clasa,"Aatrox"))
                    clasa = 6;
                else
                    if(strstr(stats.nume_clasa,"Assassin"))
                    clasa = 7;
    switch(clasa)
    {
    case 0:
        cout<<"\nAi furat "<<40 + 0.2 * (creep_t.hp - inamic.hp)<<" viata, dand "<<inamic.hp * 0.1<<" magic damage!";

        stats.hp += stats.dmg_r * 50 + 0.2 * (creep_t.hp - inamic.hp) + 10 * profile.skill_points;
        inamic.hp -= inamic.hp * 0.1;
        stats.dmg_r -= 0.1;
        inamic.dmg_r -= 0.1;
        cout<<"\nTu si inamicul pierdeti 10% din rezistente: tu - "<<stats.dmg_r * 100<<"%  inamicul - "<<inamic.dmg_r * 100<<"%";
        cooldown = 1;
        turn = 1;
        break;
    case 1:
        if(stats.hp <= stats_total.hp * 0.3 + 1)
        {
            cout<<"\n+"<<(stats_total.hp - stats.hp) * 0.35 + profile.skill_points<<"AD";
            stats.ad += (stats_total.hp - stats.hp) * 0.35 + profile.skill_points;
            stats.life_s += stats.dmg_r + inamic.dmg_r;
            cout<<"\nLife Steal: "<<stats.life_s * 100<<"%";
            stats.dmg_r = -0.2;
            cout<<"\nDmgr: "<<stats.dmg_r * 100<<"%";
            cooldown = 1;
        }
        else
            cout<<"Trebuie sa fii sub "<<stats_total.hp * 0.3<<" pentru a folosi ultimata!  ";


        break;
    case 2:
        cout<<"\nDevil Teemo a dat "<<(200 + creep_t.hp * 0.2) - (200 + creep_t.hp * 0.2) * inamic.dmg_r<<" normal damage!";
        cout<<"\nPierzi 5% din armura!";
        inamic.hp -= ((200 + creep_t.hp * 0.2) - (200 + creep_t.hp * 0.2) * inamic.dmg_r);
        inamic.dmg_r -= 0.05;
        cooldown = 1;
        turn = 0;
        break;
    case 3:
        cout<<"\Varus a dat "<<((300 + (creep_t.hp - inamic.hp) * 0.15 + stats.crit * 300) - (300 + (creep_t.hp - inamic.hp) * 0.15 + stats.crit * 300) * inamic.dmg_r)<<" normal damage!";
        inamic.hp -= ((300 + (creep_t.hp - inamic.hp) * 0.15 + stats.crit * 300) - (300 + (creep_t.hp - inamic.hp) * 0.15 + stats.crit * 300) * inamic.dmg_r);
        cooldown = 1;
        turn = 0;
        break;
    case 4:
        cout<<"\nMordekaiser te-a teleportat in \"Shadow Realm\"!";
        stats.ad += inamic.ad * 0.1;
        inamic.ad -= inamic.ad * 0.1;
        stats.hp += inamic.hp * 0.1;
        inamic.hp -= inamic.hp * 0.1;
        stats.dmg_r += inamic.dmg_r * 0.1;
        inamic.dmg_r -= inamic.dmg_r * 0.1;
        cooldown = 1;
        turn = 0;
        break;
    case 5:
        cout<<"Rhaast si-a refacut "<<(0.1 + 0.13 * (stats.ad / 100)) * creep_t.hp<<"HP si a dat "<<((350 + 1.75 * stats.ad) - (350 + 1.75 * stats.ad) * stats.dmg_r)<<" normal damage!";
        stats.hp += (0.1 + 0.13 * (stats.ad / 100)) * creep_t.hp;
        inamic.hp -= ((350 + 1.75 * stats.ad) - (350 + 1.75 * stats.ad) * stats.dmg_r);
        cooldown = 1;
        turn = 0;
        break;
    case 6:
        cout<<"\nAatrox primeste "<<stats.ad * 0.3<<" AD!";
        stats.ad += stats.ad * 0.3;
        cout<<"\nPierde toate rezistentele si crit damage pentru a primi +100% life steal si 100% crit!";
        stats.dmg_r = 0;
        stats.life_s += 1;
        stats.crit = 1;
        stats.crit_dmg = 1.5;
        cooldown = 1;
        turn = 0;
    case 7:
        if(inamic.hp <= 20 * profile.skill_points + 0.8 * stats.ad + 300 * stats.armor_pen)
        {
            cout<<"\nInamicul a fost in raza de executare!";
            cout<<"\nAi dat "<<inamic.hp<<" magic damage!";
            inamic.hp = 0;

        }
        else
        {
            cout<<"\nInamicul nu este in raza de executare, trebuie sa fie sub "<<20 * profile.skill_points + 0.8 * stats.ad + 300 * stats.armor_pen<<"HP!";
        }
        break;
    }
}

void combat(class_stats &stats, player_profile &profile, class_stats inamic,class_stats &stats_total, class_stats creep_t,int xp,int gold)
{
    unsigned cd1,cd2,cd3,cc3,cc2,cc1,turn;
    cc1 = cc2 = turn = cd1 = cd2 = cd3 = cc3 = 0;
    stats.dmg_r -= stats.dmg_r * inamic.armor_pen;
    inamic.dmg_r -= inamic.dmg_r * stats.armor_pen;
    while(stats.hp > 0 && inamic.hp > 0)
    {
        switch(turn)
        {
        case 0:
            system("cls");
            unsigned ability;
            cout<<endl<<"0 - Atac de baza   1 - Foloseste abilitatea primara    2 - Foloseste abilitatea secundara  3 - Foloseste ultimata  4 - Foloseste o potioune  5 - FF\n";
            cout<<"Este randul tau, alege ceea ce vrei sa faci: ";do{cin>>ability;}while(ability != 0 && ability != 1 && ability != 2 && ability != 3 && ability != 4 && ability != 5);
            if(ability == 4 && stats.hp + 50 <= stats_total.hp)
                if(profile.potions)
                {
                    profile.potions--;
                    stats.hp += 50;
                    cout<<"\nAi folosit o potiune, mai ai "<<profile.potions<<" potiuni!";
                    do{cout<<"\nAlege-ti urmatoarea miscare (0, 1, 2, 3 sau 5): ";cin>>ability;}while(ability == 4 || ability < 0 || ability > 5);
                }
                else
                    if(profile.potions == 0)
                {
                    cout<<"\nNu mai ai potiuni!\n";
                    do{cout<<"\nAlege-ti urmatoarea miscare (0, 1, 2, 3 sau 5): ";cin>>ability;}while(ability == 4 || ability < 0 || ability > 5);
                }
            else
            if(ability == 4 && stats.hp + 50 > stats_total.hp)
                 {
                    cout<<"\nTrebuie sa ai cel mult "<<stats_total.hp - 50<<"HP pentru a folosi o potiune!\n";
                    do{cout<<"\nAlege-ti urmatoarea miscare (0, 1, 2, 3 sau 5): ";cin>>ability;}while(ability == 4 || ability < 0 || ability > 5);
                }
            switch(ability)
            {
            case 0:
                {system("cls");
                int crit = rand() % 100;
                cout<<"Ai folosit un atac de baza!\n";
                if(crit && crit <= stats.crit * 100)
                    {
                        inamic.hp -= (stats.ad - stats.ad * inamic.dmg_r) * stats.crit_dmg;
                        cout<<"Ai dat "<<(stats.ad - stats.ad * inamic.dmg_r) * stats.crit_dmg<<" CRIT normal damage!";
                        stats.hp += stats.life_s * (stats.ad - stats.ad * inamic.dmg_r) * stats.crit_dmg;
                    }
                else
                    {
                        inamic.hp -= (stats.ad - stats.ad * inamic.dmg_r);
                        cout<<"Ai dat "<<stats.ad - stats.ad * inamic.dmg_r<<" normal damage!";
                        stats.hp += stats.life_s * (stats.ad - stats.ad * inamic.dmg_r);
                    }
                turn = 1;
                if(cd1)
                    cd1--;
                if(cd2)
                    cd2--;
                afisare_combat_hp(stats,stats_total,inamic,creep_t);
                next();}
                break;
            case 1:
                {

                    if(cd1 > 0)
                        cout<<"\nAbilitatea primara este in cooldown pentru inca "<<cd1<<" ture!";
                    else
                    {
                        system("cls");
                        cout<<"Ai folosit abilitatea primara!";
                        if(cd2)
                            cd2--;
                        abilitate1(stats,profile,cd1,inamic,turn,stats_total,creep_t);
                        afisare_combat_hp(stats,stats_total,inamic,creep_t);
                    }

                    next();
                }
                break;
            case 2:
                {
                    if(cd2 > 0)
                        cout<<"\nAbilitatea secundara este in cooldown pentru inca "<<cd2<<" ture!";
                    else
                    {
                        system("cls");
                        cout<<"Ai folosit abilitatea secundara!";
                        if(cd1)
                            cd1--;
                        abilitate2(stats,profile,cd2,inamic,turn,creep_t,stats_total);
                        afisare_combat_hp(stats,stats_total,inamic,creep_t);
                    }
                    next();
                }
                break;
            case 3:
                {
                    if(cd3 == 1)
                        cout<<"\nUltimata a fost deja folosita!";
                    else
                    {
                        system("cls");
                        cout<<"Ai folosit Ultimata!";
                        ultimata(stats,profile,cd3,inamic,turn,creep_t,stats_total);
                        afisare_combat_hp(stats,stats_total,inamic,creep_t);
                    }
                    if(cd3 == 1)
                    {
                        if(cd1)
                            cd1--;
                        if(cd2)
                            cd2--;
                    }
                    next();
                    break;
                }
            case 5:
                {
                    system("cls");
                    unsigned alege;
                    cout<<"Ai ales sa te predai, esti sigur ca doresti sa faci asta? Daca te predai, vei pierde lupta si vei fi ucis!";
                    do{cout<<"\nAlege 0 - Da    1 - Nu: ";cin>>alege;}while(alege != 0 && alege != 1);
                    if(alege == 0)
                    {
                        cout<<"\nAi ales sa te predai!";
                        stats.hp = 0;
                    }
                    break;
                }

            }
            break;
        case 1:
            {
            system("cls");
            int crit = rand() % 100;
            int alege;
            if(strstr(inamic.nume_clasa,"Creature"))
                alege = 0;
            else
                alege = rand() % 4;
            switch(alege)
            {
            case 0:
                {
                    cout<<"Inamicul foloseste un atac de baza!";
                    if(crit && crit <= inamic.crit * 100)
                {
                    stats.hp -= (inamic.ad - inamic.ad * stats.dmg_r) * inamic.crit_dmg;
                    cout<<"\nA dat normal damage crit in valoare de "<<(inamic.ad - inamic.ad * stats.dmg_r) * inamic.crit_dmg;
                    inamic.hp += inamic.life_s * (inamic.ad - inamic.ad * stats.dmg_r) * inamic.crit_dmg;
                }
                else
                {
                    stats.hp -= (inamic.ad - inamic.ad * stats.dmg_r);
                    cout<<"\nA dat normal damage in valoare de "<<inamic.ad - inamic.ad * stats.dmg_r;
                    inamic.hp += inamic.life_s * (inamic.ad - inamic.ad * stats.dmg_r);
                }
                afisare_combat_hp(stats,stats_total,inamic,creep_t);
                turn = 0;
                if(cc1)
                    cc1--;
                if(cc2)
                    cc2--;
                next();
                }
                break;
            case 1:
                if(cc1 == 0)
                {
                system("cls");
                cout<<"Inamicul a folosit abilitatea primara!";
                abilitate1(inamic,profile,cc1,stats,turn,creep_t,stats_total);

                if(cc2)
                    cc2--;
                afisare_combat_hp(stats,stats_total,inamic,creep_t);
                next();
                }

                break;
            case 2:
                if(cc2 == 0)
                {
                    system("cls");
                    cout<<"Inamicul a folosit abilitatea secundara!";
                    abilitate2(inamic,profile,cc2,stats,turn,stats_total,creep_t);
                    if(cc1)
                        cc1--;
                    afisare_combat_hp(stats,stats_total,inamic,creep_t);
                    next();
                }
                break;
            case 3:
                if(cc3 == 0)
                {
                   cout<<"Inamicul a folosit ultimata!";
                   ultimata(inamic,profile,cc3,stats,turn,stats_total,creep_t);
                   if(cc1)
                    cc1--;
                   if(cc2)
                    cc2--;
                    afisare_combat_hp(stats,stats_total,inamic,creep_t);
                   next();
                }

                break;
            }
            }
            break;
        }
    }
    if(stats.hp <= 0)
        win_lose(profile,0,xp,gold,stats_total,stats);
    if(inamic.hp <= 0)
        win_lose(profile,1,xp,gold,stats_total,stats);
    stats = stats_total;
}

#endif // COMBAT_H_INCLUDED
