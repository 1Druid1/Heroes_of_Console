#ifndef BONUS_H
#define BONUS_H
#include "MainObject.h"

class Bonus
{
    public:
//--------BEGINING OF FUNCTION----//
Bonus()
{
    //ctor
}

void setCoordinates(int i, int j){
    x=j; y=i;
}

int getX(){
    return x;
}

int getY(){
    return y;
}

//»конка на карте
char getIcon(){
    return Icon;
}

virtual void  Addbonus(MainObject* unit){

}


 virtual ~Bonus()
{
    //dtor
}
//--------END FUNCTION--------//
    protected:
    int x,y;
    double Value_bonus, Value_HP;
    char Icon;
    MainObject* unit;
    public:
        Bonus* next;
};

#endif // BONUS_H
