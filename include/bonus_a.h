#ifndef BONUS_A_H
#define BONUS_A_H
#include "bonus.h"
#include <time.h>
#include <windows.h>

class Bonus_A:public Bonus
{
    public:
    Bonus_A()
    {
    srand(time(0));
    Value_bonus=1+rand()%3;//random;
    Icon='A';
    }

void Addbonus(MainObject* unit){
    Value_bonus+=unit->getArmor();
    unit->setArmor(Value_bonus);
    }

 ~Bonus_A()
{
    //dtor
}
    private:
};

#endif // BONUS_A_H
