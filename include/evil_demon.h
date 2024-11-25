#ifndef EVIL_DEMON_H
#define EVIL_DEMON_H

class Evil_Demon:public MainObject
{
    public:
         Evil_Demon()
        {
            Hit_Points=100;
            Armor=4;
            Attack=4;
            FAttack=1;
            Range=6;
            Move_Speed=8;
            Icon=char(202);
            Race=3; Crush=3;
        }

        ~Evil_Demon()
        {
            //dtor
        }
    private:

};

#endif // EVIL_DEMON_H
