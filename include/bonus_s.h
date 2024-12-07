#ifndef BONUS_S_H_INCLUDED
#define BONUS_S_H_INCLUDED

#include "bonus.h"
#include <time.h>


class Bonus_S:public Bonus
{
    public:
    Bonus_S()
    {
        srand(time(0));
        Value_bonus=1+rand()%4;//random;
        Icon='S';
    }

void Addbonus(MainObject* unit){
    Value_bonus+=unit->getMove_Speed();
    unit->setSpeed(int(Value_bonus));
}

 ~Bonus_S()
{
    //dtor
}
    private:
};

#endif // BONUS_S_H_INCLUDED
