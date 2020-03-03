#ifndef THE_GAME_H_INCLUDED
#define THE_GAME_H_INCLUDED
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include "player_character.h"
#include "utility.h"
#include "combat.h"
#include "aventura.h"

void shop_potiuni(class_stats &stats_total,class_stats &stats,player_profile &profil)
{
    unsigned select;
    do{
        system("cls");
        cout<<"                                                  Shop - Potiuni\n";
        cout<<"============================================================================================================\n\n";
        do{cout<<"1 - Heal pot (+50HP)\n0 - Intoarce-te la Shop";
        cout<<"\nAlege: ";cin>>select;
        }while(select < 0 || select > 1);
        switch(select)
        {
        case 1:
            system("cls");
            if(profil.gold >= 50)
            {
                cout<<"Ai cumparat o potiune de Heal!";
                profil.gold -= 50;
                profil.potions++;
                cout<<"\nMai ai "<<profil.gold<<"G!";
                cout<<"\nAi "<<profil.potions<<" potiuni!";
                next();
            }
            else
                {cout<<"Nu ai suficient gold!\nMai ai nevoie de "<<50 - profil.gold<<" pentru a cumpara o potiune!";
                next();}
            break;
        }
    }while(select);
}

void shop_of(player_profile &profil,class_stats &stats_total,unsigned v[31])
{
    //odata cu adaugarea unui numar de iteme, nu uita sa schimbi si numarul lor de la shop_file_check
    unsigned select;
    do{
    system("cls");
    cout<<"                                                  Shop - Attack Damage items\n";
    cout<<"============================================================================================================\n\n";
    cout<<"Aici sunt toate itemele ce ofera statusuri ofensive, poti cumpara doar un singur item din fiecare.\n";
    cout<<"\nDaca detii un item ce poate fi construit in alt item, atunci poti sa il consumi pentru a reduce pretul\n";
    cout<<"item-ului imbunatatit, acesta poate fi reachizitionat.\nItemele nu pot fi vandute!\n";
    do{
        cout<<"ID: 1 - Long Sword(350G) : +10AD\n";
        cout<<"ID: 2 - Doran's Blade(500G) : +8AD | +80HP | +3% Life Steal\n";
        cout<<"ID: 3 - Pickaxe(850G) : +25AD\n";
        cout<<"ID: 4 - Vampiric Blade(900G/550G + Long Sword) : +15AD | +10% Life Steal\n";
        cout<<"ID: 5 - Serrated Dirk(1100G) : +35AD\n";
        cout<<"ID: 6 - Orc Sword(1500G) : +45AD\n";
        cout<<"ID: 7 - Hexdrinker(1500G) : +20AD | +2% DMGr\n";
        cout<<"ID: 8 - Last Whisper(1500G) : +20AD | 20% Armor Pen\n";
        cout<<"ID: 9 - RAT's Crossbow(2800G/200G + Serrated Dirk + Last Whisper) : +45AD | 40% Armor Pen\n";
        cout<<"ID: 10 - Ghostblade of Darktharr(3000G/1500G + Orc Sword) : +76AD\n";
        cout<<"ID: 11 - Edge of Night(3000G/1500G + Serrated Dirk + Ruby Crystal) : +55AD | +300HP\n";
        cout<<"ID: 26 - Frozen Mallet(3100G/1950G + Long Sword + Kindlegem) : +700HP | +30AD\n";
        cout<<"ID: 12 - Maw of Malmortius(3250G) : +50AD | +8% DMGr\n";
        cout<<"ID: 13 - Essence Reaver(3300G) : +70AD | + 1.5% Life Steal | +25% Crit\n";
        cout<<"ID: 14 - Infinity Edge(3400G) : +80AD | +25% Crit | +50% Crit Damage\n";
        cout<<"ID: 15 - Bloodthirster(3500G) : +80AD | +20% Life Steal\n";
        cout<<"ID: 16 - Death's Dance(3600G) : +80AD | +15% Life Steal | +10%DMGr\n";
        cout<<"ID: 17 - Ghostblade of Death(3500G + Ghostblade of Darktharr) : +24AD | +25% Crit | +50% Crit damage\n";
        cout<<"ID: 18 - Infernal Edge(3500G + Infinity Edge) : +30AD | +25% Crit | Crit Damage = 300%";
        cout<<"\n\n0 - Inapoi";
        cout<<"\n\n\nAlege ID-ul item-ului dorit: ";cin>>select;
        }while((select < 0 || select > 18) && select != 26);
    switch(select)
    {
    case 1:
        {
            system("cls");
            if(v[1] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 350)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<350 - profil.gold<<"G!";
            if(v[1] == 0 && profil.gold >= 350)
            {
                v[1] = 1;
                profil.gold -= 350;
                stats_total.ad += 10;
                cout<<"Ai cumparat \"Long Sword\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        next();
        }
        break;
    case 2:
        {
            system("cls");
            if(v[2] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 500)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<500 - profil.gold<<"G!";
            if(v[2] == 0 && profil.gold >= 500)
            {
                v[2] = 1;
                profil.gold -= 500;
                stats_total.ad += 8;
                stats_total.life_s += 0.03;
                stats_total.hp += 80;
                cout<<"Ai cumparat \"Doran's Blade\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        next();
        }
        break;
    case 3:
        {
            system("cls");
            if(v[3] == 1)
                cout<<"Deja detii acest item!";
            else
                if(profil.gold < 850)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<850 - profil.gold<<"G!";
            if(v[3] == 0 && profil.gold >= 850)
            {
                v[3] = 1;
                profil.gold -= 850;
                stats_total.ad += 25;
                cout<<"Ai cumparat \"Pickaxe\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 4:
        {
            //long sword
            system("cls");
            if(v[4] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[1] == 1 && profil.gold < 550)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<550 - profil.gold<<"G!";
                else
                    if(v[1] == 0 && profil.gold < 900)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<900 - profil.gold<<"G!";
            if(v[4] == 0 && v[1] == 1 && profil.gold >= 550)
            {
                v[4] = 1;
                v[1] = 0;
                profil.gold -= 550;
                stats_total.ad += 5;
                stats_total.life_s += 0.1;
                cout<<"Ai cumparat \"Vampiric Blade\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[4] == 0 && v[1] == 0 && profil.gold >= 900)
            {
                v[4] = 1;
                profil.gold -= 900;
                stats_total.ad += 15;
                stats_total.life_s += 0.1;
                cout<<"Ai cumparat \"Vampiric Blade\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 5:
        {
            system("cls");
            if(v[5] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 1100)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1100 - profil.gold<<"G!";
            if(v[5] == 0 && profil.gold >= 1100)
            {
                v[5] = 1;
                profil.gold -= 1100;
                stats_total.ad += 35;
                cout<<"Ai cumparat \"Serrated Dirk\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 6:
        {
            system("cls");
            if(v[6] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 1500)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1500 - profil.gold<<"G!";
            if(v[6] == 0 && profil.gold >= 1500)
            {
                v[6] = 1;
                profil.gold -= 1500;
                stats_total.ad += 45;
                cout<<"Ai cumparat \"Orc Sword\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 7:
        {
            system("cls");
            if(v[7] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 1500)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1500 - profil.gold<<"G!";
            if(v[7] == 0 && profil.gold >= 1500)
            {
                v[7] = 1;
                profil.gold -= 1500;
                stats_total.ad += 20;
                stats_total.dmg_r += 0.02;
                cout<<"Ai cumparat \"Hexdrinker\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 8:
        {
            system("cls");
            if(v[8] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 1500)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1500 - profil.gold<<"G!";
            if(v[8] == 0 && profil.gold >= 1500)
            {
                v[8] = 1;
                profil.gold -= 1500;
                stats_total.ad += 20;
                stats_total.armor_pen += 0.2;
                cout<<"Ai cumparat \"Last Whisper\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 9:
        {
            //Serrated Dirk + Last Whisper
            system("cls");
            if(v[9] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[5] == 1 && v[8] == 1 && profil.gold < 200)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<200 - profil.gold<<"G!";
                else
                    if((v[5] == 0 || v[8] == 0) && profil.gold < 2800)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2800 - profil.gold<<"G!";
            if(v[9] == 0 && v[5] == 1 && v[8] == 1 && profil.gold >= 200)
            {
                v[9] = 1;
                v[5] = 0;
                v[8] = 0;
                profil.gold -= 200;
                stats_total.ad += 25;
                stats_total.armor_pen += 0.20;

                cout<<"Ai cumparat \"RAT's Crossbow\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[9] == 0 && (v[5] == 0 || v[8] == 0) && profil.gold >= 2800)
            {
                v[9] = 1;
               profil.gold -= 2800;
               stats_total.ad += 45;
               stats_total.armor_pen += 0.4;

               cout<<"Ai cumparat \"RAT's Crossbow\"!";
               cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 10:
        //Orc Sword
        {
            system("cls");
            if(v[10] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[6] == 1 && profil.gold < 1500)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1500 - profil.gold<<"G!";
                else
                    if(v[6] == 0 && profil.gold < 3000)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3000 - profil.gold<<"G!";
            if(v[10] == 0 && v[6] == 1 && profil.gold >= 1500)
            {
                v[10] = 1;
                v[6] = 0;
                profil.gold -= 1500;
                stats_total.ad += 31;
                cout<<"Ai cumparat \"Ghostblade of Darktharr\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[10] == 0 && v[6] == 0 && profil.gold >= 3000)
            {
                v[10] = 1;
                profil.gold -= 3000;
                stats_total.ad += 76;
                cout<<"Ai cumparat \"Ghostblade of Darktharr\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 11:
        //Serrated Dirk + Ruby Crystal
        {
            system("cls");
            if(v[11] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[5] == 1 && v[19] == 1 && profil.gold < 1500)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1500 - profil.gold<<"G!";
                else
                    if((v[5] == 0 || v[19] == 0) && profil.gold < 3000)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3000 - profil.gold<<"G!";
            if(v[11] == 0 && v[5] == 1 && v[19] == 1 && profil.gold >= 1500)
            {
                v[11] = 1;
                v[5] = 0;
                v[19] = 0;
                profil.gold -= 1500;
                stats_total.ad += 20;
                stats_total.hp += 150;

                cout<<"Ai cumparat \"Edge of Night\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[11] == 0 && (v[5] == 0 || v[19] == 0) && profil.gold >= 3000)
            {
                v[9] = 1;
               profil.gold -= 2800;
               stats_total.ad += 45 + stats_total.ad * 0.35;

               cout<<"Ai cumparat \"Edge of Night\"!";
               cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 12:
        //hexdrinker
        {
            system("cls");
            if(v[12] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[7] == 1 && profil.gold < 1750)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1750 - profil.gold<<"G!";
                else
                    if(v[7] == 0 && profil.gold < 3250)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3250 - profil.gold<<"G!";
            if(v[12] == 0 && v[7] == 1 && profil.gold >= 1750)
            {
                v[12] = 1;
                v[7] = 0;
                profil.gold -= 2750;
                stats_total.ad += 30;
                stats_total.dmg_r += 0.045;
                cout<<"Ai cumparat \"Maw of Malmortius\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[12] == 0 && v[7] == 0 && profil.gold >= 3250)
            {
                v[12] = 1;
                profil.gold -= 3250;
                stats_total.ad += 50;
                stats_total.dmg_r += 0.08;
                cout<<"Ai cumparat \"Maw of Malmortius\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 13:
        {
            system("cls");
            if(v[13] == 1)
                cout<<"Deja detii acest item!";
            else
                if(profil.gold < 3300)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3300 - profil.gold<<"G!";
            if(v[13] == 0 && profil.gold >= 3300)
            {
                v[13] = 1;
                profil.gold -= 3300;
                stats_total.ad += 70;
                stats_total.life_s += 0.015;
                stats_total.crit += 0.25;
                cout<<"Ai cumparat \"Essence Reaver\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 14:
        //Orc Sword + Last Whisper
        {
            system("cls");
            if(v[14] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[6] == 1 && v[8] == 1 && profil.gold < 400)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<400 - profil.gold<<"G!";
                else
                    if((v[6] == 0 || v[8] == 0) && profil.gold < 3400)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3400 - profil.gold<<"G!";
            if(v[14] == 0 && v[6] == 1 && v[8] == 1 && profil.gold >= 400)
            {
                v[14] = 1;
                v[6] = 0;
                v[8] = 0;
                profil.gold -= 400;
                stats_total.ad += 15;
                stats_total.crit += 0.25;
                stats_total.crit_dmg += 0.5;

                cout<<"Ai cumparat \"Infinity Edge\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[14] == 0 && (v[6] == 0 || v[8] == 0) && profil.gold >= 3400)
            {
                v[14] = 1;
               profil.gold -= 3400;
               stats_total.ad += 80;
               stats_total.crit += 0.25;
               stats_total.crit_dmg += 0.5;

               cout<<"Ai cumparat \"Infinity Edge\"!";
               cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 15:
        //Orc Sword + Vampiric Blade
        system("cls");
            if(v[15] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[6] == 1 && v[4] == 1 && profil.gold < 2400)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2400 - profil.gold<<"G!";
                else
                    if((v[6] == 0 || v[4] == 0) && profil.gold < 3500)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3500 - profil.gold<<"G!";
            if(v[15] == 0 && v[6] == 1 && v[4] == 1 && profil.gold >= 2400)
            {
                v[14] = 1;
                v[6] = 0;
                v[4] = 0;
                profil.gold -= 2400;
                stats_total.ad += 20;
                stats_total.life_s += 0.1;

                cout<<"Ai cumparat \"Bloodthirster\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[15] == 0 && (v[6] == 0 || v[4] == 0) && profil.gold >= 3500)
            {
                v[14] = 1;
               profil.gold -= 3400;
               stats_total.ad += 80;
               stats_total.life_s += 0.2;

               cout<<"Ai cumparat \"Bloodthirster\"!";
               cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        next();
        break;
    case 16:
        //Maw of Malmortius
        {
            system("cls");
            if(v[16] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[12] == 1 && profil.gold < 350)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<350 - profil.gold<<"G!";
                else
                    if(v[12] == 0 && profil.gold < 3600)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3600 - profil.gold<<"G!";
            if(v[16] == 0 && v[12] == 1 && profil.gold >= 350)
            {
                v[16] = 1;
                v[12] = 0;
                profil.gold -= 350;
                stats_total.ad += 30;
                stats_total.dmg_r = 0.3;
                stats_total.life_s += 0.15;
                cout<<"Ai cumparat \"Death's Dance\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[16] == 0 && v[12] == 0 && profil.gold >= 3600)
            {
                v[16] = 1;
                profil.gold -= 3600;
                stats_total.ad += 80;
                stats_total.dmg_r = 0.3;
                stats_total.life_s += 0.15;
                cout<<"Ai cumparat \"Death's Dance\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
    case 17:
        //Ghostblade of Darktharr
        {
            system("cls");
            if(v[17] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(v[10] == 0)
                        cout<<"Trebuie sa detii \"Ghostblade of Darktharr\" pentru a cumpara acest item!";
                        else
                            if(v[10] == 1 && profil.gold < 3500)
                                cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3500 - profil.gold<<"G!";
            if(v[17] == 0 && v[10] == 1 && profil.gold >= 3500)
            {
                v[17] = 1;
                profil.gold -= 3500;
                stats_total.ad += 24;
                stats_total.crit_dmg += 0.5;
                stats_total.crit += 0.25;
                cout<<"Ai cumparat \"Ghostblade of Death\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }

        }
        next();
        break;
    case 18:
        {
            system("cls");
            if(v[18] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(v[14] == 0)
                        cout<<"Trebuie sa detii \"Infinity Edge\" pentru a cumpara acest item!";
                        else
                            if(v[14] == 1 && profil.gold < 3500)
                                cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3500 - profil.gold<<"G!";
            if(v[18] == 0 && v[14] == 1 && profil.gold >= 3500)
            {
                v[18] = 1;
                profil.gold -= 3500;
                stats_total.ad += 30;
                stats_total.crit_dmg = 3;
                stats_total.crit += 0.25;
                cout<<"Ai cumparat \"Infernal Edge\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }

        }
        next();
        break;
    case 26:
            {
                //kindlegem + Long Sword
                system("cls");
                if(v[26] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[21] == 1 && v[1] == 1 && profil.gold < 1950)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1950 - profil.gold<<"G!";
                else
                    if((v[21] == 0 || v[1] == 0) && profil.gold < 3100)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3100 - profil.gold<<"G!";
            if(v[26] == 0 && v[1] == 1 && v[21] == 1 && profil.gold >= 1950)
            {
                v[26] = 1;
                v[21] = 0;
                v[1] = 0;
                profil.gold -= 1950;
                stats_total.hp += 400;
                stats_total.ad += 20;

                cout<<"Ai cumparat \"Frozen Mallet\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[26] == 0 && (v[21] == 0 || v[1] == 0) && profil.gold >= 3100)
            {
                v[26] = 1;
                profil.gold -= 3100;
                stats_total.hp += 700;
                stats_total.ad += 30;

                cout<<"Ai cumparat \"Frozen Mallet\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;

    }
    }while(select);
}

void shop_def(player_profile &profil,class_stats &stats_total,unsigned v[31])
{
    unsigned select;
    do{
    system("cls");
    cout<<"                                                  Shop - Health Points items\n";
    cout<<"============================================================================================================\n\n";
    cout<<"Aici sunt toate itemele ce ofera statusurile defensive, poti cumpara doar un singur item din fiecare.\n";
    cout<<"\nDaca detii un item ce poate fi construit in alt item, atunci poti sa il consumi pentru a reduce pretul\n";
    cout<<"item-ului imbunatatit, acesta poate fi reachizitionat.\nItemele nu pot fi vandute!\n";
        do{
        cout<<"ID: 19 - Ruby Crystal(400G) : +150HP\n";
        cout<<"ID: 20 - Doran's Shield(450G) : +90HP | +1%DMGr\n";
        cout<<"ID: 2 - Doran's Blade(500G) : +80HP | +8AD | +3% Life Steal\n";
        cout<<"ID: 21 - Kindlegem(800G/400G + Ruby Crystal) : +300HP\n";
        cout<<"ID: 28 - Chainvest(800G) : +3,5% DMGr\n";
        cout<<"ID: 22 - Sunfire Cape(2750G/1150G + Kindlegem + Chainvest) : +425HP | +10%DMGr\n";
        cout<<"ID: 23 - Spirit Visage(2800G/1700G + Kindlegem + Vampiric Blade) : +450HP | +30% Life Steal\n";
        cout<<"ID: 24 - Warmog's Armor(2850G) : +1200HP\n";
        cout<<"ID: 25 - Randuin's Omen(2900G/1300G + Kindlegem + Chainvest) : +400HP | +15% DMGr\n";
        cout<<"ID: 11 - Edge of Night(3000G/1500G + Serrated Dirk + Ruby Crystal) : +55AD | +300HP\n";
        cout<<"ID: 26 - Frozen Mallet(3100G/1950G + Long Sword + Kindlegem) : +700HP | +30AD\n";
        cout<<"ID: 27 - Forgefire Cape(2500G + Sunfire Cape) : +325HP | +8%DMGr\n";
        cout<<"\n\n0 - Inapoi";
        cout<<"\n\n\nAlege ID-ul item-ului dorit: ";cin>>select;
        }while( (select < 19 || select > 28)  && select != 2 && select != 11 && select != 0);
        switch(select)
        {
        case 19:
            {
                system("cls");
                if(v[19] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 400)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<400 - profil.gold<<"G!";
            if(v[19] == 0 && profil.gold >= 400)
            {
                v[19] = 1;
                profil.gold -= 400;
                stats_total.hp += 150;
                cout<<"Ai cumparat \"Ruby Crystal\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            next();
            }
            break;
        case 20:
            {
                system("cls");
                if(v[20] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 450)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<400 - profil.gold<<"G!";
                if(v[20] == 0 && profil.gold >= 450)
                {
                    v[20] = 1;
                    profil.gold -= 450;
                    stats_total.hp += 90;
                    stats_total.dmg_r += 0.01;
                    cout<<"Ai cumparat \"Doran's Shield\"!";
                    cout<<"\nMai ai "<<profil.gold<<"G!";
                }
            }
            next();
            break;
        case 2:
            {
            system("cls");
            if(v[2] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 500)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<500 - profil.gold<<"G!";
            if(v[2] == 0 && profil.gold >= 500)
            {
                v[2] = 1;
                profil.gold -= 500;
                stats_total.ad += 8;
                stats_total.life_s += 0.03;
                stats_total.hp += 80;
                cout<<"Ai cumparat \"Doran's Blade\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        next();
        }
        break;
        case 21:
            {   //ruby crystal
                system("cls");
                if(v[21] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[19] == 1 && profil.gold < 400)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<400 - profil.gold<<"G!";
                else
                    if(v[19] == 0 && profil.gold < 800)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<800 - profil.gold<<"G!";
            if(v[21] == 0 && v[19] == 1 && profil.gold >= 400)
            {
                v[21] = 1;
                v[19] = 0;
                profil.gold -= 400;
                stats_total.hp += 150;
                cout<<"Ai cumparat \"Kindlegem\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[21] == 0 && v[19] == 0 && profil.gold >= 800)
            {
                v[21] = 1;
                profil.gold -= 800;
                stats_total.hp += 300;
                cout<<"Ai cumparat \"Kindlegem\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;
        case 22:
            {   //kindlegem + chainvest
                system("cls");
                if(v[22] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[28] == 1 && v[21] == 1 && profil.gold < 1150)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1150 - profil.gold<<"G!";
                else
                    if((v[28] == 0 || v[21] == 0) && profil.gold < 2750)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2750 - profil.gold<<"G!";
            if(v[22] == 0 && v[21] == 1 && v[28] == 1 && profil.gold >= 1150)
            {
                v[22] = 1;
                v[21] = 0;
                v[28] = 0;
                profil.gold -= 1150;
                stats_total.hp += 125;
                stats_total.dmg_r += 0.065;

                cout<<"Ai cumparat \"Sunfire Cape\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[22] == 0 && (v[21] == 0 || v[28] == 0) && profil.gold >= 2750)
            {
                v[22] = 1;
                profil.gold -= 2750;
                stats_total.hp += 425;
                stats_total.dmg_r += 0.1;

                cout<<"Ai cumparat \"Sunfire Cape\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }

            }
            next();
            break;
        case 23:
            {   //Kindlegem + Vampiric Blade
                system("cls");
                if(v[23] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[21] == 1 && v[4] == 1 && profil.gold < 1700)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1700 - profil.gold<<"G!";
                else
                    if((v[21] == 0 || v[4] == 0) && profil.gold < 2800)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2800 - profil.gold<<"G!";
            if(v[23] == 0 && v[21] == 1 && v[4] == 1 && profil.gold >= 1700)
            {
                v[23] = 1;
                v[21] = 0;
                v[4] = 0;
                profil.gold -= 1700;
                stats_total.hp += 150;
                stats_total.life_s += 0.2;

                cout<<"Ai cumparat \"Spirit Visage\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[23] == 0 && (v[21] == 0 || v[4] == 0) && profil.gold >= 2800)
            {
                v[23] = 1;
                profil.gold -= 2800;
                stats_total.hp += 450;
                stats_total.life_s += 0.3;

                cout<<"Ai cumparat \"Spirit Visage\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }

            }
            next();
            break;
        case 24:
            {
                system("cls");
                if(v[24] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 2850)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2850 - profil.gold<<"G!";
            if(v[24] == 0 && profil.gold >= 2850)
            {
                v[24] = 1;
                profil.gold -= 2850;
                stats_total.hp += 1200;
                cout<<"Ai cumparat \"Warmog's Armor\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;
        case 25:
            {
                //kindlegem + chainvest
                system("cls");
                if(v[25] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[28] == 1 && v[21] == 1 && profil.gold < 1300)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1300 - profil.gold<<"G!";
                else
                    if((v[28] == 0 || v[21] == 0) && profil.gold < 2900)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2900 - profil.gold<<"G!";
            if(v[25] == 0 && v[21] == 1 && v[28] == 1 && profil.gold >= 1300)
            {
                v[25] = 1;
                v[21] = 0;
                v[28] = 0;
                profil.gold -= 1300;
                stats_total.hp += 100;
                stats_total.dmg_r += 0.115;

                cout<<"Ai cumparat \"Randuin's Omen\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[25] == 0 && (v[21] == 0 || v[28] == 0) && profil.gold >= 2900)
            {
                v[25] = 1;
                profil.gold -= 2900;
                stats_total.hp += 400;
                stats_total.dmg_r += 0.15;

                cout<<"Ai cumparat \"Sunfire Cape\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;
        case 28:
            {
                system("cls");
            if(v[28] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(profil.gold < 800)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<800 - profil.gold<<"G!";
            if(v[28] == 0 && profil.gold >= 800)
            {
                v[28] = 1;
                profil.gold -= 800;
                stats_total.dmg_r += 0.035;
                cout<<"Ai cumparat \"Chainvest\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;
        case 11:
            //Serrated Dirk + Ruby Crystal
        {
            system("cls");
            if(v[11] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[5] == 1 && v[19] == 1 && profil.gold < 1500)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1500 - profil.gold<<"G!";
                else
                    if((v[5] == 0 || v[19] == 0) && profil.gold < 3000)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3000 - profil.gold<<"G!";
            if(v[11] == 0 && v[5] == 1 && v[19] == 1 && profil.gold >= 1500)
            {
                v[11] = 1;
                v[5] = 0;
                v[19] = 0;
                profil.gold -= 1500;
                stats_total.ad += 20;
                stats_total.hp += 150;

                cout<<"Ai cumparat \"Edge of Night\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[11] == 0 && (v[5] == 0 || v[19] == 0) && profil.gold >= 3000)
            {
                v[9] = 1;
               profil.gold -= 2800;
               stats_total.ad += 45 + stats_total.ad * 0.35;

               cout<<"Ai cumparat \"Edge of Night\"!";
               cout<<"\nMai ai "<<profil.gold<<"G!";
            }
        }
        next();
        break;
        case 26:
            {
                //kindlegem + Long Sword
                system("cls");
                if(v[26] == 1)
                cout<<"Deja detii acest item!";
            else
                if(v[21] == 1 && v[1] == 1 && profil.gold < 1950)
                    cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<1950 - profil.gold<<"G!";
                else
                    if((v[21] == 0 || v[1] == 0) && profil.gold < 3100)
                        cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<3100 - profil.gold<<"G!";
            if(v[26] == 0 && v[1] == 1 && v[21] == 1 && profil.gold >= 1950)
            {
                v[26] = 1;
                v[21] = 0;
                v[1] = 0;
                profil.gold -= 1950;
                stats_total.hp += 400;
                stats_total.ad += 20;

                cout<<"Ai cumparat \"Frozen Mallet\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            else
                if(v[26] == 0 && (v[21] == 0 || v[1] == 0) && profil.gold >= 3100)
            {
                v[26] = 1;
                profil.gold -= 3100;
                stats_total.hp += 700;
                stats_total.ad += 30;

                cout<<"Ai cumparat \"Frozen Mallet\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;
        case 27:
            {
                system("cls");
                if(v[17] == 1)
                cout<<"Deja detii acest item!";
                else
                    if(v[22] == 0)
                        cout<<"Trebuie sa detii \"Sunfire Cape\" pentru a cumpara acest item!";
                        else
                            if(v[22] == 1 && profil.gold < 2500)
                                cout<<"Nu ai suficienti bani!\nMai ai nevoie de "<<2500 - profil.gold<<"G!";
            if(v[27] == 0 && v[22] == 1 && profil.gold >= 2500)
            {
                v[27] = 1;
                profil.gold -= 2500;
                stats_total.hp += 325;
                stats_total.dmg_r += 0.08;
                cout<<"Ai cumparat \"Forgefire Cape\"!";
                cout<<"\nMai ai "<<profil.gold<<"G!";
            }
            }
            next();
            break;
        }
    }while(select);
}

void shop(class_stats &stats_total,class_stats &stats,player_profile &profil,unsigned v[31])
{
    unsigned select;
    do{
        system("cls");
        cout<<"                                                  Shop\n";
        cout<<"============================================================================================================\n\n";
        cout<<"Gold: "<<profil.gold<<endl;
        do{cout<<"1 - Potiuni\n2 - Offensive Stats\n3 - Deffensive Stats\n0 - Intoarce-te la meniul principal";
        cout<<"\nAlege categoria: ";cin>>select;}while(select < 0 || select > 6);
        switch (select)
        {
        case 1:
            shop_potiuni(stats_total,stats,profil);
            break;
        case 2:
            shop_of(profil,stats_total,v);
            break;
        case 3:
            shop_def(profil,stats_total,v);
            break;
        }
    }while(select);
    stats = stats_total;
}


void aventura(class_stats &stats_total,class_stats &stats,player_profile &profil,unsigned v[31])
{
    unsigned select;
    do{
        system("cls");
        cout<<"                                                  Lista de aventuri\n";
        cout<<"============================================================================================================\n\n";
        do{cout<<"1 - Catacombe\n2 - Infernul\n0 - Intoarce-te la meniul principal";
        cout<<"\nAlege categoria: ";cin>>select;}while(select < 0 || select > 6);
        switch (select)
        {
        case 1:
            aventura_dungeons(stats,stats_total,profil);
            break;
        case 2:
            aventura_infern(stats,stats_total,profil,v);
            break;
        }
    }while(select);

}

void meniul(class_stats &stats_total,player_profile &profil,class_stats &stats,unsigned v[31])
{
    unsigned select;
    do{
        system("cls");
        cout<<"                                                  Meniul Principal\n";
        cout<<"============================================================================================================\n\n";
        do{cout<<"1 - Save\n2 - Shop\n3 - Stats\n4 - Aventura\n5 - Inventar\n0 - Quit";
        cout<<endl<<"Alege: ";cin>>select;}while(select < 0 || select > 5);
        switch(select)
        {
        case 1:
            system("cls");
            cout<<"Progresul tau a fost salvat!";
            save_game(stats_total,profil);
            next();
            break;
        case 2:
            shop(stats_total,stats,profil,v);
            break;
        case 3:
            afisare_stats(profil,stats);
            afisare_skills(stats);
            next();
            break;
        case 4:
            aventura(stats_total,stats,profil,v);
            break;
        case 5:
            system("cls");
            cout<<"                                                  Inventarul\n";
            cout<<"============================================================================================================\n\n";
            cout<<"\n\nGold: "<<profil.gold;
            cout<<"\nPotiuni: "<<profil.potions;
            cout<<endl<<"ID-ul itemelor detinute: | ";
            for(int i = 1; i < 29; i++)
                if(v[i])
                    cout<<i<<" | ";
            next();
            break;

        }
    }while(select);
    cout<<"Progresul tau a fost salvat automat!";
    next();
    save_game(stats_total,profil);
}

#endif // THE_GAME_H_INCLUDED
