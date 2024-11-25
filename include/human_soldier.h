#ifndef HUMAN_SOLDIER_H
#define HUMAN_SOLDIER_H

class Human_Soldier:public MainObject
{
    public:
        Human_Soldier()
        {
            Hit_Points=100;
            Armor=2;
            Attack=2;
            Range=0;
            Move_Speed=8;
            Icon=char(197);
            Race=1; Crush=1;
        }

        ~Human_Soldier()
        {
            //dtor
        }
    private:
};

#endif // HUMAN_SOLDIER_H
