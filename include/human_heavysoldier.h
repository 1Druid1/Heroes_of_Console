#ifndef HUMAN_HEAVYSOLDIER_H
#define HUMAN_HEAVYSOLDIER_H

class Human_HeavySoldier:public MainObject
{
    public:
         Human_HeavySoldier()
        {
            Hit_Points=100;
            Armor=5;
            Attack=4;
            Range=0;
            Move_Speed=7;
            Icon=char(219);
            Race=1; Crush=3;
        }

        ~Human_HeavySoldier()
        {
            //dtor
        }
    protected:
    private:

};

#endif // HUMAN_HEAVYSOLDIER_H
