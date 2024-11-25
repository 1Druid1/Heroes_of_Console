#ifndef ELF_HERO_H
#define ELF_HERO_H
#include "MainObject.h"
class Elf_Hero:public MainObject
{
    public:
         Elf_Hero()
        {
            Hit_Points=100.0;
            Armor=4;
            Attack=6;
            Move_Speed=10;
            Range=15;
            Icon=char(251);
            Race=2; Crush=0;
        }

        ~Elf_Hero()
        {

        }
    private:
};

#endif // ELF_HERO_H
