#ifndef AVENTURA_H_INCLUDED
#define AVENTURA_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include "player_character.h"
#include "utility.h"
#include "combat.h"

void aventura_dungeons(class_stats &stats,class_stats stats_total,player_profile &profil)
{
    unsigned select;
    do{
    system("cls");
    cout<<"                                                  Catacombe\n";
    cout<<"============================================================================================================\n\n";
    cout<<"\nCatacombele sunt principala sursa de gold si XP, aici te vei lupta cu creaturi de acelasi nivel ca si tine.\n";
    cout<<"Tu:";
    combat_stats(stats);
    class_stats inamic,inamic_t;
         if(profil.level < 10)
                {
                    inamic.ad = profil.kills * 0.5 + 30 + 5 * profil.level;
                    inamic.hp = 300 + stats.hp * 0.4 + 40 * profil.level;
                    inamic.dmg_r = 0.05;
                    inamic.life_s = 0;
                    inamic.crit = 0;
                }
         if(profil.level >= 10 && profil.level < 20)
                {
                    inamic.ad = 50 + 10 * profil.level;
                    inamic.hp = 500 + stats.hp * 0.4 + 80 * profil.level;
                    inamic.dmg_r = profil.level / 100;
                    inamic.life_s = 0.5 * stats.life_s;
                    inamic.crit = 0.25 * stats.crit;
                }
        if(profil.level >= 20 && profil.level < 30)
        {
            inamic.ad = 100 + 10 * profil.level + profil.kills;
            inamic.hp = 1000 + stats.hp * 0.3;
            inamic.dmg_r = profil.level / 100;
            inamic.life_s = 0.5;
            inamic.crit = stats.crit * 0.1;
            inamic.armor_pen = 0.2;
        }
        if(profil.level >= 30)
        {
            inamic.ad = stats.ad * 0.2 + profil.kills + profil.deaths + 15 * profil.level;
            inamic.hp = stats.hp + stats.hp * 0.5 + 50 * profil.level;
            inamic.dmg_r = 0.5;
            inamic.life_s = 0.1;
            inamic.crit = 0;
            inamic.armor_pen = 0.25;
        }
    strcpy(inamic.nume_clasa,"Creature");
    inamic_t = inamic;

    cout<<"\nInamicul:";
    combat_stats(inamic);
    do{cout<<"\n1 - Incepe lupta\n0 - Inapoi";
       cout<<"\nAlege: ";cin>>select;
       }while(select < 0 || select > 1);
     if(select == 1)
     {
         combat(stats,profil,inamic,stats_total,inamic_t,20 + profil.kills - profil.deaths + profil.level * 2,10 + profil.level * 10);
         system("cls");
         save_game(stats_total,profil);
     }
    }while(select);
}
void aventura_infern(class_stats &stats,class_stats stats_total,player_profile &profil,unsigned v[31])
{
    unsigned select,sel;
    do{
    system("cls");
    cout<<"                                                 Infernul\n";
    cout<<"============================================================================================================\n\n";
    cout<<"Infernul contine demoni ce au abilitati si sunt cu mult mai puternici decat creaturile, invinge acesti\n";
    cout<<"demoni pentru a obtine cantitati mari de XP, gold si iteme!\nFiecare demon are un anumit level, daca nu ai\n";
    cout<<"nivelul necesar, este imposibil sa invingi un demon.\n";
    cout<<"Daca depasesti cu 5 nivele un demon, acesta nu va mai oferi nimic.\n";
    cout<<"Exceptie face Aatrox the Undying, te poti lupta cu acesta dupa level 30, level-ul acestuia crescand odata cu al tau,\n";
    cout<<"asa ca dupa ce invingi cei 4 demoni, el va fi adversarul tau pentru eternitate!\n";
    class_stats inamic,inamic_t;
    stats_total = stats;
    do{
       cout<<"1 - Devil Teemo(level 3 - 8)";
       cout<<"\n2 - Varus(level 10 - 15)";
       cout<<"\n3 - Mordekaiser(level 17 - 22)";
       cout<<"\n4 - Rhaast(level 24 - 29)";
       cout<<"\n5 - Aatrox the Undying(level 30+)";
       cout<<"\n\n0 - Inapoi";
       cout<<"\nAlege: ";cin>>select;
    }while(select < 0 || select > 5);
    switch(select)
    {
    case 1:
        {
        unsigned winl = profil.deaths;
        system("cls");
        cout<<"                                                  Infernul - Devil Teemo\n";
        cout<<"============================================================================================================\n\n";
        cout<<"El este Teemo, imparatul intunericului si al tuturor creaturilor ce se tarasc prin negura noptii!\n";
        cout<<"Teemo este un asasin ce se bazeaza pe abilitati ce dau damage in functie de viata inamicului!";
        cout<<"\nAbilitatile lui Teemo:\n- Primara: Normal damage si stun\n- Secundara: Normal damage in functie de viata ta lipsa, dar daca esti sub\n";
        cout<<"50% HP, acesta va da mai mult damage, convertit in magic damage";
        cout<<"\n- Ultimata: Nuke damage ce scaleaza cu viata ta maxima";
        inamic.hp = 700;
        inamic.ad = 170;
        inamic.armor_pen = 0.2;
        inamic.crit = 0;
        inamic.dmg_r = 0.1;
        inamic.life_s = 0;
        cout<<"\nDevil Teemo stats:";
        strcpy(inamic.nume_clasa,"Teemo");
        inamic_t = inamic;
        combat_stats(inamic_t);
        do{cout<<"\nDoresti sa te lupti acum?: 1 - Da | 0 - Nu: ";cin>>sel;}while(sel != 1 && sel != 0);
        if(sel == 1)
        {

            if(profil.level <= 8)
            {
                combat(stats,profil,inamic,stats_total,inamic_t,500,0);
                if(winl == profil.deaths)
                    if(v[8] == 0)
                    {
                        cout<<"\nAi castigat \"Last Whisper\"!";
                        stats_total.ad += 20;
                        stats_total.armor_pen += 0.2;
                        stats = stats_total;
                        v[8] = 1;
                        shop_file_update(v);
                        next();
                    }
                    else
                    {
                        cout<<"\nDetii deja \"Last Whisper\", dar vei primi 30% din pretul item-ului in schimb!\n+450G";
                        profil.gold += 450;
                        next();
                    }
            }
            else
                combat(stats,profil,inamic,stats_total,inamic_t,0,0);
        }
        }
        break;
    case 2:
        {
            unsigned winl = profil.deaths;
            system("cls");
        cout<<"                                                  Infernul - Varus\n";
        cout<<"============================================================================================================\n\n";
        cout<<"Doi demoni au fost inchisi in corpul unui biet soldat, asa a aparut Varus!\n";
        cout<<"Varus este un demon ce se bazeaza pe loviturile de baza!";
        cout<<"\nAbilitatile lui Varus:\n- Primara: Varus renunta la o parte din rezistente pentru a-si imbunatati statusurile ofensive";
        cout<<"\n- Secundara: Varus primeste mai mult AD\n";
        cout<<"\n- Ultimata: Nuke damage ce scaleaza cu viata ta lipsa";
        inamic.hp = 1000;
        inamic.ad = 200;
        inamic.armor_pen = 0;
        inamic.crit = 0;
        inamic.dmg_r = 0.1;
        inamic.life_s = 0;
        cout<<"\nVarus stats:";
        strcpy(inamic.nume_clasa,"Varus");
        inamic_t = inamic;
        combat_stats(inamic_t);
        do{cout<<"\nDoresti sa te lupti acum?: 1 - Da | 0 - Nu: ";cin>>sel;}while(sel != 1 && sel != 0);
        if(sel == 1)
        {

            if(profil.level <= 15)
            {
                combat(stats,profil,inamic,stats_total,inamic_t,1200,0);
                if(winl == profil.deaths)
                    if(v[7] == 0)
                    {
                        cout<<"\nAi castigat \"Hexdrinker\"!";
                        stats_total.ad += 20;
                        stats_total.dmg_r += 0.02;
                        stats = stats_total;
                        v[7] = 1;
                        shop_file_update(v);
                        next();
                    }
                    else
                    {
                        cout<<"\nDetii deja \"Hexdrinker\", dar vei primi 30% din pretul item-ului in schimb!\n+240G";
                        profil.gold += 240;
                        next();
                    }
            }
            else
                combat(stats,profil,inamic,stats_total,inamic_t,0,0);
        }
        }
        break;
        case 3:
        {
            unsigned winl = profil.deaths;
            system("cls");
        cout<<"                                                  Infernul - Mordekaiser\n";
        cout<<"============================================================================================================\n\n";
        cout<<"Mordekaiser este lordul propriei sale lumi de apoi, orice fiinta ucisa de el, ii va fi servitoare in \"Shadow Realm\".\n";
        cout<<"El este un bruiser bazat pe burst";
        cout<<"\nAbilitatile lui Mordekaiser:\n- Primara: Mordekaiser isi izbeste buzduganul, dand damage.";
        cout<<"\n- Secundara: Se vindeca in funcie de viata sa lipsa\n";
        cout<<"\n- Ultimata: Nuke damage ce scaleaza cu viata ta lipsa";
        inamic.hp = 3000;
        inamic.ad = 300;
        inamic.armor_pen = 0.15;
        inamic.crit = 0;
        inamic.dmg_r = 0.3;
        inamic.life_s = 0.15;
        cout<<"\nMordekaiser stats:";
        strcpy(inamic.nume_clasa,"Morde");
        inamic_t = inamic;
        combat_stats(inamic_t);
        do{cout<<"\nDoresti sa te lupti acum?: 1 - Da | 0 - Nu: ";cin>>sel;}while(sel != 1 && sel != 0);
        if(sel == 1)
        {

            if(profil.level <= 22)
            {
                combat(stats,profil,inamic,stats_total,inamic_t,2200,0);
                if(winl == profil.deaths)
                    if(v[24] == 0)
                    {
                        cout<<"\nAi castigat \"Warmog's Armor\"!";
                        stats_total.hp += 1200;
                        stats = stats_total;
                        v[24] = 1;
                        shop_file_update(v);
                        next();
                    }
                    else
                    {
                        cout<<"\nDetii deja \"Warmog's Armor\", dar vei primi 30% din pretul item-ului in schimb!\n+855G";
                        profil.gold += 855;
                        next();
                    }
            }
            else
                combat(stats,profil,inamic,stats_total,inamic_t,0,0);
        }
        }
        break;
        case 4:
        {
            unsigned winl = profil.deaths;
            system("cls");
        cout<<"                                                  Infernul - Rhaast\n";
        cout<<"============================================================================================================\n\n";
        cout<<"Rhaast este cel mai agresiv dintre toti demonii, este un barbar insetat de sange, dar servitorul de incredere al lui Aatrox.\n";
        cout<<"El este un bruiser ce se vindeca din orice forma de damage";
        cout<<"\nAbilitatile lui Rhaast:\n- Primara: Rhaast da damage si se vindeca pentru 100% din damage-ul dat.";
        cout<<"\n- Secundara: Rhaast consuma o parte din viata sa curenta pentru a primi mai mult AD\n";
        cout<<"\n- Ultimata: Se vindeca in functie de viata lipsa a inamicului.";
        inamic.hp = 2000;
        inamic.ad = 500;
        inamic.armor_pen = 0.5;
        inamic.crit = 0;
        inamic.dmg_r = 0.3;
        inamic.life_s = 0.35;
        cout<<"\nRhaast stats:";
        strcpy(inamic.nume_clasa,"Rhaast");
        inamic_t = inamic;
        combat_stats(inamic_t);
        do{cout<<"\nDoresti sa te lupti acum?: 1 - Da | 0 - Nu: ";cin>>sel;}while(sel != 1 && sel != 0);
        if(sel == 1)
        {

            if(profil.level <= 29)
            {
                combat(stats,profil,inamic,stats_total,inamic_t,2500,0);
                if(winl == profil.deaths)
                    if(v[16] == 0)
                    {
                        cout<<"\nAi castigat \"Death's Dance\"!";
                        stats_total.ad += 80;
                        stats_total.life_s += 0.15;
                        stats_total.dmg_r += 0.1;
                        stats = stats_total;
                        v[16] = 1;
                        shop_file_update(v);
                        next();
                    }
                    else
                    {
                        cout<<"\nDetii deja \"Death's Dance\", dar vei primi 30% din pretul item-ului in schimb!\n+1080G";
                        profil.gold += 1080;
                        next();
                    }
            }
            else
                combat(stats,profil,inamic,stats_total,inamic_t,0,0);
        }
        }
        break;
    case 5:
        {
            unsigned winl = profil.deaths;
            system("cls");
        cout<<"                                                  Infernul - Aatrox the Undying\n";
        cout<<"============================================================================================================\n\n";
        cout<<"Aatrox este creatorul infernului, fiinta superioara si nemuritoare!.\n";
        cout<<"Stilul de lupta: ???";
        cout<<"\nAbilitatile lui Aatrox: ???";
        inamic.hp = (profil.deaths + profil.kills) * 1000;
        inamic.ad = (profil.deaths + profil.kills) * 1000 * 0.3;
        inamic.armor_pen = 0.35;
        inamic.crit = 0.2;
        inamic.dmg_r = 0.35;
        inamic.life_s = 1;
        cout<<"\nAatrox stats:";
        strcpy(inamic.nume_clasa,"Aatrox");
        inamic_t = inamic;
        combat_stats(inamic_t);
        do{cout<<"\nDoresti sa te lupti acum?: 1 - Da | 0 - Nu: ";cin>>sel;}while(sel != 1 && sel != 0);
        if(sel == 1)
        {

            if(profil.level >= 30)
            {
                combat(stats,profil,inamic,stats_total,inamic_t,3000,0);
                if(winl == profil.deaths)
                    {
                        if(v[29] == 0)
                        {
                            cout<<"\nAi castigat \"Darkin's Blood Sword\"!";
                            cout<<"\n+500AD | +30% Life Steal | +500HP";
                            stats_total.ad += 500;
                            stats_total.life_s += 0.3;
                            stats_total.hp += 500;
                            stats = stats_total;
                            v[29] = 1;
                            shop_file_update(v);
                            next();
                        }
                        else
                        {
                            cout<<"\nDetii deja \"Darkin's Blood Sword\", nu exista un echivalent pentru acest item, asa ca nu vei primi nimic, dar bravo pentru victoria ta!";
                            next();
                        }
                        if(v[30] == 0)
                        {
                            cout<<"\nAi castigat \"Darkin's Blood Vest\"!";
                            cout<<"\n+10% Dmgr | +2000HP | +30% Life Steal";
                            stats_total.hp += 2000;
                            stats_total.life_s += 0.3;
                            stats_total.dmg_r += 0.1;
                            stats = stats_total;
                            v[30] = 1;
                            shop_file_update(v);
                            next();
                        }
                        else
                        {
                            cout<<"\nDetii deja \"Darkin's Blood Vest\", nu exista un echivalent pentru acest item, asa ca nu vei primi nimic, dar bravo pentru victoria ta!";
                            next();
                        }
                    }

            }
            else
                {
                    cout<<"Ai ales sa te lupti cu Aatrox, dar ai un nivel prea mic, mai ai nevoie de "<<30 - profil.level<<" nivele pentru a-l infrunta pe marele Aatrox!";
                    cout<<"\n\"Aatrox te priveste cu dezinteres si dispare in negura infernului\"";
                    next();
                }
        }
        }
        break;
    }
    save_game(stats_total,profil);
}while(select);
}

#endif // AVENTURA_H_INCLUDED
