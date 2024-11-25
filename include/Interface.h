#ifndef INTERFACE_H
#define INTERFACE_H

#include "players.h"

#include <iostream>
#include "objectbase.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Interface{
private:
        char **h, **elf, **ork;//heroes
        int I=7, LprintSymb;// I - height of avatar, LprintSymb - adopt number of printf() symbols
        int JK=12, JE=18, JO=20;
        char **warriors, **archers, **special;//units
        int IU=5;
        int J=9;
        ObjectBase* BASE;
        /*MENU*/
        int Hero_Number, Unit_Number;
        char* MenuItem, *SideItem, **ItemNames;
        int* RaceItem;
        int counter, UpBorder, DownBorder;
        char key;
        /*   */
    public:
    Interface(){
           h=new char*[I];
            for(int i=0; i<I; i++)
                h[i]=new char[JK];

            elf=new char*[I];
            for(int i=0; i<I; i++)
                elf[i]=new char[JE];

            ork=new char*[I];
            for(int i=0; i<I; i++)
                ork[i]=new char[JO];

            for(int i=0; i<I; i++){
                for(int j=0; j<JE; j++)
                    elf[i][j]=' ';
            for(int k=0; k<JO; k++)
                ork[i][k]=' ';
            }

            warriors=new char*[I];
            archers=new char*[I];
            special=new char*[I];
            for(int i=0; i<I; i++){
                warriors[i]=new char[J];
                archers[i]=new char[J];
                special[i]=new char[J];
            }
        h[0][0]=' '; h[0][1]=' '; h[0][2]='_'; h[0][3]='_'; h[0][4]='_'; h[0][5]='/'; h[0][6]='|'; h[0][7]='\\'; h[0][8]='_'; h[0][9]='_'; h[0][10]=' '; h[0][11]=' ';
        h[1][0]=' '; h[1][1]='/'; h[1][2]=' '; h[1][3]=' '; h[1][4]=' '; h[1][5]=' '; h[1][6]=' '; h[1][7]=' '; h[1][8]=' '; h[1][9]=' '; h[1][10]='\\'; h[1][11]=' ';
        h[2][0]='|'; h[2][1]='\\'; h[2][2]='_'; h[2][3]='_'; h[2][4]='_'; h[2][5]='_'; h[2][6]='_'; h[2][7]='_'; h[2][8]='_'; h[2][9]='_'; h[2][10]='/'; h[2][11]='|';
        h[3][0]='|'; h[3][1]='\\'; h[3][2]='_'; h[3][3]='_'; h[3][4]='0'; h[3][5]='_'; h[3][6]='|'; h[3][7]='_'; h[3][8]='0'; h[3][9]='_'; h[3][10]='/'; h[3][11]='|';
        h[4][0]='|'; h[4][1]=' '; h[4][2]=' '; h[4][3]='|'; h[4][4]=' '; h[4][5]='|'; h[4][6]=' '; h[4][7]='|'; h[4][8]=' '; h[4][9]='|'; h[4][10]=' '; h[4][11]='|';
        h[5][0]='\\'; h[5][1]=' '; h[5][2]=' '; h[5][3]='|'; h[5][4]=' '; h[5][5]='|'; h[5][6]=' '; h[5][7]='|'; h[5][8]=' '; h[5][9]='|'; h[5][10]=' '; h[5][11]='/';
        h[6][0]=' '; h[6][1]=' '; h[6][2]='\\'; h[6][3]='_'; h[6][4]='_'; h[6][5]='|'; h[6][6]='_'; h[6][7]='|'; h[6][8]='_'; h[6][9]='/'; h[6][10]=' '; h[6][11]=' ';

        elf[0][7]='_'; elf[0][8]='\\'; elf[0][9]='|'; elf[0][10]='/'; elf[0][11]='_';
        elf[1][6]='/'; elf[1][7]='_'; elf[1][8]='_'; elf[1][9]='_'; elf[1][10]='_'; elf[1][11]='_'; elf[1][12]='\\';
        elf[2][0]='_'; elf[2][1]='_'; elf[2][5]='+';	elf[2][8]='_';	elf[2][10]='_';					elf[2][13]='+'; elf[2][16]='_'; elf[2][17]='_';
        elf[3][1]='\\'; elf[3][2]='\\'; elf[3][4]='+'; elf[3][8]='o'; elf[3][10]='o'; elf[3][14]='+';  elf[3][15]='/'; elf[3][16]='/';
        elf[4][2]='|'; elf[4][3]='_'; elf[4][4]='+'; elf[4][9]='_'; elf[4][10]='_'; elf[4][13]='+'; elf[4][14]='_'; elf[4][15]='|';
        elf[5][5]='+'; elf[5][6]='_'; elf[5][7]='_'; elf[5][8]='_'; elf[5][9]='_'; elf[5][10]='_'; elf[5][11]='_'; elf[5][12]='+';

        ork[0][0]='/'; ork[0][1]='|'; ork[0][2]='_'; for(int i=3; i<17; i++) ork[0][i]='='; ork[0][17]='_'; ork[0][18]='|'; ork[0][19]='\\';
        ork[1][0]='\\'; ork[1][1]='\\'; ork[1][2]='_'; ork[1][3]='\\'; ork[1][4]='\\'; for(int i=5; i<15; i++) ork[1][i]='-'; ork[1][15]='/'; ork[1][16]='/'; ork[1][17]='_'; ork[1][18]='/'; ork[1][19]='/';
        ork[2][4]='|'; ork[2][7]='('; ork[2][8]=')'; ork[2][11]='('; ork[2][12]=')';  ork[2][15]='|';
        ork[2][4]='|';                                                              ork[2][15]='|';
        ork[3][4]='|';                                                               ork[3][15]='|';
        ork[4][3]='/';  ork[4][6]='/'; ork[4][7]='|'; ork[4][12]='|'; ork[4][13]='\\'; ork[4][16]='\\';
        ork[5][3]='|'; ork[5][6]='\\'; ork[5][7]='\\'; ork[5][8]='-'; ork[5][9]='-'; ork[5][10]='-'; ork[5][11]='-'; ork[5][12]='/'; ork[5][13]='/'; ork[5][16]='|';
        ork[6][3]='\\'; for(int i=4; i<16; i++) ork[6][i]='_'; ork[6][16]='/';
        }

    void setBase(ObjectBase* base){
        BASE=base;
    }

    void InitializeMenuItem(){
        MenuItem=new char[BASE->getRACENUMB()];
        RaceItem=new int[BASE->getRACENUMB()];
        ItemNames=new char*[BASE->getRACENUMB()];
        for(int i=0; i<BASE->getRACENUMB(); i++)
            ItemNames[i]=new char[10];
        ItemNames[0][0]='K'; ItemNames[0][1]='N'; ItemNames[0][2]='I'; ItemNames[0][3]='G'; ItemNames[0][4]='H'; ItemNames[0][5]='T'; ItemNames[0][6]='\0';
        ItemNames[1][0]='E'; ItemNames[1][1]='L'; ItemNames[1][2]='F'; ItemNames[1][3]='\0';
        ItemNames[2][0]='O'; ItemNames[2][1]='R'; ItemNames[2][2]='C'; ItemNames[2][3]='\0';
        counter=0;
        UpBorder=BASE->getRACENUMB();
        DownBorder=0;
        for(int i=0; i<BASE->getRACENUMB(); i++)
            MenuItem[i]=' ';
        RaceItem[0]=BASE->getHUMRACE();
        RaceItem[1]=BASE->getELFRACE();
        RaceItem[2]=BASE->getEVILRACE();
        MenuItem[0]='*';
    }

    void Menu(){
        for(int i=0; i<BASE->getPLENGTH(); i++){
                key=0;
            while(key!=13){
                system("cls");
                AvatarsRace(RaceItem[counter]);
                printf("\n %s, chose hero:\n", BASE->getPLAYERS()[i].getNickname());
                drawline(0, '-', 20); cout<<"X"<<endl;
                for(int i=DownBorder; i<UpBorder; i++){
                    cout<<"--";
                    printf("%s", ItemNames[i]);
                    cout<<" "<<MenuItem[i]<<endl;
                }
                drawline(0, '-', 20); cout<<"X"<<endl;
                printf(" <PRESS Up OR Down>\n");
                key=getch();
                switch(key){
                    case 72:
                        if(counter>DownBorder){
                            MenuItem[counter]=' ';
                            counter--;
                            MenuItem[counter]='*';
                        }
                    break;
                    case 80:
                        if(counter<UpBorder-1){
                            MenuItem[counter]=' ';
                            counter++;
                            MenuItem[counter]='*';
                        }
                    break;
                }
            }
            BASE->getPLAYERS()[i].setRace(RaceItem[counter]);
            if(counter==DownBorder){
                counter++;
                MenuItem[counter]='*';
                DownBorder++;
            }
            else if(counter==UpBorder-1){
                counter--;
                MenuItem[counter]='*';
                UpBorder--;
            }
            else {
                for(int i=counter; i<UpBorder; i++){
                    MenuItem[i]=MenuItem[i+1];
                    ItemNames[i]=ItemNames[i+1];
                    RaceItem[i]=RaceItem[i+1];
                }
                UpBorder--;
                MenuItem[counter]='*';
            }
        }
        system("cls");
        delete []MenuItem;
        for(int i=0; i<BASE->getRACENUMB(); i++)
            delete []ItemNames[i];
        delete []ItemNames;
        delete []RaceItem;
    }

    void SideMenu(){
        DownBorder=0;
        counter=0;
        UpBorder=2;
        SideItem=new char[UpBorder];
        MenuItem=new char[UpBorder];
        for(int i=0; i<UpBorder; i++)
            MenuItem[i]=' ';
        MenuItem[0]='L';
        SideItem[0]='L';
        SideItem[1]='R';
        for (int i=0; i<BASE->getPLENGTH(); i++)
        {
            key=0;
            while(key!=13)
            {
                system("cls");
                printf(" %s, choose side on field\n", BASE->getPLAYERS()[i].getNickname());
                drawline(0, '-', 30); cout<<">"<<endl;
                for(int j=DownBorder; j<UpBorder; j++)
                    printf("\t%c\t", MenuItem[j]);
                cout<<endl;
                drawline(0, '-', 30); cout<<">"<<endl;
                printf(" <PRESS Left OR Right>\n");
                key=getch();
                switch(key){
                case 77://>
                    if(counter<UpBorder-1){
                            counter++;
                            MenuItem[counter]='R';
                            MenuItem[counter-1]=' ';
                        }
                    break;
                    case 75://<
                        if(counter>DownBorder){
                            counter--;
                            MenuItem[counter]='L';
                            MenuItem[counter+1]=' ';
                        }
                    break;
            }
        }
        BASE->getPLAYERS()[i].setSide(SideItem[counter]);
        if(counter==DownBorder){
                counter++;
                MenuItem[counter]='R';
                DownBorder++;
            }
            else if(counter==UpBorder-1){
                counter--;
                MenuItem[counter]='L';
                UpBorder--;
            }
        }
        //delete []MenuItem;
        delete []SideItem;
    }

    char CollocationMenu(){
        key=0;
        DownBorder=0;
        UpBorder=2;
        counter=0;
        MenuItem=new char[2];
        MenuItem[0]='*'; MenuItem[1]=' ';
        char* Answer=new char[2];
        Answer[0]='y'; Answer[1]='n';
        ItemNames=new char*[2];
        for(int i=0; i<2; i++)
            ItemNames[i]=new char[4];
        ItemNames[0][0]='Y'; ItemNames[0][1]='E'; ItemNames[0][2]='S'; ItemNames[0][3]='\0';
        ItemNames[1][0]='N'; ItemNames[1][1]='O'; ItemNames[1][2]='\0';
            while(key!=13){
                system("cls");
                printf("\nDO YOU WANT COLLOCATE UNITS YOURSELF?\n");
                for(int i=DownBorder; i<UpBorder; i++){
                    cout<<"--";
                    printf("%s", ItemNames[i]);
                    cout<<" "<<MenuItem[i]<<endl;
                }
                printf("\n <PRESS Up OR Down>\n");
                key=getch();
                switch(key){
                    case 72:
                        if(counter>DownBorder){
                            MenuItem[counter]=' ';
                            counter--;
                            MenuItem[counter]='*';
                        }
                    break;
                    case 80:
                        if(counter<UpBorder-1){
                            MenuItem[counter]=' ';
                            counter++;
                            MenuItem[counter]='*';
                        }
                    break;
                }
        }
        delete []MenuItem;
        for(int i=0; i<2; i++)
            delete []ItemNames[i];
        delete []ItemNames;
        system("cls");
        return Answer[counter];
        delete []Answer;
    }


     char pressWay(){
        char c;
        c=getch();
        while(int(c)!=75 && int(c)!=77 && int(c)!=72 && int(c)!=80)
            c=getch();
        switch(c){
                case 75://<
                    c='<';
                break;
                case 77://>
                    c='>';
                break;
                case 80://v
                    c='v';
                break;
                case 72://^
                    c='^';
                break;
            }
        return c;
    }

int pressCrush(){
        int c;
        c=getch();
        while(c!=48 && c!=49 && c!=50 && c!=51)
            c=getch();
        c=c-'0';
        return c;
    }

char pressUnitNumb(){
    char c;
    c=getch();
    while(int(c)<49 || int(c)>57)
        c=getch();
    return c;
}

int pressAction(){
    int c;
    c=getch();
    while(int(c)<48 || int(c)>50)
        c=getch();
    c=int(c)-'0';
    return c;
}

int DefineUnitRange(int PickedCrush, Players* P){
    BASE->setMOCurrent(BASE->getBegin());
    while(BASE->getCurrent()!=0){
            if(BASE->getCurrent()->getCrush()==PickedCrush && BASE->getCurrent()->getOwner()==P){
                return BASE->getCurrent()->getRange(); break;
            }
            BASE->setMOCurrent(BASE->getCurrent()->next);
    }
}

void AvatarsRace(int flag){
    switch(flag){
        case 1:
            for(int i=0; i<I; i++){
                    cout<<'\t';
                for(int j=0; j<JK; j++)
                    cout<<h[i][j];
                cout<<endl;
            }
        break;
        case 2:
            for(int i=0; i<I; i++){
                    cout<<'\t';
                for(int j=0; j<JE; j++)
                    cout<<elf[i][j];
                cout<<endl;
            }
        break;
        case 3:
                for(int i=0; i<I; i++){
                        cout<<'\t';
                for(int j=0; j<JO; j++)
                    cout<<ork[i][j];
                cout<<endl;
            }
        break;
    }
  }

void Avatarsonfield(){
    char ***tempmas; int *length; const int SIZE_T=3;
    tempmas=new char**[SIZE_T];
    tempmas[0]=h; tempmas[1]=elf; tempmas[2]=ork;
    length=new int[SIZE_T];
    length[0]=JK; length[1]=JE; length[2]=JO;
    for(int p=0; p<BASE->getPLENGTH()-1; p++){
            //Outputting nicknames
            if(BASE->getPLAYERS()[p].getSide()=='L'){
                drawline(0, ' ', 11);
                LprintSymb=printf("%s", BASE->getPLAYERS()[p].getNickname());}
            else if(BASE->getPLAYERS()[p+1].getSide()=='L'){
                    drawline(0, ' ', 11);
                    LprintSymb=printf("%s", BASE->getPLAYERS()[p+1].getNickname());
            }
            drawline(0, ' ', 73-LprintSymb);
            if(BASE->getPLAYERS()[p].getSide()=='R')
                cout<<BASE->getPLAYERS()[p].getNickname()<<endl;
            else if(BASE->getPLAYERS()[p+1].getSide()=='R')
                    cout<<BASE->getPLAYERS()[p+1].getNickname()<<endl;
        //Outputting avatars
        for(int i=0; i<I; i++){
                cout<<'\t';
                if(BASE->getPLAYERS()[p].getSide()=='L'){
            for(int j1=0; j1<length[BASE->getPLAYERS()[p].getRace()-1]; j1++)
                cout<<tempmas[BASE->getPLAYERS()[p].getRace()-1][i][j1];
            }
            if(BASE->getPLAYERS()[p+1].getSide()=='L'){
            for(int j2=0; j2<length[BASE->getPLAYERS()[p+1].getRace()-1]; j2++)
                cout<<tempmas[BASE->getPLAYERS()[p+1].getRace()-1][i][j2];
            }
            if(BASE->getPLAYERS()[p].getSide()=='R'){
                drawline(0, ' ', 60);
                for(int j1=0; j1<length[BASE->getPLAYERS()[p].getRace()-1]; j1++)
                    cout<<tempmas[BASE->getPLAYERS()[p].getRace()-1][i][j1];
                }

            if(BASE->getPLAYERS()[p+1].getSide()=='R'){
                    drawline(0, ' ', 60-LprintSymb);
                for(int j2=0; j2<length[BASE->getPLAYERS()[p+1].getRace()-1]; j2++)
                    cout<<tempmas[BASE->getPLAYERS()[p+1].getRace()-1][i][j2];
            }
            cout<<endl;
        }
    }
    delete []tempmas;
    delete []length;

    //Drawing avatars
}

    void HItems(){
        bool Hero_flag_F=false, Hero_flag_S=false;
        BASE->setMOCurrent(BASE->getBegin());
        BASE->setMOTemp(BASE->getBegin());
        while((Hero_flag_F!=true || Hero_flag_S!=true) &&(BASE->getCurrent()!=0 && BASE->getTemp()!=0)){
            if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getHEROCR())
                Hero_flag_F=true;
            else if(Hero_flag_F!=true) BASE->setMOCurrent(BASE->getCurrent()->next);
            if(BASE->getTemp()->getOwner()->getSide()=='R' && BASE->getTemp()->getCrush()==BASE->getHEROCR())
                Hero_flag_S=true;
            else if(Hero_flag_S!=true) BASE->setMOTemp(BASE->getTemp()->next);
            }
            if(Hero_flag_F==true && Hero_flag_S==true){
                LprintSymb=printf("\tHealth: %.1f%%", BASE->getCurrent()->getHit_Points());
                LprintSymb+=printf("\tRange: %d", BASE->getCurrent()->getRange());

                drawline(0, ' ', 72-LprintSymb);
                printf("Health: %.1f%%", BASE->getTemp()->getHit_Points());
                printf("\tRange: %d\n", BASE->getTemp()->getRange());

                LprintSymb=printf("\tArmor: %.0f", BASE->getCurrent()->getArmor());
                LprintSymb+=printf("\tCrush: %d", BASE->getCurrent()->getCrush());
                drawline(0, ' ', 66-LprintSymb);
                printf("Armor: %.0f", BASE->getTemp()->getArmor());
                printf("\tCrush: %d\n", BASE->getTemp()->getCrush());

                LprintSymb=printf("\tAttack: %d", BASE->getCurrent()->getAttack());
                drawline(0, ' ', 72-LprintSymb);
                 printf("\tAttack: %d\n", BASE->getTemp()->getAttack());

                 LprintSymb=printf("\tSpeed: %d", BASE->getCurrent()->getMove_Speed());
                 drawline(0, ' ', 72-LprintSymb);
                 printf("\tSpeed: %d\n", BASE->getTemp()->getMove_Speed());

                 LprintSymb=printf("\tIcon: %c", BASE->getCurrent()->getIcon());
                 drawline(0, ' ', 72-LprintSymb);
                 printf("\tIcon: %c\n", BASE->getTemp()->getIcon());
            }
        }

    void warrior()
    {
        char w[7][19];
        int numb=1;
            cout<<endl;
            w[0][0]=' '; w[0][1]='_'; w[0][2]='_'; w[0][3]='_'; w[0][4]='_'; w[0][5]='_'; w[0][6]='_'; w[0][7]='_'; w[0][8]=' ';
            w[1][0]='|'; w[1][1]=' '; w[1][2]=' '; w[1][3]='/'; w[1][4]=' '; w[1][5]='/'; w[1][6]=' '; w[1][7]='/'; w[1][8]='|';
            w[2][0]='|'; w[2][1]=' '; w[2][2]='/'; w[2][3]='_'; w[2][4]='/'; w[2][5]='_'; w[2][6]='/'; w[2][7]=' '; w[2][8]='|';
            w[3][0]='|'; w[3][1]=' '; w[3][2]=' '; w[3][3]='/'; w[3][4]='/'; w[3][5]=' '; w[3][6]=' '; w[3][7]=' '; w[3][8]='|';
            w[4][0]=' '; w[4][1]='-'; w[4][2]='-'; w[4][3]='-'; w[4][4]='-'; w[4][5]='-'; w[4][6]='-'; w[4][7]='-'; w[4][8]=' ';
            w[1][12]='H'; w[1][13]='e'; w[1][14]='a'; w[1][15]='l'; w[1][16]='t'; w[1][17]='h'; w[1][18]=':';
            w[2][12]='N'; w[2][13]=' '; w[2][14]='u'; w[2][15]='n'; w[2][16]='i'; w[2][17]='t'; w[2][18]=':';
            w[3][12]='A'; w[3][13]='r'; w[3][14]='m'; w[3][15]='o'; w[3][16]='r'; w[3][17]=':'; w[3][18]=' ';
            w[4][12]='S'; w[4][13]='t'; w[4][14]='e'; w[4][15]='p'; w[4][16]=':'; w[4][17]=' '; w[4][18]=' ';
            w[5][12]='A'; w[5][13]='t'; w[5][14]='t'; w[5][15]='a'; w[5][16]='c'; w[5][17]='k'; w[5][18]=':';
            w[6][12]=' '; w[6][13]='I'; w[6][14]='c'; w[6][15]='o'; w[6][16]='n'; w[6][17]=':'; w[6][18]=' ';
            for(int i=0; i<9; i++) cout<<w[0][i]; cout<<" "; for(int i=12; i<19; i++) cout<<w[1][i]<<" ";  cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            LprintSymb=0;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    LprintSymb+=printf("%.0f ", BASE->getCurrent()->getHit_Points());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    printf("%.0f ", BASE->getCurrent()->getHit_Points());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            for(int i=0; i<9; i++) cout<<w[1][i]; cout<<" "; for(int i=12; i<19; i++) cout<<w[2][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            LprintSymb=0;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getWARCR()){
                    LprintSymb+=printf("%d   ", numb); numb++;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            numb=1;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getWARCR()){
                    printf("%d   ", numb); numb++;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            for(int i=0; i<9; i++) cout<<w[2][i]; cout<<" "; for(int i=12; i<19; i++) cout<<w[3][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            LprintSymb=0;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    LprintSymb+=printf("%.0f   ", BASE->getCurrent()->getArmor());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    printf("%.0f   ", BASE->getCurrent()->getArmor());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            for(int i=0; i<9; i++) cout<<w[3][i]; cout<<" "; for(int i=12; i<19; i++) cout<<w[4][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            LprintSymb=0;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getMove_Speed());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    printf("%d  ", BASE->getCurrent()->getMove_Speed());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            for(int i=0; i<9; i++) cout<<w[4][i]; cout<<" "; for(int i=12; i<19; i++) cout<<w[5][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            LprintSymb=0;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    LprintSymb+=printf("%d   ", BASE->getCurrent()->getAttack());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getWARCR())
                    printf("%d   ", BASE->getCurrent()->getAttack());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            for(int i=12; i<19; i++) cout<<w[6][i]<<" ";
            BASE->setMOCurrent(BASE->getBegin());
            LprintSymb=0;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getWARCR()){
                    LprintSymb+=printf("\t\t\t%c ", BASE->getCurrent()->getIcon()); break;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 49-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getWARCR()){
                    printf("%c ", BASE->getCurrent()->getIcon()); break;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 18);   cout<<endl;
}

void archer()
{
    int numb=1;
    char a[8][19];
            a[0][0]=' '; a[0][1]='_'; a[0][2]='_'; a[0][3]='_'; a[0][4]='_'; a[0][5]='_'; a[0][6]='_'; a[0][7]='_'; a[0][8]=' ';
            a[1][0]='|'; a[1][1]=' '; a[1][2]=' '; a[1][3]=' '; a[1][4]='/'; a[1][5]=' '; a[1][6]='|'; a[1][7]=' '; a[1][8]='|';
            a[2][0]='|'; a[2][1]='<'; a[2][2]='-'; a[2][3]='|'; a[2][4]='-'; a[2][5]='-'; a[2][6]='|'; a[2][7]='-'; a[2][8]='|';
            a[3][0]='|'; a[3][1]=' '; a[3][2]=' '; a[3][3]=' '; a[3][4]='\\'; a[3][5]=' '; a[3][6]='|'; a[3][7]=' '; a[3][8]='|';
            a[4][0]=' '; a[4][1]='-'; a[4][2]='-'; a[4][3]='-'; a[4][4]='-'; a[4][5]='-'; a[4][6]='-'; a[4][7]='-'; a[4][8]=' ';
            a[1][12]='H'; a[1][13]='e'; a[1][14]='a'; a[1][15]='l'; a[1][16]='t'; a[1][17]='h'; a[1][18]=':';
            a[2][12]='N'; a[2][13]=' '; a[2][14]='u'; a[2][15]='n'; a[2][16]='i'; a[2][17]='t'; a[2][18]=':';
            a[3][12]='A'; a[3][13]='r'; a[3][14]='m'; a[3][15]='o'; a[3][16]='r'; a[3][17]=':'; a[3][18]=' ';
            a[4][12]='S'; a[4][13]='t'; a[4][14]='e'; a[4][15]='p'; a[4][16]=':'; a[4][17]=' '; a[4][18]=' ';
            a[5][12]='R'; a[5][13]='a'; a[5][14]='n'; a[5][15]='g'; a[5][16]='e'; a[5][17]=':'; a[5][18]=' ';
            a[6][12]='A'; a[6][13]='t'; a[6][14]='t'; a[6][15]='a'; a[6][16]='c'; a[6][17]='k'; a[6][18]=':';
            a[7][12]='I'; a[7][13]='c'; a[7][14]='o'; a[7][15]='n'; a[7][16]=':'; a[7][17]=' '; a[7][18]=' ';
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<a[0][i]; cout<<" "; for(int i=12; i<19; i++) cout<<a[1][i]<<" ";  cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    LprintSymb+=printf("%.0f ", BASE->getCurrent()->getHit_Points());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    printf("%.0f ", BASE->getCurrent()->getHit_Points());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<a[1][i]; cout<<" "; for(int i=12; i<19; i++) cout<<a[2][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR()){
                    LprintSymb+=printf("%d   ", numb); numb++;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            numb=1;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR()){
                    printf("%d   ", numb); numb++;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<a[2][i]; cout<<" "; for(int i=12; i<19; i++) cout<<a[3][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    LprintSymb+=printf("%.0f   ", BASE->getCurrent()->getArmor());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    printf("%.0f   ", BASE->getCurrent()->getArmor());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<a[3][i]; cout<<" "; for(int i=12; i<19; i++) cout<<a[4][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getMove_Speed());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    printf("%d  ", BASE->getCurrent()->getMove_Speed());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<a[4][i]; cout<<" "; for(int i=12; i<19; i++) cout<<a[5][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getRange());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    printf("%d  ", BASE->getCurrent()->getRange());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=12; i<19; i++) cout<<a[6][i]<<" "; drawline(0, ' ', 18);
                BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getAttack());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR())
                    printf("%d  ", BASE->getCurrent()->getAttack());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=12; i<19; i++) cout<<a[7][i]<<" "; drawline(0, ' ', 18);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getARCHCR()){
                    LprintSymb+=printf("%c ", BASE->getCurrent()->getIcon()); break;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getARCHCR()){
                    printf("%c ", BASE->getCurrent()->getIcon()); break;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
             cout<<endl;
}

void spec()
{
    char s[8][19]; int numb=1;
            s[0][0]=' '; s[0][1]='_'; s[0][2]='_'; s[0][3]='_'; s[0][4]='_'; s[0][5]='_'; s[0][6]='_'; s[0][7]='_'; s[0][8]=' ';
            s[1][0]='|'; s[1][1]=' '; s[1][2]='\\'; s[1][3]=')'; s[1][4]='('; s[1][5]='/'; s[1][6]=' '; s[1][7]=' '; s[1][8]='|';
            s[2][0]='|'; s[2][1]=' '; s[2][2]=' '; s[2][3]='|'; s[2][4]='|'; s[2][5]=' '; s[2][6]=' '; s[2][7]=' '; s[2][8]='|';
            s[3][0]='|'; s[3][1]=' '; s[3][2]=' '; s[3][3]='|'; s[3][4]='|'; s[3][5]=' '; s[3][6]=' '; s[3][7]=' '; s[3][8]='|';
            s[4][0]=' '; s[4][1]='-'; s[4][2]='-'; s[4][3]='-'; s[4][4]='-'; s[4][5]='-'; s[4][6]='-'; s[4][7]='-'; s[4][8]=' ';
            s[1][12]='H'; s[1][13]='e'; s[1][14]='a'; s[1][15]='l'; s[1][16]='t'; s[1][17]='h'; s[1][18]=':';
            s[2][12]='N'; s[2][13]=' '; s[2][14]='u'; s[2][15]='n'; s[2][16]='i'; s[2][17]='t'; s[2][18]=':';
            s[3][12]='A'; s[3][13]='r'; s[3][14]='m'; s[3][15]='o'; s[3][16]='r'; s[3][17]=':'; s[3][18]=' ';
            s[4][12]='S'; s[4][13]='t'; s[4][14]='e'; s[4][15]='p'; s[4][16]=':'; s[4][17]=' '; s[4][18]=' ';
            s[5][12]='R'; s[5][13]='a'; s[5][14]='n'; s[5][15]='g'; s[5][16]='e'; s[5][17]=':'; s[5][18]=' ';
            s[6][12]='A'; s[6][13]='t'; s[6][14]='t'; s[6][15]='a'; s[6][16]='c'; s[6][17]='k'; s[6][18]=':';
            s[7][12]='I'; s[7][13]='c'; s[7][14]='o'; s[7][15]='n'; s[7][16]=':'; s[7][17]=' '; s[7][18]=' ';
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<s[0][i]; cout<<" "; for(int i=12; i<19; i++) cout<<s[1][i]<<" ";  cout<<"\t";
             BASE->setMOCurrent(BASE->getBegin());
             while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    LprintSymb+=printf("%.0f ", BASE->getCurrent()->getHit_Points());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    printf("%.0f ", BASE->getCurrent()->getHit_Points());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<s[1][i]; cout<<" "; for(int i=12; i<19; i++) cout<<s[2][i]<<" "; cout<<"\t";
             BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR()){
                    LprintSymb+=printf("%d   ", numb); numb++;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            numb=1;
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR()){
                    printf("%d   ", numb); numb++;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<s[2][i]; cout<<" "; for(int i=12; i<19; i++) cout<<s[3][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    LprintSymb+=printf("%.0f   ", BASE->getCurrent()->getArmor());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    printf("%.0f   ", BASE->getCurrent()->getArmor());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<s[3][i]; cout<<" "; for(int i=12; i<19; i++) cout<<s[4][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getMove_Speed());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    printf("%d  ", BASE->getCurrent()->getMove_Speed());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=0; i<9; i++) cout<<s[4][i]; cout<<" "; for(int i=12; i<19; i++) cout<<s[5][i]<<" "; cout<<"\t";
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getRange());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    printf("%d  ", BASE->getCurrent()->getRange());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=12; i<19; i++) cout<<s[6][i]<<" "; drawline(0, ' ', 18);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    LprintSymb+=printf("%d  ", BASE->getCurrent()->getAttack());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR())
                    printf("%d  ", BASE->getCurrent()->getAttack());
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            cout<<endl;
            LprintSymb=0;
            for(int i=12; i<19; i++) cout<<s[7][i]<<" "; drawline(0, ' ', 18);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='L' && BASE->getCurrent()->getCrush()==BASE->getSPECCR()){
                    LprintSymb+=printf("%c ", BASE->getCurrent()->getIcon()); break;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            drawline(0, ' ', 46-LprintSymb);
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getOwner()->getSide()=='R' && BASE->getCurrent()->getCrush()==BASE->getSPECCR()){
                    printf("%c ", BASE->getCurrent()->getIcon()); break;
                }
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
             cout<<endl;
}

void ChangeHeroesEyes(){
    for(int p=0; p<BASE->getPLENGTH(); p++){
    for(int i=0; i<I; i++){
        if(BASE->getPLAYERS()[p].getRace()==1 && BASE->getPLAYERS()[p].getLoser()==true)
        for(int j=0; j<JK; j++)
            if(h[i][j]=='o' ||  h[i][j]=='O' || h[i][j]=='(' || h[i][j]==')')
                h[i][j]='X';
        if(BASE->getPLAYERS()[p].getRace()==2 && BASE->getPLAYERS()[p].getLoser()==true)
        for(int j=0; j<JE; j++)
            if(elf[i][j]=='o' ||  elf[i][j]=='O' || elf[i][j]=='(' || elf[i][j]==')')
                elf[i][j]='X';
        if(BASE->getPLAYERS()[p].getRace()==3 && BASE->getPLAYERS()[p].getLoser()==true)
        for(int j=0; j<JO; j++)
            if(ork[i][j]=='o' ||  ork[i][j]=='O' || ork[i][j]=='(' || ork[i][j]==')')
                ork[i][j]='X';
    }
    }
}

 void drawline(int shift, char symbol, int length){
 	if(shift>0){
 	char* identation;
 	identation=new char[shift];
 	for(int i=0; i<shift; i++){
 		identation[i]=' ';
 		cout<<identation[i];
 	} delete []identation;
 	}
 	char* line;
 	line=new char[length];
 	for(int i=0; i<length; i++){
 		line[i]=symbol;
 		cout<<line[i];
 	} delete []line;
 }

    ~Interface(){
        for(int i=0; i<I; i++)
            delete []h[i];
        delete []h;
        for(int i=0; i<I; i++)
            delete []elf[i];
        delete []elf;
        for(int i=0; i<I; i++)
            delete []ork[i];
        delete []ork;

        for(int i=0; i<I; i++){
            delete []warriors[i];
            delete []archers[i];
            delete []special[i];
        }
        delete []warriors;
        delete []archers;
        delete []special;
    }

};
#endif // INTERFACE_H


