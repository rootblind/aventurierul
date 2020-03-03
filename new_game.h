#ifndef NEW_GAME_H_INCLUDED
#define NEW_GAME_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include "player_character.h"
#include "utility.h"
#include "combat.h"


using namespace std;



void class_select(class_stats &stats,class_stats &stats_total)//selectarea clasei
{

    ofstream f_stats("statusurile_jucatorului.txt");// statusurile selectate
    ofstream f_nume("nume_clasa.txt");//detalii string

    unsigned select;
    system("cls");

    cout<<"                                                  Selectarea clasei\n";
    cout<<"============================================================================================================\n\n";
    cout<<"Tank (0) : Ai mult HP, Damage Reduction, dar nu ai mult damage.\n";
    cout<<"Bruiser (1): Ai damage moderat, Life Steal, iar rezistenta ta este moderata.\n";
    cout<<"Assassin (2):Ai mult burst damage, armor pen, dar rezistenta ta este mica.\n";
    cout<<"0- Tank      1- Bruiser      2- Assassin:";
    do{ cin>>select;
     }while(select != 0 && select != 1 && select != 2);
     if(select == 0)

            {
                strcpy(stats.nume_clasa,"Tank");//atribuirea statusurilor de inceput la tank
                strcpy(stats_total.nume_clasa,"Tank");
                stats_total.hp = stats.hp = 600;
                stats_total.dmg_r = stats.dmg_r = 0.3;
                stats_total.ad = stats.ad = 35;
                stats_total.crit = stats.crit = 0.0;
                stats_total.life_s = stats.life_s = 0.0;
                f_nume<<stats_total.nume_clasa<<endl;
                f_stats<<stats_total.hp<<endl;
                f_stats<<stats_total.dmg_r<<endl;
                f_stats<<stats_total.ad<<endl;
                f_stats<<stats_total.crit<<endl;
                f_stats<<stats_total.life_s<<endl;
                f_stats<<stats_total.crit_dmg<<endl;
                f_stats<<stats_total.armor_pen<<endl;

            }
        else
            if(select == 1)

       {

           strcpy(stats.nume_clasa,"Bruiser");//atribuirea statusurilor de inceput la brusier
           strcpy(stats_total.nume_clasa,"Bruiser");
           stats_total.hp = stats.hp = 500;
           stats_total.dmg_r = stats.dmg_r = 0.25;
           stats_total.ad = stats.ad = 65;
           stats_total.crit = stats.crit = 0.0;
           stats_total.life_s = stats.life_s = 0.0;
           f_nume<<stats_total.nume_clasa<<endl;
           f_stats<<stats_total.hp<<endl;
           f_stats<<stats_total.dmg_r<<endl;
           f_stats<<stats_total.ad<<endl;
           f_stats<<stats_total.crit<<endl;
           f_stats<<stats_total.life_s<<endl;
           f_stats<<stats_total.crit_dmg<<endl;
           f_stats<<stats_total.armor_pen<<endl;
       }
        else
        {
           strcpy(stats.nume_clasa,"Assassin");
           strcpy(stats_total.nume_clasa,"Assassin");
           stats_total.hp = stats.hp = 350;
           stats_total.dmg_r = stats.dmg_r = 0.1;
           stats_total.ad = stats.ad = 90;
           stats_total.crit = stats.crit = 0.0;
           stats_total.life_s = stats.life_s = 0.0;
           stats_total.armor_pen = 0.05;
           f_nume<<stats_total.nume_clasa<<endl;
           f_stats<<stats_total.hp<<endl;
           f_stats<<stats_total.dmg_r<<endl;
           f_stats<<stats_total.ad<<endl;
           f_stats<<stats_total.crit<<endl;
           f_stats<<stats_total.life_s<<endl;
           f_stats<<stats_total.crit_dmg<<endl;
           f_stats<<stats_total.armor_pen<<endl;
        }
       f_stats.close();
       f_nume.close();
       cout<<"\nAi ales "<<stats_total.nume_clasa<<"!\n";
       cout<<"HP:  "<<stats_total.hp;
       cout<<"\nDamage Reduction (DMGr):  "<<stats_total.dmg_r*100<<"%\n";
       cout<<"Attack Damage (AD):  "<<stats_total.ad;
       cout<<"\nCrit:  "<<stats_total.crit*100<<"%\n";
       cout<<"Life Steal:  "<<stats_total.life_s*100<<"%\n";
       cout<<"Crit damage:   "<<stats_total.crit_dmg * 100<<"%\n";
       cout<<"Armor Pen:    "<<stats_total.armor_pen * 100<<"%\n";
       next();

}

void profile_set(player_profile &profil, class_stats &stats)
{
    ofstream f_nume("nume_clasa.txt",ios::app);
    ofstream f_stats("statusurile_jucatorului.txt",ios::app);
    system("cls");

    cout<<"                                                  Profilul jucatorului\n";
    cout<<"============================================================================================================\n\n";
    do{cout<<"Insereaza-ti numele, maxim 20 de caractere: ";cin>>profil.nume_player;}while(strlen(profil.nume_player)>20);
    f_nume<<profil.nume_player;
    do{cout<<"\nAlege-ti genul M- masculin F- feminin E- elicopter de lupta A- altul: ";cin>>profil.gender;}
    while(profil.gender != 'M' && profil.gender != 'F' && profil.gender != 'E' && profil.gender != 'A');
    f_nume<<'\n'<<profil.gender;
    f_stats<<'\n'<<profil.gold;
    f_stats<<'\n'<<profil.skill_points;
    f_stats<<'\n'<<profil.xp;
    f_stats<<'\n'<<profil.level;
    f_stats<<'\n'<<profil.kills;
    f_stats<<'\n'<<profil.deaths;
    f_stats<<'\n'<<profil.potions;
    afisare_stats(profil, stats);
    afisare_skills(stats);

    next();
}

void tutorial(class_stats &stats, class_stats stats_total, player_profile &profil)
{
    system("cls");
    cout<<"                                                  Tutorial\n";
    cout<<"============================================================================================================\n\n";
    cout<<"\nSalutari, acest joc este bazat pe lupte in text doar 1 vs 1, fiecare avand cate o tura in care poate alege";
    cout<<"\ndaca sa foloseasca o abilitate, atac de baza, potiune sau sa fugi, acest lucru poate fi schimbat de efectele\n";
    cout<<"de ametire. Utilizarea potiunilor nu consuma tura, insa poate fi folosita o singura potiune pe tura.\n";
    cout<<"Fiecare clasa are doua abilitati de baza si o ultimata. Cele doua abilitati de baza au un cooldown\n";
    cout<<"reprezentat de ture trecute, iar ultimata poate fi folosita odata pe lupta, deci alege-ti momentul potrivit.\n";
    cout<<"In acest joc exista 2 tipuri de daune: \"Normal Damage\" si \"Magic Damage\", diferenta dintre cele 2 este ca Magic Damage ignora rezistentele(dmg_r)\n";
    cout<<"Inamicii pe care ii vei intalni vor fi creaturi, acestea pot folosi numai atacuri de baza. Si Demoni, acestia au si abilitati.\n";
    cout<<"Uciderea lor iti poate oferi iteme, gold si xp. Pentru mai multe detalii, iti recomand sa citesti documentarul.\n\n";
    cout<<"In acest tutorial vei invata sa te lupti, "<<profil.nume_player<<", sa incepem!";
    next();
    system("cls");
    class_stats tutorial_creep,creep_t;
    creep_t.ad = tutorial_creep.ad = 40;
    creep_t.hp = tutorial_creep.hp = 300;
    creep_t.dmg_r = tutorial_creep.dmg_r = 0.05;
    creep_t.crit = tutorial_creep.crit = 0.0;
    creep_t.life_s = tutorial_creep.life_s = 0;
    strcpy(tutorial_creep.nume_clasa,"Creature");
    strcpy(creep_t.nume_clasa,"Creature");
    combat(stats,profil,tutorial_creep,stats_total,creep_t,10,100);
    system("cls");
    save_game(stats_total,profil);
    cout<<"Progresul tau a fost salvat!";
    next();

}

void apelare_new_game(class_stats &stats, player_profile &profil,class_stats &stats_total)
{
    class_select(stats,stats_total);
    profile_set(profil,stats);
    unsigned alegere;
    cout<<"\nDoresti sa completezi tutorialul?\nCompletarea tutorialului te va rasplati cu 100G si 10xp";
    do{cout<<"\n0 - DA  1 - NU  :";cin>>alegere;}while(alegere != 1 && alegere != 0);
    if(alegere == 0)
        do{
                tutorial(stats,stats_total,profil);
        }while(profil.deaths);


}


#endif // NEW_GAME_H_INCLUDED
