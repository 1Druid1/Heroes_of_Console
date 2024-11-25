#ifndef EVIL_WARRIOR_H
#define EVIL_WARRIOR_H

class Evil_Warrior:public MainObject
{
    public:
         Evil_Warrior()
        {
            Hit_Points=100;
            Armor=2;
            Attack=3;
            Range=0;
            Move_Speed=8;
            Icon=char(215);
            Race=3; Crush=1;
        }

         ~Evil_Warrior()
        {
            //dtor
        }
};

#endif // EVIL_WARRIOR_H
