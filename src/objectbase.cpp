#include "objectbase.h"
#include "classmodulmain.h"

using namespace std;
ObjectBase::ObjectBase()
{
    HERO_CRUSH=0;
    WAR_CRUSH=1;
    ARCH_CRUSH=2;
    SPEC_CRUSH=3;
    HUM_RACE=1;
    ELF_RACE=2;
    EVIL_RACE=3;
    RACE_NUMBER=3;
    Player=NULL;
    PL_LENGTH=0;
    HERO_LENGTH=0;
    WAR_LENGTH=0;
    ARCH_LENGTH=0;
    SPEC_LENGTH=0;
    MOBegin=NULL;
    MOEnd=NULL;
    MOCurrent=NULL;
    MOTemp=NULL;
    B_temp=NULL;
    B_begin=NULL;
    B_end=NULL;
    }

int ObjectBase::getPLENGTH(){
    return PL_LENGTH;
}

const int ObjectBase::getHEROCR(){
    return HERO_CRUSH;
}

int ObjectBase::getWARCR(){
    return WAR_CRUSH;
}

int ObjectBase::getARCHCR(){
    return ARCH_CRUSH;
}

int ObjectBase::getSPECCR(){
    return SPEC_CRUSH;
}

int ObjectBase::getHUMRACE(){
    return HUM_RACE;
}

int ObjectBase::getELFRACE(){
    return ELF_RACE;
}

int ObjectBase::getEVILRACE(){
    return EVIL_RACE;
}

int ObjectBase::getRACENUMB(){
    return RACE_NUMBER;
}

int ObjectBase::getWARLEN(){
    return WAR_LENGTH;
}

int ObjectBase::getARCHLEN(){
    return ARCH_LENGTH;
}

int ObjectBase::getSPECLEN(){
    return SPEC_LENGTH;
}

void ObjectBase::createPlayers(int number){
    if(Player==NULL){
        PL_LENGTH=number;
        Player=new Players[number];
    }
}

void ObjectBase::Add_A_BonusToList(){
    B_current=new Bonus_A;
    if(B_begin==NULL){
        B_begin=B_current;
        B_end=B_current;
        B_end->next=0;
    }
    else if(B_begin!=NULL){
        B_end->next=B_current;
        B_end=B_current;
        B_end->next=0;
    }
}

void ObjectBase::Add_H_BonusToList(){
    B_current=new Bonus_H;
    if(B_begin==NULL){
        B_begin=B_current;
        B_end=B_current;
        B_end->next=0;
    }
    else if(B_begin!=NULL){
        B_end->next=B_current;
        B_end=B_current;
        B_end->next=0;
    }
}

void ObjectBase::Add_S_BonusToList(){
    B_current=new Bonus_S;
    if(B_begin==NULL){
        B_begin=B_current;
        B_end=B_current;
        B_end->next=0;
    }
    else if(B_begin!=NULL){
        B_end->next=B_current;
        B_end=B_current;
        B_end->next=0;
    }
}

void ObjectBase::createLists(){
    if(Player!=NULL){
        for(int i=0; i<PL_LENGTH; i++){
            switch(Player[i].getRace()){
                case 1:
                    /*Creating Heroes list*/
                    MOCurrent=new Knight;
                    MOCurrent->setOwner(&Player[i]);
                    if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                    }
                    else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    /*Creating Units list*/
                    /*WARRIORS*/
                    for(int j=0; j<WAR_LENGTH; j++){
                        MOCurrent=new Human_Soldier;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                            MOEnd->next=MOCurrent;
                            MOEnd=MOEnd->next;
                            MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                            MOBegin=MOCurrent;
                            MOEnd=MOCurrent;
                            MOEnd->next=0;
                        }
                    }
                    /*ARCHERS*/
                    for(int j=0; j<ARCH_LENGTH; j++){
                        MOCurrent=new Human_Shooter;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                            MOEnd->next=MOCurrent;
                            MOEnd=MOEnd->next;
                            MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                            MOBegin=MOCurrent;
                            MOEnd=MOCurrent;
                            MOEnd->next=0;
                        }
                    }
                    /*SPECIAL*/
                    for(int j=0; j<SPEC_LENGTH; j++){
                        MOCurrent=new Human_HeavySoldier;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                            MOEnd->next=MOCurrent;
                            MOEnd=MOEnd->next;
                            MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                            MOBegin=MOCurrent;
                            MOEnd=MOCurrent;
                            MOEnd->next=0;
                    }
                    }
                    break;
                case 2:
                     /*Creating Heroes list*/
                    MOCurrent=new Elf_Hero;
                    MOCurrent->setOwner(&Player[i]);
                    if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                    }
                    else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    /*Creating Units list*/
                    /*WARRIORS*/
                    for(int j=0; j<WAR_LENGTH; j++){
                        MOCurrent=new Elf_Hunter;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    }
                    /*ARCHERS*/
                    for(int j=0; j<ARCH_LENGTH; j++){
                        MOCurrent=new Elf_Archer;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    }
                    /*SPECIAL*/
                    for(int j=0; j<SPEC_LENGTH; j++){
                        MOCurrent=new Elf_Druid;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                        }
                    }
                    break;
                case 3:
                     /*Creating Heroes list*/
                    MOCurrent=new Evil_Hero;
                    MOCurrent->setOwner(&Player[i]);
                    if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                    }
                    else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    /*Creating Units list*/
                    /*WARRIORS*/
                    for(int j=0; j<WAR_LENGTH; j++){
                        MOCurrent=new Evil_Warrior;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    }
                    /*ARCHERS*/
                    for(int j=0; j<ARCH_LENGTH; j++){
                        MOCurrent=new Evil_Demon;
                        MOCurrent->setCrush(ARCH_CRUSH);
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                    }
                    }
                    /*SPECIAL*/
                    for(int j=0; j<SPEC_LENGTH; j++){
                        MOCurrent=new Evil_Demon;
                        MOCurrent->setOwner(&Player[i]);
                        if(MOBegin!=NULL && MOEnd!=NULL){
                        MOEnd->next=MOCurrent;
                        MOEnd=MOEnd->next;
                        MOEnd->next=0;
                        }
                        else if(MOBegin==NULL){
                        MOBegin=MOCurrent;
                        MOEnd=MOCurrent;
                        MOEnd->next=0;
                        }
                    }
                    break;
            }
        }
    }
}

void ObjectBase::setMOBegin(MainObject* pointer){
    MOBegin=pointer;
}

void ObjectBase::setMOEnd(MainObject* pointer){
    MOEnd=pointer;
}

void ObjectBase::setMOTemp(MainObject* pointer){
    MOTemp=pointer;
}

void ObjectBase::setMOCurrent(MainObject* pointer){
    MOCurrent=pointer;
}

void ObjectBase::setHpfPointer(MainObject* Pointer){
    HelpfullPointer=Pointer;
}

void ObjectBase::setHEROLENGTH(int number){
    HERO_LENGTH=number;
}

void ObjectBase::setWARLENGTH(int number){
    WAR_LENGTH=number;
}

void ObjectBase::setARCHLENGTH(int number){
    ARCH_LENGTH=number;
}

void ObjectBase::setBBegin(Bonus* bon){
    B_begin=bon;
}

void ObjectBase::setBCurrent(Bonus* bon){
    B_current=bon;
}

void ObjectBase::setBTemp(Bonus* bon){
    B_temp=bon;
}

void ObjectBase::setBEnd(Bonus* bon){
    B_end=bon;
}


Bonus* ObjectBase::getBBegin(){
    return B_begin;
}

Bonus* ObjectBase::getBCurrent(){
    return B_current;
}

Bonus* ObjectBase::getBTemp(){
    return B_temp;
}

Bonus* ObjectBase::getBEnd(){
    return B_end;
}

void ObjectBase::setSPECLENGTH(int number){
    SPEC_LENGTH=number;
}

Players* ObjectBase::getPLAYERS(){
    return Player;
}

MainObject* ObjectBase::getBegin(){
    return MOBegin;
}

MainObject* ObjectBase::getCurrent(){
    return MOCurrent;
}

MainObject* ObjectBase::getTemp(){
    return MOTemp;
}

MainObject* ObjectBase::getEnd(){
    return MOEnd;
}

MainObject* ObjectBase::getHpfPointer(){
    return HelpfullPointer;
}

ObjectBase::~ObjectBase()
{
    if(Player!=NULL) delete []Player;
    if(MOBegin!=NULL){
        while(MOBegin!=0){
            MOTemp=MOBegin;
            MOBegin=MOBegin->next;
            delete MOTemp;
        }
    }
    if(B_begin!=NULL){
        while(B_begin!=0){
            B_temp=B_begin;
            B_begin=B_begin->next;
            delete B_temp;
        }
    }
}
