/*
Ideea este de a face un rpg cu backstory ce odata completat poti farma la infinit.
Plan de programare:
Imparte programul in functii:
-int main: apeleaza functiile principale
-functiile principale: apeleaza functiile de constructie
-functiile de constructie: sunt impartite in headere in functie de ceea ce sunt capabile
*/
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string.h>

#include "new_game.h"
#include "player_character.h"
#include "utility.h"
#include "combat.h"
#include "the_game.h"

using namespace std;

void load(unsigned select, class_stats &stats,player_profile &profil, class_stats &stats_total,unsigned v[31])// new game sau load game
{
    shop_file_load(v);
    if(select == 0)
    {
        ofstream g("items.txt");
        shop_file_load(v);
        apelare_new_game(stats,profil, stats_total);
    }


    load_stats(stats_total,stats,profil);
    meniul(stats_total,profil,stats,v);
    shop_file_update(v);


}

void main_menu(unsigned &select)// meniul in care se deschide jocul
{

    do{
    system("cls");
    cout<<"============================================================================================================\n\n";
    cout<<"\nSelecteaza:\n"<<"0-   Joc nou         1-  Continua       2-  Documentar: ";
    cin>>select;
    if(select!=0 &&select !=1 && select != 2)
    {   system("cls");
        cout<<"Ai de ales dintre 0- Joc nou, 1- Continua sau 2- Documentar:";
    }
    if(select == 2)
        documentar();
    }while(select !=0 && select!=1 );

}



int main()
{
    player_profile profil;
    class_stats stats_total,stats;
    unsigned *select=new unsigned;
    unsigned v[31];
    main_menu(*select);
    load(*select, stats,profil,stats_total,v);
    delete select;
    getch();






}
