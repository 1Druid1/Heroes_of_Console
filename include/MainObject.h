#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED

#include "players.h"
class MainObject
{
protected:
    /*Crush values: Race values:
          0-Hero
          1-Warriors    1-Humans
          2-Archers     2-Elf
          3-Special     3-Evil*/
    int x, y;
    double Hit_Points, Armor;
    int Move_Speed, Attack, Race, Crush, Range;
    char Icon;
    Players* Owner;
    int FAttack;
    int RAttack;
    public:
    MainObject* next;

    MainObject(){

    }

   void Damage(int Attack_Enemy)
    {
        const double TEN=10.0;
        double Damage;
        Damage=(Attack_Enemy/Armor)*TEN;
        Hit_Points=double(Hit_Points-Damage);
    }

   void setXY(int i, int j){
        x=j;
        y=i;
    }

    void setRace(int number){
        Race=number;
    }

    void setHealth(double value){
        Hit_Points=value;
    }

    void setArmor(double value){
        Armor=value;
    }

    void setSpeed(int Speed){
        Move_Speed=Speed;
    }

    void setCrush(int crush){
        Crush=crush;
    }

    void setRange(int rang){
        Range=rang;
    }

    void setIcon(char icon){
        Icon=icon;
    }

    double getHit_Points(){
        return Hit_Points;
    }

double getArmor(){
	return Armor;
}

int getAttack(){
	return Attack;
}

char getIcon(){
	return Icon;
}

int getX(){
    return x;
}

int getY(){
    return y;
}

int getRace(){
    return Race;
}

int getMove_Speed(){
    return Move_Speed;
}

int getRange(){
    return Range;
}

int getCrush(){
    return Crush;
}

void setOwner(Players* P){
    Owner=P;
}

Players* getOwner(){
    return Owner;
}

    virtual ~MainObject(){

    }

};

#endif // MAINOBJECT_H_INCLUDED
