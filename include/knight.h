#ifndef KNIGHT_H
#define KNIGHT_H

class Knight:public MainObject
{
    public:
        Knight()
        {
            Hit_Points=100;
            Armor=6;
            Attack=5;
            Move_Speed=20;
            Icon=char(206);
            Race=1;
            Crush=0;
            Range=0;
        }


        ~Knight()
        {
            //dtor
        }
    private:

};

#endif // KNIGHT_H
