#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "classmodulmain.h"
#include "WinnerAndLoser.h"
#include "HOC_LOGO.h"
using namespace std;

int main(int argc, char** argv) {
	system("TITLE HEROES OF CONSOLE");
	system("color 34");
	outLOGO();
	printf("\n\t\t\tDEVELOPED BY MAXIM ALEXEEV AND ARTYOM IVANOV. copyright 2015-2016\n\n");
	printf("\n\t\t\tVersion 1.0\n\n\t\t\t");
	system("PAUSE");
	system("color 07");
	system("cls");
	Interface display;
	//describing player's and bonus'es objects and War field
	ObjectBase base;
	base.createPlayers(2);
	base.setWARLENGTH(8);
	base.setARCHLENGTH(5);
	base.setSPECLENGTH(5);
	WarField field;
	field.setBase(&base);
	field.setDisplay(&display);
	display.setBase(&base);
	//INPUT NICK
	char nick[20], CollAnswer;
	for(int i=0; i<20; i++){
        nick[i]=' ';
	}   nick[19]='\0';
    //Entering of players nicknames
    for(int i=0; i<base.getPLENGTH(); i++){
        printf("+>Player %d, enter your nickname: ", i+1);
        scanf("%s", nick);
        base.getPLAYERS()[i].setnick(nick);
    }
    display.InitializeMenuItem();
    display.Menu();
    display.SideMenu();
    base.createLists();
    field.CreateStartPosition();
    CollAnswer=display.CollocationMenu();
    if(CollAnswer=='y') field.Collocation();
    field.GenerateUnits();
    system("cls");
    display.Avatarsonfield();
    display.HItems();
    field.outField();
    display.warrior();
    display.archer();
    display.spec();
    char  Picked_Unit, Picked_Way;
    int Picked_Action, Picked_Crush, Range, Picked_Step;
    //CYCLE OF PLAYERS ACTIONS
    while(field.Winner()!=true){
        field.BonusGenerator();
        Players *Ptemp=field.ControlPlayers();
        printf("\n\n|>%s, PRESS and choose an action:\n> 0-Skip movement\n> 1-Move unit\n> 2-Attack unit\n ", Ptemp->getNickname());
        Picked_Action=display.pressAction();
        system("cls");
        field.outField();
        switch(Picked_Action){
        case 1://MOVING
            printf("\n>%s, PRESS and pick CRUSH:\n <HERO - press 0; WARRIOR - press 1; ARCHER - press 2; SPECIAL - press 3>\n", Ptemp->getNickname());
            Picked_Crush=display.pressCrush();
            field.Choosing(Picked_Crush, Ptemp);
            system("cls");
            field.outField();
            printf("\n>PRESS a key and pick NUMBER of unit which will move:\n ");
            Picked_Unit=display.pressUnitNumb();
            printf("\n>PRESS a key and pick WAY of moving \n <DOWN or UP or RIGHT or LEFT>\n ");
            Picked_Way=display.pressWay();
            printf("\n>ENTER step of moving:\n|-> ");
            scanf("%d", &Picked_Step);
            if(field.Moving_Units(Picked_Way, Picked_Step, Picked_Unit)==0)
                printf("\nSorry, invalid step.\n");
            break;
            case 2://ATTACK
                printf("\n%s,PRESS a key and choose CRUSH which will attack\n <0-Hero, 1-warriors, 2-Archers, 3-Special>\n ", Ptemp->getNickname());
                Picked_Crush=display.pressCrush();
                field.Choosing(Picked_Crush, Ptemp);
                system("cls");
                field.outField();
                printf("\n>PRESS and pick NUMBER of unit which will attack:\n ");
                Picked_Unit=display.pressUnitNumb();
                printf("\n>PRESS a key and pick WAY of moving\n <DOWN or UP or RIGHT or LEFT>\n|-> ");
                Picked_Way=display.pressWay();
                Range=display.DefineUnitRange(Picked_Crush, Ptemp);
                if(Range==0) field.fellowAttack(Picked_Way, Picked_Unit);
                else field.RangeAttack(Picked_Way, Picked_Unit);
            break;
        }
        system("cls");
        display.Avatarsonfield();
        display.HItems();
        field.outField();
        display.warrior();
        display.archer();
        display.spec();
    }
    cout<<'\007';
    display.ChangeHeroesEyes();
    system("cls");
    display.Avatarsonfield();
    field.outField();
    cout<<endl;
    system("PAUSE");
    system("color 47");
    system("cls");
    display.drawline(0, '#', 40); cout<<endl;
    WinnerPicture();
    printf("\n\t*WINNERS*\n");
    for(int i=0; i<base.getPLENGTH(); i++)
        if(base.getPLAYERS()[i].getWinner()==true) printf("\t%s, YOU WIN!", base.getPLAYERS()[i].getNickname());
    cout<<endl<<endl;
    display.drawline(0, '#', 40); cout<<endl;
    LoserPicture();
    printf("\n\t*LOSERS*\n");
    for(int i=0; i<base.getPLENGTH(); i++)
        if(base.getPLAYERS()[i].getLoser()==true) printf("\t%s, YOU LOSE!\n\n", base.getPLAYERS()[i].getNickname());
    display.drawline(0, '#', 40); cout<<endl;
    system("PAUSE");
    return 0;
}
