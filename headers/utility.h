#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void next()
{
    cout<<'\n'<<"Apasa o tasta pentru a continua:";getch();
}

void shop_file_load(unsigned v[31])
{
    fstream f("items.txt");
    unsigned x;
    f>>x;
    if(x)
    {
        f<<0<<" ";
        for(int i = 1; i < 31; i++)
        {
            f<<0<<" ";
            v[i] = 0;
        }
    }
    else
        for(int i = 1; i < 31; i++)
            f>>v[i];
    f.close();
}
void shop_file_update(unsigned v[31])
{
    ofstream f("items.txt");
    f<<0<<" ";
    for(int i = 1; i < 31; i++)
        f<<v[i]<<" ";
    f.close();
}

void levelup(int xp, player_profile &profile,class_stats &stats_total,class_stats &stats)
{
    unsigned clasa;
    if(strstr(stats_total.nume_clasa,"Tank"))
        clasa = 0;
    else
        if(strstr(stats.nume_clasa,"Bruiser"))
        clasa = 1;
    else
        clasa = 2;
    if(profile.xp + xp >= 100 * profile.level)
    {
        profile.xp = profile.xp + xp - 100 * profile.level;
        profile.level++;
        profile.skill_points++;
        profile.potions++;
        profile.gold += 50;
        switch(clasa)
            {
            case 0:
                stats_total.hp += 100;
                stats_total.ad += 5;
                stats.hp += 100;
                stats.ad += 5;
                break;
            case 1:
                stats_total.hp += 80;
                stats.ad += 10;
                stats.hp += 80;
                stats_total.ad += 10;
                break;
            case 2:
                stats.hp += 70;
                stats.ad += 20;
                stats_total.ad += 20;
                stats_total.hp += 70;
            }
        cout<<"\nLevel up!";
        cout<<"\nNivelul tau actual: "<<profile.level;
        cout<<"\nXP: "<<profile.xp<<"/"<<profile.level * 100;
        cout<<"\nSkill Points: "<<profile.skill_points;
    }
        else
            profile.xp += xp;

}

void afisare_skills(class_stats stats)
{
    unsigned clasa;
    if(strstr(stats.nume_clasa,"Tank"))
        clasa = 0;
    else
        if(strstr(stats.nume_clasa,"Bruiser"))
        clasa = 1;
        else
            clasa = 2;
    switch(clasa)
    {
    case 0:
        cout<<"                                                  Abilitatile clasei  "<<stats.nume_clasa<<'\n';
        cout<<"============================================================================================================\n\n";
        cout<<"\nTancul este o clasa ce se bazeaza pe abilitati, avand mai mult utility in acestea.";
        cout<<"\n\nPasiva \"Thormnail\": Abilitatile tale scaleaza si cu DMGr.";
        cout<<"\n\nAbilitatea primara \"Impact\": Dai damage inamicului.";
        cout<<"\n       Formula: 200% din DMGr + 5 * skill points + 100% din AD | Normal Damage";
        cout<<"\n       Cooldown: 3 ture";
        cout<<"\n\nAbilitatea secundara \"Shock Wave\": Dai damage inamicului si il ametesti.";
        cout<<"\n       Formula: 40 + 10 * skill points + 200% din DMGr | Normal Damage";
        cout<<"\n       Cooldown: 6 ture";
        cout<<"\n\nUltimata \"Drop of Life\": Furi o parte din viata inamicului si tu si inamicul renuntati la o parte din rezistente.";
        cout<<"\n       Formula pentru damage: 10% din viata curenta a inamicului | Magic Damage";
        cout<<"\n       Formula pentru viata primita: 50% din DMGr + 20% din viata lipsa a inamicului";
        cout<<"\n       Tu si inamicul pierdeti 10% din rezistente";
        break;
    case 1:
        cout<<"                                                  Abilitatile clasei  "<<stats.nume_clasa<<'\n';
        cout<<"============================================================================================================\n\n";
        cout<<"\nBruiser-ul este o clasa ce se bazeaza pe life steal si sustain damage.";
        cout<<"\n\nPasiva \"Grasp of the Undying\": Abilitatile tale au un efect special atunci cand esti sub 30% HP.";
        cout<<"\n\nAbilitatea primara \"Jaws of the Beast\": Dai un atac de baza imbunatatit.";
        cout<<"\n       Efectul pasivei: Primesti 60% din damage-ul dat ca HP";
        cout<<"\n       Formula: 10 * skill points + 100% din AD | Normal Damage";
        cout<<"\n       Cooldown: 2 ture";
        cout<<"\n\nAbilitatea secundara \"Primal Strike\": Dai damage.";
        cout<<"\n       Efectul pasivei: \"Primal Strike\" da mai mult damage, convertit in Magic Damage";
        cout<<"\n       Formula: 50 + 5 * skill points + 30% din AD | Normal Damage";
        cout<<"\n       Cooldown: 4 ture";
        cout<<"\n               sub 30% HP: cooldown: 2 ture | 40 + 5 * skill points + 100% din AD + 20% din viata lipsa a inamicului | Magic Damage";
        cout<<"\n\nUltimata \"Bleeding Beast\": Primesti AD si Life steal, dar primesti 20% mai mult damage.";
        cout<<"\n       Efectul pasivei: Deblocheaza aceasta abilitate";
        cout<<"\n       Formula: AD: 35% din viata ta lipsa | Life Steal: suma rezistentei tale si a inamicului | DMGr: -20%";
        break;
    case 2:
        cout<<"                                                  Abilitatile clasei  "<<stats.nume_clasa<<'\n';
        cout<<"============================================================================================================\n\n";
        cout<<"\nAssassin-ul este o clasa bazata pe burst si armor pen.";
        cout<<"\n\nPasiva \"Bleeding Prey\": Abilitatea primara si secundara au un efect special atunci cand inamicul este sub 50% HP.";
        cout<<"\n\nAbilitatea primara \"Void's Stab\": Injunghii inamicul.";
        cout<<"\n       Efectul pasivei: Daune critice";
        cout<<"\n       Formula: 65 + 20 * Skill Points + 90% din AD";
        cout<<"\n       Cooldown: 3 ture";
        cout<<"\n\nAbilitatea secundara \"Deep Cut\": Un atac de baza ce micsoreaza armura inamicului cu 5%.";
        cout<<"\n       Efectul pasivei: Inamicul pierde 10% din armura curenta";
        cout<<"\n       Cooldown: 4 ture";
        cout<<"\n\nUltimata \"Death Sentence\": Daca inamicul are HP-ul sub o anumita valoare, il vei executa.";
        cout<<"\n       Pragul de executare: Ultimata poate fi folosita daca inamicul este sub 20 * Skill Points + 80% din AD + 30 pe 10% Armor Pen HP";
        break;
    }
}

void combat_stats(class_stats stats)
{
    cout<<"\nClasa: "<<stats.nume_clasa;
    cout<<"\n\nHP: "<<stats.hp;
    cout<<"\nDMGr:   "<<stats.dmg_r*100<<'%';
    cout<<"\nAD:   "<<stats.ad;
    cout<<"\nCrit:   "<<stats.crit*100<<'%';
    cout<<"\nCrit Damage:   "<<stats.crit_dmg * 100<<"%";
    cout<<"\nLife Steal:   "<<stats.life_s*100<<'%'<<'\n';
    cout<<"Armor Pen:   "<<stats.armor_pen * 100<<"%\n";
    cout<<endl;
}
void afisare_stats(player_profile profil,class_stats stats)
{
    system("cls");
    cout<<"                                                  Statusurile jucatorului "<<profil.nume_player<<'\n';
    cout<<"============================================================================================================\n\n";
    cout<<"Clasa:   "<<stats.nume_clasa;
    cout<<"\nGenul:   "<<profil.gender;
    cout<<"\n\nHP:   "<<stats.hp;
    cout<<"\nDMGr:   "<<stats.dmg_r*100<<'%';
    cout<<"\nAD:   "<<stats.ad;
    cout<<"\nCrit:   "<<stats.crit*100<<'%';
    cout<<"\nArmor Pen:   "<<stats.armor_pen * 100<<"%";
    cout<<"\nCrit Damage:   "<<stats.crit_dmg * 100<<"%";
    cout<<"\nLife Steal:   "<<stats.life_s*100<<'%'<<'\n';
    cout<<"\nGold:   "<<profil.gold;
    cout<<"\nSkill Points:   "<<profil.skill_points;
    cout<<"\nXP:   "<<profil.xp<<"/"<<profil.level * 100;
    cout<<"\nLevel:   "<<profil.level;
    cout<<"\nKills:   "<<profil.kills;
    cout<<"\nDeaths:   "<<profil.deaths;
    cout<<"\nPotiuni:   "<<profil.potions;


}

void save_game(class_stats &stats_total,player_profile &profil)
{
    ofstream f_stats("statusurile_jucatorului.txt");
    f_stats<<stats_total.hp<<endl;
    f_stats<<stats_total.dmg_r<<endl;
    f_stats<<stats_total.ad<<endl;
    f_stats<<stats_total.crit<<endl;
    f_stats<<stats_total.life_s<<endl;
    f_stats<<stats_total.crit_dmg<<endl;
    f_stats<<stats_total.armor_pen<<endl;
    f_stats<<'\n'<<profil.gold;
    f_stats<<'\n'<<profil.skill_points;
    f_stats<<'\n'<<profil.xp;
    f_stats<<'\n'<<profil.level;
    f_stats<<'\n'<<profil.kills;
    f_stats<<'\n'<<profil.deaths;
    f_stats<<'\n'<<profil.potions;
    f_stats.close();
}

void load_stats(class_stats &stats_total,class_stats &stats,player_profile &profil)
{
    ifstream f_stats("statusurile_jucatorului.txt");
    ifstream f_nume("nume_clasa.txt");
    f_nume>>stats_total.nume_clasa;
    f_stats>>stats_total.hp;
    f_stats>>stats_total.dmg_r;
    f_stats>>stats_total.ad;
    f_stats>>stats_total.crit;
    f_stats>>stats_total.life_s;
    f_stats>>stats_total.crit_dmg;
    f_stats>>stats_total.armor_pen;
    f_nume>>profil.nume_player;
    f_nume>>profil.gender;
    f_stats>>profil.gold;
    f_stats>>profil.skill_points;
    f_stats>>profil.xp;
    f_stats>>profil.level;
    f_stats>>profil.kills;
    f_stats>>profil.deaths;
    f_stats>>profil.potions;
    stats = stats_total;
    f_stats.close();
    f_nume.close();
}

void documentar()
{
    unsigned select;
    do{
        system("cls");
        cout<<"                                                  Documentar\n";
        cout<<"============================================================================================================\n\n";
        cout<<"Toate informatiile necesare despre orice aspect al acestui joc.\n";
        cout<<"0 - Inapoi\n";
        cout<<"1 - Statusuri\n";
        cout<<"2 - Items\n";
        cout<<"3 - Level,Skill Points, XP si Gold\n";
        cout<<"4 - Combat\n";
        cout<<"5 - Caractere\n";
        do{cout<<"\n\nAlege: ";cin>>select;}while(select < 0 || select > 5);
        switch(select)
        {
        case 1:
            system("cls");
            cout<<"                                                  Documentar - Statusuri\n";
            cout<<"============================================================================================================\n\n";
            cout<<"Statusurile sunt caracteristicile tale si totodata sursa de scaling in lupta. Acestea pot fi obtinute din iteme\n";
            cout<<"si level up.\n";
            cout<<"- Health Points(HP): este statusul defensiv principal, acesta iti creste viata cu care incepi o lupta.\n";
            cout<<"- Damage Reduction(DMGr): status defensiv, reprezentand armura din joc, atunci cand esti ranit cu normal damage, acesta\n";
            cout<<"este diminuat de DMGr. Magic damage ignora DMGr, iar daca cineva are DMGr negativ, acesta va suferi daune bonus.\n";
            cout<<"- Attack Damage(AD): este statusul ofensiv principal, cu acesta scaleaza unele abilitati, de acest status profita\n";
            cout<<"in special caracterele axate pe damage. Atacurile de baza scaleaza cu 100% din AD, iar un atac critic scaleaza cu mai mult\n";
            cout<<"in functie de statusul Crit Damage\n";
            cout<<"- Crit Damage: status ofensiv ce iti creste damage-ul de pe loviturile critice, normal, acesta este 200% din AD\n";
            cout<<"- Crit: status ofensiv ce se refera la sansa unei lovituri critice. Daca ai crit, lovitura ta critica depinde de RNG.\n";
            cout<<"- Armor Penetration(Armor Pen): status ofensiv ce reduce la inceputul luptei un procent din armura curenta a inamicului.\n";
            cout<<"\n- Life Steal: status utilitar, fiecare atac de baza iti returneaza HP egal cu un procent din damage-ul dat pe auto sau auto\n";
            cout<<"empowered. Un procent mai mare de Life steal, inseamna mai mult HP. Poti depasi viata maxima prin life steal\n";
            next();
            break;
        case 2:
            system("cls");
            cout<<"                                                  Documentar - Items\n";
            cout<<"============================================================================================================\n\n";
            cout<<"Itemele sunt principalele resurse de statusuri, acestea pot fi achizitionate din Shop folosind Gold(G) sau castigate\n";
            cout<<"ca trofee din Infern.\n";
            cout<<"Nu poti detine mai mult de un item dintr-un tip, cumpararea unui item sau obtinerea acestuia este ireversibila,\n";
            cout<<"acestea impartindu-se in iteme simple, iteme complete si enchanted. Itemele complete pot avea pret redus daca detii\n";
            cout<<"item-ul simplu din care sunt facute, acest proces te va face sa consumi item-ul simplu, dar acesta poate fi reachizitionat,\n";
            cout<<"iar cele enchanted sunt iteme complete cu statusuri mai bune, acest proces nu consuma item-ul complet.\n";
            cout<<"Exista 2 iteme speciale ce pot fi obtinute numai prin invingerea lui Aatrox.\n";
            cout<<"Potiunile sunt iteme speciale, consumabile, ce ofera un anumit efect valabil doar in acea lupta.";
            next();
            break;
        case 3:
            system("cls");
            cout<<"                                                  Documentar - Level, Skill Points, XP si Gold\n";
            cout<<"============================================================================================================\n\n";
            cout<<"Gold(G): Reprezinta moneda acestui joc, cu Gold poti achizitiona diverse obiecte din Shop. Daca esti ucis sau cumperi\n";
            cout<<"un item, gold-ul tau scade. Gold-ul este obtinut ca recompensa din level up si invingerea inamicilor.\n";
            cout<<"Level(lvl): Reprezinta puterea si experienta acumulata de-a lungul jocului. Cu cat vei avea level mai mare, vei\n";
            cout<<"infrunta creaturi din ce in ce mai puternice.\n";
            cout<<"Experienta(XP): Reprezinta subunitatea level-ului, pentru a trece un nivel, vei avea nevoie de un anumit numar de XP\n";
            cout<<"pe care il vei obtine prin invingerea inamicilor in lupta.\n";
            cout<<"Skill Points: Odata cu level up, vei primi si skill points care fac abilitatile unui caracter mai puternice.";
            next();
            break;
        case 4:
            system("cls");
            cout<<"                                                  Documentar - Combat\n";
            cout<<"============================================================================================================\n\n";
            cout<<"Luptele se desfasoara in felul urmator: jucatorul va avea mereu prima miscare si va avea de ales dintre a folosi\n";
            cout<<"un atac de baza, abilitatea primara, abilitatea secundara, ultimata, sa consume o potiune sau sa se predea, dupa care\n";
            cout<<"inamicul isi va alege miscarea, doar demonii au alte abilitati decat atacul de baza.\n";
            cout<<"Lupta se bazeaza pe ture, fiecare ataca odata, dupa care asteapta raspunsul inamicului. Exceptie facand efectele de stun\n";
            cout<<"ceea ce ofera celuilalt o tura in plus si abilitatile fara cast-time.\n";
            cout<<"Efectele de stun dureaza doar o tura, iar abilitatile fara cast-time sunt abilitati ce ofera buff-uri/debuff-uri si nu dau damage.\n";
            cout<<"Ultimata, in general, este cea mai importanta abilitate, avand o utilizare unica intr-o lupta. Abilitatile celelalte,\n";
            cout<<"au in general un cooldown, acesta scazand odata cu turele proprii.";
            cout<<"\nExista 2 tipuri de damage: Normal Damage si Magic Damage; Crit reprezentand faptul ca daunele au fost multiplicate.\n";
            cout<<"Pentru a castiga o lupta, va trebui sa te folosesti de resursele si optiunile tale de lupta pentru a aduce viata inamicului\n";
            cout<<"la 0 sau o valoare negativa.\n";
            cout<<"Atacurile de baza scaleaza cu 100% din AD, aplica efecte, cum ar fi crit si life steal.\n";
            cout<<"Potiunile sunt iteme consumabile ce pot fi folosite odata pe tura, acestea nu au cast-time.\n";
            cout<<"Demonii isi aleg miscarea prin RNG.\n";
            cout<<"In vingerea unui inamic poate oferi XP, gold sau iteme, insa daca tu esti invins, vei pierde gold.";
            next();
            break;
        case 5:
            system("cls");
            cout<<"                                                  Documentar - Caractere\n";
            cout<<"============================================================================================================\n\n";
            cout<<"Caracterele pe care le poti alege sa joci ca fiind ele: Tank, Bruiser si Assassin\n";
            cout<<"In functie de ce caracter ai ales, vei avea un anumit playstyle si vei avea prioritate pentru un anumit status.\n";
            cout<<"Caracterele din acest joc:\n";
            cout<<"- Tank: damage scazut, rezistente ridicate, are un stun si se bazeaza pe statusuri defensive\n";
            cout<<"- Bruiser: damage moderat, rezistente moderate, se bazeaza pe life steal si AD\n";
            cout<<"- Assassin: damage ridicat, rezistente scazute, se bazeaza pe abilitati, mult AD si Armor Pen\n";
            cout<<"- Devil Teemo(Assassin): damage ridicat, rezistenta scazuta, se bazeaza pe abilitati\n";
            cout<<"- Varus(Demon): damage ridicat, rezistenta scazuta, se bazeaza pe atacuri de baza\n";
            cout<<"- Mordekaiser(Bruiser): damage ridicat, rezistenta moderata, se bazeaza pe life steal si abilitati\n";
            cout<<"- Rhaast(Bruiser): damage ridicat, rezistenta moderata, mult life steal, se bazeaza pe abilitati\n";
            cout<<"- Aatrox(???): statusuri ridicate";
            next();
            break;
        }

    }while(select);
}
#endif // UTILITY_H_INCLUDED
