#ifndef OBJECTBASE_H
#define OBJECTBASE_H
#include "elf_hero.h"
#include "knight.h"
#include "evil_hero.h"
#include "human_soldier.h"
#include "human_shooter.h"
#include "human_heavysoldier.h"
#include "elf_archer.h"
#include "elf_hunter.h"
#include "elf_druid.h"
#include "evil_demon.h"
#include "evil_warrior.h"
#include "bonus.h"
#include "bonus_a.h"
#include "bonus_h.h"
#include "bonus_s.h"
#include "players.h"
#include "MainObject.h"
class ObjectBase
{
    public:
        ObjectBase();
        int getPLENGTH();
        void createLists();
        void createPlayers(int number);
        void setHEROLENGTH(int number);
        void setWARLENGTH(int number);
        void setARCHLENGTH(int number);
        void setSPECLENGTH(int number);
        void setMOBegin(MainObject* pointer);
        void setMOEnd(MainObject* pointer);
        void setHpfPointer(MainObject* Pointer);
        void setMOCurrent(MainObject* pointer);
        void setMOTemp(MainObject* pointer);
        Players* getPLAYERS();
        MainObject* getBegin();
        MainObject* getCurrent();
        MainObject* getTemp();
        MainObject* getEnd();
        MainObject* getHpfPointer();
        int getHUMRACE();
        int getELFRACE();
        int getEVILRACE();
        int getRACENUMB();
        const int getHEROCR();
        int getWARCR();
        int getARCHCR();
        int getSPECCR();
        int getWARLEN();
        int getARCHLEN();
        int getSPECLEN();
        void Add_A_BonusToList();
        void Add_H_BonusToList();
        void Add_S_BonusToList();
        void setBBegin(Bonus* bon);
        void setBCurrent(Bonus* bon);
        void setBTemp(Bonus* bon);
        void setBEnd(Bonus* bon);
        Bonus* getBBegin();
        Bonus*  getBCurrent();
        Bonus* getBTemp();
        Bonus* getBEnd();
        ~ObjectBase();
    protected:
    private:
        int HERO_CRUSH, WAR_CRUSH, ARCH_CRUSH, SPEC_CRUSH;
        int HUM_RACE, ELF_RACE, EVIL_RACE, RACE_NUMBER;
        int HERO_LENGTH, WAR_LENGTH, ARCH_LENGTH, SPEC_LENGTH;
        int PL_LENGTH;
        MainObject* MOBegin, *MOEnd, *MOCurrent, *MOTemp, *HelpfullPointer;
        Players* Player;
        Bonus* B_begin, *B_end, *B_current, *B_temp;
};

#endif // OBJECTBASE_H
