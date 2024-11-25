#ifndef EVIL_HERO_H
#define EVIL_HERO_H

class Evil_Hero:public MainObject
{
    public:
         Evil_Hero()
        {
            Hit_Points=100;
            Armor=5;
            Attack=5;
            Move_Speed=14;
            Icon=char(253);
            Race=3; Crush=0;
            Range=0;
        }

        ~Evil_Hero()
        {
            //dtor
        }
    private:
};

#endif // EVIL_HERO_H
