#ifndef HUMAN_SHOOTER_H
#define HUMAN_SHOOTER_H

class Human_Shooter:public MainObject
{
    public:
         Human_Shooter()
        {
            Hit_Points=100;
            Armor=1;
            Attack=4;
            Move_Speed=8;
            Range=10;
            Icon=char(195);
            Race=1; Crush=2;
        }

        ~Human_Shooter()
        {
            //dtor
        }
    private:

};

#endif // HUMAN_SHOOTER_H
