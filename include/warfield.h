#ifndef WARFIELD_H
#define WARFIELD_H
#include <stdbool.h>
#include <time.h>
#include "Bonus.h"
#include "Bonus_A.h"
#include "Bonus_H.h"
#include "Players.h"
#include "objectbase.h"
#include "Interface.h"

class WarField
{
    public:
       WarField() {
        Field=new char*[HEIGHT];
        for (int i=0; i<HEIGHT; i++)
            Field[i]=new char[WEIGHT];

        FlagField=new bool* [HEIGHT];
        for (int i=0; i<HEIGHT; i++)
            FlagField[i]=new bool[WEIGHT];

        BonusField=new bool* [HEIGHT];
        for (int i=0; i<HEIGHT; i++)
            BonusField[i]=new bool[WEIGHT];

    //Initialization massive of coordinates.
        for(int i=0; i<HEIGHT; i++){
            for(int j=0; j<WEIGHT; j++)
                Field[i][j]=' ';
        }

    //Logic massive, TRUE-used, FALSE-unused.
        for(int i=0; i<HEIGHT; i++)
        {
            for(int j=0; j<WEIGHT; j++)
                FlagField[i][j]=false;
        }
        for(int i=0; i<HEIGHT; i++)
        {
            for(int j=0; j<WEIGHT; j++)
                BonusField[i][j]=false;
        }
        Move_ment_counter=0;
}

    void setDisplay(Interface* disp){
        Display=disp;
    }

    //Setting base of object
    void setBase(ObjectBase* base){
        BASE=base;
    }

    //Starting position
    void CreateStartPosition(){
        yHL=17;    xHL=3;
        yWL=15;    xWL=5;
        yAL=15;    xAL=2;
        ySL=8;    xSL=5;

        yHR=17;   xHR=WEIGHT-5;
        yWR=15;   xWR=WEIGHT-8;
        yAR=8;    xAR=WEIGHT-4;
        ySR=15;   xSR=WEIGHT-7;
    }

    void Collocation(){
        char c, NonActiveMarker='x', ActiveMarker='*';
        int *pointerY, *pointerX, crushLength, wayX, wayY, FantomStep=1;
        int UpBorder, DownBorder, RightBorder, LeftBorder, Up=-1, Down=1, Left=-1, Right=1;
        bool Busy;
        for(int i=0; i<BASE->getPLENGTH(); i++){
                switch(BASE->getPLAYERS()[i].getSide()){//Initialization of coordinates
                case 'L':
                    pointerY=&yHL; pointerX=&xHL; crushLength=3;
                    UpBorder=0; DownBorder=HEIGHT; RightBorder=UpBorder+29; LeftBorder=0;
                    for(int depos=0; depos<3; depos++){
                        FlagField[yHL+depos][xHL]=true;
                        Field[yHL+depos][xHL]='x';
                    }
                    for(int depos=0; depos<9; depos++){
                        FlagField[yWL+depos][xWL]=true;
                        Field[yWL+depos][xWL]='x';
                    }
                    for(int depos=0; depos<9; depos++){
                        FlagField[yAL+depos][xAL]=true;
                        Field[yAL+depos][xAL]='x';
                    }
                    for(int depos=0; depos<6; depos++){
                        FlagField[ySL+depos][xSL]=true;
                        Field[ySL+depos][xSL]='x';
                    }
                    break;
                case 'R':
                    pointerY=&yHR; pointerX=&xHR; crushLength=3;
                    UpBorder=0; DownBorder=HEIGHT; RightBorder=WEIGHT; LeftBorder=WEIGHT-29;
                    for(int depos=0; depos<3; depos++){
                        FlagField[yHR+depos][xHR]=true;
                        Field[yHR+depos][xHR]='x';
                    }
                    for(int depos=0; depos<9; depos++){
                        FlagField[yWR+depos][xWR]=true;
                        Field[yWR+depos][xWR]='x';
                    }
                    for(int depos=0; depos<9; depos++){
                        FlagField[yAR+depos][xAR]=true;
                        Field[yAR+depos][xAR]='x';
                    }
                    for(int depos=0; depos<6; depos++){
                        FlagField[ySR+depos][xSR]=true;
                        Field[ySR+depos][xSR]='x';
                    }
                    break;
                }
                for(int j=0; j<crushLength; j++)
                    Field[*pointerY+j][*pointerX]=ActiveMarker;
                system("cls");
                outField();
        while(c!=13){//Cycle where Collocation will did
            printf("\n\tCONTROL:\n PRESS 0 or 1 or 2 or 3 to choose crush\n PRESS UP or DOWN or LEFT or RIGHT to move crush"
               "\n PRESS '+' or '-' to expand or discount step of moving.\n");
            c=getch();
            switch(c){//
                case 75://<
                    wayY=0; wayX=Left;
                    if(*pointerX+wayX>=LeftBorder){
                        for(int j=0; j<crushLength; j++)
                            if(FlagField[*pointerY+wayY+j][*pointerX+wayX]==true){
                                Busy=true; break;
                            }
                        if(Busy!=true){
                            for(int j=0; j<crushLength; j++){
                                Field[*pointerY+wayY+j][*pointerX+wayX]=ActiveMarker;
                                Field[*pointerY+j][*pointerX]=' ';
                                FlagField[*pointerY+wayY+j][*pointerX+wayX]=true;
                                FlagField[*pointerY+j][*pointerX]=false;
                            }
                            *pointerY+=wayY;
                            *pointerX+=wayX;
                        }
                        else Busy=false;
                    }
                break;
                case 77://>
                    wayY=0; wayX=Right;
                    if(*pointerX+wayX<RightBorder){
                        for(int j=0; j<crushLength; j++)
                            if(FlagField[*pointerY+wayY+j][*pointerX+wayX]==true){
                                Busy=true; break;
                            }
                        if(Busy!=true){
                            for(int j=0; j<crushLength; j++){
                                Field[*pointerY+wayY+j][*pointerX+wayX]=ActiveMarker;
                                Field[*pointerY+j][*pointerX]=' ';
                                FlagField[*pointerY+wayY+j][*pointerX+wayX]=true;
                                FlagField[*pointerY+j][*pointerX]=false;
                            }
                            *pointerY+=wayY;
                            *pointerX+=wayX;
                        }
                        else Busy=false;
                    }
                break;
                case 80://v
                    wayY=Down; wayX=0;
                    if(*pointerY+crushLength+wayY<DownBorder){
                            if(FlagField[*pointerY+wayY+crushLength-1][*pointerX+wayX]==true)
                                Busy=true;
                        if(Busy!=true){
                            for(int j=0; j<crushLength; j++){
                                FlagField[*pointerY+j][*pointerX]=false;
                                Field[*pointerY+j][*pointerX]=' ';
                            }
                            *pointerY+=wayY;
                            *pointerX+=wayX;
                            for(int j=0; j<crushLength; j++){
                                Field[*pointerY+j][*pointerX]=ActiveMarker;
                                FlagField[*pointerY+j][*pointerX]=true;
                            }

                        }
                        else Busy=false;
                    }
                break;
                case 72://^
                    wayY=Up; wayX=0;
                    if(*pointerY+wayY>=UpBorder){
                            if(FlagField[*pointerY+wayY][*pointerX+wayX]==true)
                                Busy=true;
                        if(Busy!=true){
                            for(int j=0; j<crushLength; j++){
                                Field[*pointerY+j][*pointerX]=' ';
                                FlagField[*pointerY+j][*pointerX]=false;
                            }
                            *pointerY+=wayY;
                            *pointerX+=wayX;
                            for(int j=0; j<crushLength; j++){
                                Field[*pointerY+j][*pointerX]=ActiveMarker;
                                FlagField[*pointerY+j][*pointerX]=true;
                            }

                        }
                        else Busy=false;
                    }
                break;
                case '0'://choosing Hero crush
                    for(int j=0; j<crushLength; j++)
                        Field[*pointerY+j][*pointerX]=NonActiveMarker;
                    if(BASE->getPLAYERS()[i].getSide()=='L') { pointerY=&yHL; pointerX=&xHL;}
                    else if(BASE->getPLAYERS()[i].getSide()=='R') {pointerY=&yHR; pointerX=&xHR;}
                    crushLength=3;
                    break;
                case '1'://choosing Warrior crush
                    for(int j=0; j<crushLength; j++)
                        Field[*pointerY+j][*pointerX]=NonActiveMarker;
                    if(BASE->getPLAYERS()[i].getSide()=='L') { pointerY=&yWL; pointerX=&xWL;}
                    else if(BASE->getPLAYERS()[i].getSide()=='R') {pointerY=&yWR; pointerX=&xWR;}
                    crushLength=9;
                    break;
                case '2':// choosing Archers crush
                    for(int j=0; j<crushLength; j++)
                        Field[*pointerY+j][*pointerX]=NonActiveMarker;
                    if(BASE->getPLAYERS()[i].getSide()=='L') { pointerY=&yAL; pointerX=&xAL;}
                    else if(BASE->getPLAYERS()[i].getSide()=='R') {pointerY=&yAR; pointerX=&xAR;}
                    crushLength=9;
                    break;
                case '3':// choosing Special crush
                    for(int j=0; j<crushLength; j++)
                        Field[*pointerY+j][*pointerX]=NonActiveMarker;
                    if(BASE->getPLAYERS()[i].getSide()=='L') { pointerY=&ySL; pointerX=&xSL;}
                    else if(BASE->getPLAYERS()[i].getSide()=='R') {pointerY=&ySR; pointerX=&xSR;}
                    crushLength=6;
                    break;
                case '+'://to expand step
                    if(FantomStep<4){
                        FantomStep++;
                        Up--; Down++; Left--; Right++;
                    }
                    break;
                case '-'://to discount step
                    if(FantomStep>0){
                        FantomStep--;
                        Up++; Down--; Left++; Right--;
                    }
                    break;
            }
            for(int j=0; j<crushLength; j++)//Make new chose crush active
                Field[*pointerY+j][*pointerX]=ActiveMarker;
            system("cls");
            outField();
        }
        for(int j=0; j<crushLength; j++)//Make new chose crush active
                Field[*pointerY+j][*pointerX]=NonActiveMarker;
        c=0;//reset pressed key
    }
    for(int j=0; j<HEIGHT; j++){//to clear the Field from crush'es fantoms
        for(int k=0; k<WEIGHT; k++){
            FlagField[j][k]=false;
            Field[j][k]=' ';
    }
    }
    }

    //Generating coordinates for units
    void GenerateUnits(){
        int deposition=0;
        bool UnitTakePosition=false;
        BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
            switch(BASE->getCurrent()->getOwner()->getSide()){
               case 'L':
                    if(BASE->getCurrent()->getCrush()==BASE->getHEROCR()){
                            while(UnitTakePosition!=true){
                                if(FlagField[yHL+deposition][xHL]!=true){
                                    BASE->getCurrent()->setXY(yHL+deposition, xHL);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    UnitTakePosition=true;
                                    deposition=0;
                                }
                                else deposition++;
                            }
                    }
                     else if(BASE->getCurrent()->getCrush()==BASE->getWARCR()){
                            while (UnitTakePosition!=true) {
                                if(FlagField[yWL+deposition][xWL]!=true){
                                    BASE->getCurrent()->setXY(yWL+deposition, xWL);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    UnitTakePosition=true;
                                    deposition=0;
                                }
                                else deposition++;
                            }
                     }
                    else if(BASE->getCurrent()->getCrush()==BASE->getARCHCR()){
                            while(UnitTakePosition!=true) {
                                if(FlagField[yAL+deposition][xAL]!=true){
                                    BASE->getCurrent()->setXY(yAL+deposition, xAL);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    UnitTakePosition=true;
                                    deposition=0;
                                }
                                else deposition++;
                            }
                    }
                    else if(BASE->getCurrent()->getCrush()==BASE->getSPECCR()){
                            while (UnitTakePosition!=true){
                                if(FlagField[ySL+deposition][xSL]!=true){
                                    BASE->getCurrent()->setXY(ySL+deposition, xSL);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    deposition=0;
                                    UnitTakePosition=true;
                                }
                                else deposition++;
                            }
                    }
                    break;
                case 'R':
                    if(BASE->getCurrent()->getCrush()==BASE->getHEROCR()){
                            while(UnitTakePosition!=true) {
                                if(FlagField[yHR+deposition][xHR]!=true){
                                    BASE->getCurrent()->setXY(yHR+deposition, xHR);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    deposition=0;
                                    UnitTakePosition=true;
                                }
                                else deposition++;
                            }
                    }
                     else if(BASE->getCurrent()->getCrush()==BASE->getWARCR()){
                            while(UnitTakePosition!=true) {
                                if(FlagField[yWR+deposition][xWR]!=true){
                                    BASE->getCurrent()->setXY(yWR+deposition, xWR);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    deposition=0;
                                    UnitTakePosition=true;
                                }
                                else deposition++;
                            }
                     }
                    else if(BASE->getCurrent()->getCrush()==BASE->getARCHCR()){
                            while(UnitTakePosition!=true){
                                if(FlagField[yAR+deposition][xAR]!=true){
                                    BASE->getCurrent()->setXY(yAR+deposition, xAR);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    deposition=0;
                                    UnitTakePosition=true;
                                }
                                else deposition++;
                            }
                    }
                    else if(BASE->getCurrent()->getCrush()==BASE->getSPECCR()){
                            while(UnitTakePosition!=true) {
                                if(FlagField[ySR+deposition][xSR]!=true){
                                    BASE->getCurrent()->setXY(ySR+deposition, xSR);
                                    Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                                    FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=true;
                                    deposition=0;
                                    UnitTakePosition=true;
                                }
                                else deposition++;
                            }
                    }
                    break;
            }
            UnitTakePosition=false;
            BASE->setMOCurrent(BASE->getCurrent()->next);
        }
    }

    //Function which get to bonus his coordinates on the Field.
    void GenerateBonus()
    {
        int i,j;
        BASE->setBCurrent(BASE->getBBegin());
        while(BASE->getBCurrent()!=0){
            srand(time(0));
            i=int(0+rand()%24); j=int(25+rand()%58);
            while(FlagField[i][j]==true || BonusField[i][j]==true){
                while((i<0 || i>=HEIGHT) || (j>=WEIGHT || j<0))
                    i=int(0+rand()%24); j=int(25+rand()%58);
            }
        BASE->getBCurrent()->setCoordinates(i,j);
        Field[i][j]=BASE->getBCurrent()->getIcon();
        BonusField[i][j]=true;
        BASE->setBCurrent(BASE->getBCurrent()->next);
        }
    }

    //Function of adopting numbers.
    void Choosing (int crush, Players* player)
    {
        int sum=1;
        BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
            if(BASE->getCurrent()->getCrush()==crush && BASE->getCurrent()->getOwner()==player){
                Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=char(sum+48);
                sum++;
            }
            BASE->setMOCurrent(BASE->getCurrent()->next);
        }
    }

//-----------------------------------------------------------------------------------------------//
    //Function which make chose unit and his moving
          //Function which make chose unit and his moving
    int Moving_Units(char way, int step, char compare_numb){
        int Y=0, X=0; bool Flag=false;//coordinates will adopted here, Flag-give signal about incorrect way
        int wayY=0, wayX=0;//it will summing step, index-number of object which was chosen by our
        if(step!=0){
            //COMPARE UNITS WITH COMPARING NUMBER
            BASE->setMOCurrent(BASE->getBegin());
                while(BASE->getCurrent()!=0){
                    if(Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]==compare_numb){
                        Y=BASE->getCurrent()->getY();
                        X=BASE->getCurrent()->getX();
                        BASE->setMOTemp(BASE->getCurrent());
                        break;
                    }
                    BASE->setMOCurrent(BASE->getCurrent()->next);
                }
        if(step<=BASE->getCurrent()->getMove_Speed()){
        //here summing step get his values
            switch(way){
                case '<':
                    if((X-step)>=0) wayX=-1;
                    else {Flag=true; ReturningIcons(); return 0;}
                break;
                case '>':
                    if((X+step)<WEIGHT) wayX=1;
                    else {Flag=true; ReturningIcons(); return 0;}
                break;
                case '^':
                    if((Y-step)>=0) wayY=-1;
                    else {Flag=true; ReturningIcons(); return 0;}
                break;
                case 'v':
                    if((Y+step)<HEIGHT) wayY=1;
                    else {Flag=true; ReturningIcons(); return 0;}
                break;
                default:
                    Flag=true;
                    ReturningIcons();
                return 0;
            break;
        }
        }
        else Flag=true;
        //checking coordinates out Field
        if(Flag==false){
        //checking coordinates
        for(int i=1, tempY=Y, tempX=X; i<=step; i++){
            if(FlagField[tempY+wayY][tempX+wayX]!=false){
                Flag=true;
                ReturningIcons();
                break;
            }
            tempY+=wayY; tempX+=wayX;
        }
        if(Flag==false){
        FlagField[Y][X]=false;
        ReturningIcons();
        //Animation
        for(int i=1; i<=step; i++){
                if(BonusField[Y+wayY][X+wayX]==true){
                    DefineBonusByCoords(Y+wayY, X+wayX)->Addbonus(BASE->getTemp());
                    DeleteBonus(Y+wayY, X+wayX);
                }
            	Field[Y+wayY][X+wayX]=Field[Y][X];
                Field[Y][X]=' ';
                Y+=wayY;
                X+=wayX;
                Sleep(150);
                system("cls");
                outField();
        }
        FlagField[Y][X]=true;
        BASE->getTemp()->setXY(Y, X);
        return 1;
        }
        else {
            ReturningIcons();//returning original icons
            return 0;
        }
        }
        else {
            ReturningIcons();//returning original icons
            return 0;
        }
        }
        else return 0;
    }
//-----------------------------------------------------------------------------------------------

//*****************ATTACKS***********************

//BEGIN OF DAMAGING///
int fellowAttack(char way, char numb){

    int Y=0, X=0, tempY=0, tempX=0; bool Flag=false;
    int wayY=0, wayX=0; char sword;
    BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
            //checking compliance of unit with number
            if(Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]==numb){
                Y=BASE->getCurrent()->getY();
                X=BASE->getCurrent()->getX();
                tempY=Y; tempX=X;
                BASE->setHpfPointer(BASE->getCurrent());
                break;
            }
            BASE->setMOCurrent(BASE->getCurrent()->next);
        }
         //here summing step get his values
         switch(way){
            case '<':
                wayX=-1; sword=char(195);
                if((X-1)<0) {Flag=true;}
            break;
            case '>':
                wayX=1; sword=char(218);
                if((X+1)>=WEIGHT) {Flag=true;}
            break;
            case '^':
                wayY=-1; sword=char(209);
                if((Y-1)<0) {Flag=true;}
            break;
            case 'v':
                wayY=1; sword=char(207);
                if((Y+1)>=HEIGHT) {Flag=true;}
            break;
            default:
                Flag=true;
                ReturningIcons();
                return -1;
            break;
        }
        ReturningIcons();
        if(Flag==false){
        //Animation
        Field[Y][X]=sword;
        for(int i=1; i<=2; i++){
                if(FlagField[Y+wayY][X+wayX]==true && BonusField[Y+wayY][X+wayX]!=true){
                    DefineUnitByCoords(Y+wayY, X+wayX)->Damage(BASE->getHpfPointer()->getAttack());
                    DeleteUnit();
                    break;
                }
                else if(FlagField[Y+wayY][X+wayX]==false) Field[Y][X]=' ';
            	Field[Y+wayY][X+wayX]=Field[Y][X];
                Y+=wayY;
                X+=wayX;
                Field[BASE->getHpfPointer()->getY()][BASE->getHpfPointer()->getX()]=BASE->getHpfPointer()->getIcon();
                Sleep(20);
                system("cls");
                outField();
        }
        ReturningIcons();
        return 1;
        }
        else return 0;
}

//Range attack///
int RangeAttack(char wayofshooting, char numb){
        int Y=0, X=0, tempY, tempX; bool Flag=false;//coordinates will adopted here, Flag-give signal about incorrect way
        int wayY=0, wayX=0; char arrow;//it will summing step, index-number of object which was chosen by our
        int tempRange;
        //cycle on crush's objects
        BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
            //checking compliance of unit with number
            if(Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]==numb){
                Y=BASE->getCurrent()->getY();
                X=BASE->getCurrent()->getX();
                tempY=Y; tempX=X;
                BASE->setHpfPointer(BASE->getCurrent());
                break;
            }
            BASE->setMOCurrent(BASE->getCurrent()->next);
        }
        tempRange=BASE->getCurrent()->getRange();
         //here summing step get his values
         switch(wayofshooting){
            case '<':
                wayX=-1; arrow='-';
                if((X-BASE->getCurrent()->getRange())<0) tempRange+=X-BASE->getCurrent()->getRange();
            break;
            case '>':
                wayX=1; arrow='-';
                if((X+BASE->getCurrent()->getRange())>=WEIGHT) tempRange=WEIGHT-X-1;
            break;
            case '^':
                wayY=-1; arrow='|';
                if((Y-BASE->getCurrent()->getRange())<0) tempRange+=Y-BASE->getCurrent()->getRange();
            break;
            case 'v':
                wayY=1; arrow='|';
                if((Y+BASE->getCurrent()->getRange())>=HEIGHT) tempRange=HEIGHT-Y-1;
            break;
            default:
                Flag=true;
                ReturningIcons();
                return -1;
            break;
        }
        ReturningIcons();
        if(Flag==false){
        //Animation
        Field[Y][X]=arrow;
        for(int i=1; i<=tempRange; i++){
                 if(FlagField[Y+wayY][X+wayX]==true && BonusField[Y+wayY][X+wayX]!=true){
                    DefineUnitByCoords(Y+wayY, X+wayX)->Damage(BASE->getHpfPointer()->getAttack());
                    DeleteUnit();
                    break;
                }
            	Field[Y+wayY][X+wayX]=Field[Y][X];
                Field[Y][X]=' ';
                Y+=wayY;
                X+=wayX;
                Field[BASE->getHpfPointer()->getY()][BASE->getHpfPointer()->getX()]=BASE->getHpfPointer()->getIcon();
                //Sleep(20);
                system("cls");
                outField();
        }
        Field[Y][X]=' ';
        ReturningIcons();
        return 1;
        }
        else return 0;
}

//------------------ENDATTACKS--------------------
    //Function which return original icons.
    void ReturningIcons(){
        BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
                Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=BASE->getCurrent()->getIcon();
                BASE->setMOCurrent(BASE->getCurrent()->next);
    }
    }
    //Function players queue
    Players* ControlPlayers(){
        Move_ment_counter--;
        BonusLife_counter--;
        if(BASE->getPLAYERS()[BASE->getPLENGTH()-1].getPStep()==true){
            for(int i=0; i<BASE->getPLENGTH(); i++)
                BASE->getPLAYERS()[i].setPStep(false);
        }
        for(int i=0; i<BASE->getPLENGTH(); i++){
            if(BASE->getPLAYERS()[i].getPStep()==false){
                BASE->getPLAYERS()[i].setPStep(true);
                return &(BASE->getPLAYERS()[i]); break;
            }
        }
    }

    bool Winner(){
        bool Hero;
        int Loser_count=0;
        for(int i=0; i<BASE->getPLENGTH();i++){
            Hero=false;
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getCrush()==BASE->getHEROCR() && BASE->getCurrent()->getOwner()==(&(BASE->getPLAYERS()[i])))
                    Hero=true;
                BASE->setMOCurrent(BASE->getCurrent()->next);
            }
            if(Hero==false) {
                    BASE->getPLAYERS()[i].setLoser(true);
                    Loser_count++;
            }
        }
        return defineWinner(Loser_count);
    }

    //Function which delete death units.
    void DeleteUnit()
    {
        BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
            if(BASE->getCurrent()->getHit_Points()<=0) {
                Field[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]='X';
                FlagField[BASE->getCurrent()->getY()][BASE->getCurrent()->getX()]=false;
                if(BASE->getCurrent()==BASE->getBegin() && BASE->getCurrent()==BASE->getEnd()){
                    delete BASE->getBegin();
                    BASE->setMOBegin(NULL);
                    BASE->setMOCurrent(NULL);
                    BASE->setMOEnd(NULL);
                }
                else {
                    if(BASE->getCurrent()==BASE->getBegin()){
                        BASE->setMOTemp(BASE->getCurrent());
                        if(BASE->getBegin()->next!=0) {
                            BASE->setMOBegin(BASE->getBegin()->next);
                            BASE->setMOCurrent(BASE->getBegin());
                        }
                        delete BASE->getTemp();
                }
                else if(BASE->getCurrent()==BASE->getEnd()){
                        BASE->setMOTemp(BASE->getBegin());
                        while(BASE->getTemp()->next!=BASE->getEnd()) BASE->setMOTemp(BASE->getTemp()->next);
                        BASE->setMOEnd(BASE->getTemp());
                        BASE->setMOTemp(BASE->getTemp()->next);
                        BASE->getEnd()->next=0;
                        delete BASE->getTemp();
                        BASE->setMOCurrent(NULL);
                        BASE->setMOTemp(BASE->getEnd());
                }
                else{
                        BASE->setMOTemp(BASE->getBegin());
                        while(BASE->getTemp()->next!=BASE->getCurrent()) BASE->setMOTemp(BASE->getTemp()->next);
                        BASE->getTemp()->next=BASE->getCurrent()->next;
                        delete BASE->getCurrent();
                        BASE->setMOCurrent(BASE->getTemp()->next);
                }
        }
        }
        if(BASE->getCurrent()!=NULL)  BASE->setMOCurrent(BASE->getCurrent()->next);
    }
    }

    void DeleteBonus(int Y, int X)
    {
        BASE->setBCurrent(BASE->getBBegin());
        while(BASE->getBCurrent()!=0){
            if(BASE->getBCurrent()->getX()==X && BASE->getBCurrent()->getY()==Y) {
                Field[BASE->getBCurrent()->getY()][BASE->getBCurrent()->getX()]=' ';
                BonusField[BASE->getBCurrent()->getY()][BASE->getBCurrent()->getX()]=false;
                if(BASE->getBCurrent()==BASE->getBBegin() && BASE->getBCurrent()==BASE->getBEnd()){
                    delete BASE->getBBegin();
                    BASE->setBBegin(NULL);
                    BASE->setBCurrent(NULL);
                    BASE->setBEnd(NULL);
                }
                else {
                    if(BASE->getBCurrent()==BASE->getBBegin()){
                        BASE->setBTemp(BASE->getBCurrent());
                        if(BASE->getBBegin()->next!=0) {
                            BASE->setBBegin(BASE->getBBegin()->next);
                            BASE->setBCurrent(BASE->getBBegin());
                        }
                        delete BASE->getBTemp();
                }
                else if(BASE->getBCurrent()==BASE->getBEnd()){
                        BASE->setBTemp(BASE->getBBegin());
                        while(BASE->getBTemp()->next!=BASE->getBEnd()) BASE->setBTemp(BASE->getBTemp()->next);
                        BASE->setBEnd(BASE->getBTemp());
                        BASE->setBTemp(BASE->getBTemp()->next);
                        BASE->getBEnd()->next=0;
                        delete BASE->getBTemp();
                        BASE->setBCurrent(NULL);
                        BASE->setBTemp(BASE->getBEnd());
                }
                else{
                        BASE->setBTemp(BASE->getBBegin());
                        while(BASE->getBTemp()->next!=BASE->getBCurrent()) BASE->setBTemp(BASE->getBTemp()->next);
                        BASE->getBTemp()->next=BASE->getBCurrent()->next;
                        delete BASE->getBCurrent();
                        BASE->setBCurrent(BASE->getBTemp()->next);
                }
        }
        }
        if(BASE->getBCurrent()!=NULL)  BASE->setBCurrent(BASE->getBCurrent()->next);
    }
    }

    void BonusGenerator(){
        if(Move_ment_counter==0){
            srand(time(0));
            Move_ment_counter=int(12+rand()%20);
            srand(time(0));
            int NumberofBonus=int(1+rand()%2);
            for(int i=1, fortune; i<=NumberofBonus; i++){
                srand(time(0));
                fortune=int(1+rand()%3);
                switch(fortune){
                case 1:
                    BASE->Add_H_BonusToList();
                    break;
                case 2:
                    BASE->Add_A_BonusToList();
                    break;
                case 3:
                    BASE->Add_S_BonusToList();
                    break;
                }
            }
            BonusLife_counter=BONUSLIFE;
            GenerateBonus();
        }
        else if(BonusLife_counter==0)
                DeleteBonusList();
    }

    void outField(){
        Display->drawline(9,'-',WEIGHT);
        cout<<endl;
    for(int i=0; i<HEIGHT; i++){
            cout<<'\t'<<'|';
        for(int j=0; j<WEIGHT; j++)
            cout<<Field[i][j];
            cout<<'|'<<endl;
        }
        Display->drawline(9,'-',WEIGHT);
    }

    void DeleteBonusList(){
        if(BASE->getBBegin()!=NULL){
            while(BASE->getBBegin()!=0){
                Field[BASE->getBBegin()->getY()][BASE->getBBegin()->getX()]=' ';
                BonusField[BASE->getBBegin()->getY()][BASE->getBBegin()->getX()]=false;
                BASE->setBTemp(BASE->getBBegin());
                BASE->setBBegin(BASE->getBBegin()->next);
                delete BASE->getBTemp();
            }
            BASE->setBBegin(NULL);
            BASE->setBEnd(NULL);
        }
    }

    ~WarField()
    {
        for (int i=0; i<HEIGHT; i++)
            delete [] Field[i];
        delete [] Field;

        for (int i=0; i<HEIGHT; i++)
            delete [] FlagField[i];
        delete [] FlagField;

        for (int i=0; i<HEIGHT; i++)
            delete [] BonusField[i];
        delete [] BonusField;
    }
    private:
        int const HEIGHT=25;
        int const WEIGHT=100;
        int const BONUSLIFE=5;
        char **Field;
        bool **FlagField, **BonusField;
        ObjectBase* BASE;
        int Move_ment_counter, BonusLife_counter;
        /*Starting positions left*/
        int xHL, yHL, xWL, yWL, xAL, yAL, xSL, ySL;
        /*Starting positions right*/
        int xHR, yHR, xWR, yWR, xAR, yAR, xSR, ySR;
        Interface* Display;
        //PRIVATE FUNCTIONS:
    bool defineWinner(int counter){
        if((BASE->getPLENGTH()-counter)==1){
            BASE->setMOCurrent(BASE->getBegin());
            while(BASE->getCurrent()!=0){
                if(BASE->getCurrent()->getCrush()==BASE->getHEROCR() && BASE->getCurrent()->getHit_Points()>0){
                    BASE->getCurrent()->getOwner()->setWinner(true);
                    return true;
                    break;
                }
            BASE->setMOCurrent(BASE->getCurrent()->next);
            }
        }
        return false;
    }

    Bonus* DefineBonusByCoords(int i, int j){
        BASE->setBCurrent(BASE->getBBegin());
        while(BASE->getBCurrent()!=0){
            if(BASE->getBCurrent()->getY()==i && BASE->getBCurrent()->getX()==j){
                return BASE->getBCurrent(); break;
            }
            BASE->setBCurrent(BASE->getBCurrent()->next);
        }
    }

    MainObject* DefineUnitByCoords(int i, int j){
        BASE->setMOCurrent(BASE->getBegin());
        while(BASE->getCurrent()!=0){
            if(BASE->getCurrent()->getY()==i && BASE->getCurrent()->getX()==j){
                return BASE->getCurrent(); break;
            }
            BASE->setMOCurrent(BASE->getCurrent()->next);
        }
    }
};

#endif // WARFIELD_H
