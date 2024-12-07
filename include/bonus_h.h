#ifndef BONUS_H_H
#define BONUS_H_H
#include "bonus.h"
#include <time.h>

class Bonus_H:public Bonus
{
    public:
         Bonus_H()
        {
            srand(time(0));
            Value_HP=20+rand()%30;
            Icon=char(43);
        }

        void Addbonus(MainObject* unit){
            Value_HP+=unit->getHit_Points();
            unit->setHealth(Value_HP);
        }

        ~Bonus_H()
        {
            //dtor
        }

    private:

};

#endif // BONUS_H_H
