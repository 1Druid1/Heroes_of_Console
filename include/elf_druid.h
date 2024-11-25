#ifndef ELF_DRUID_H
#define ELF_DRUID_H

class Elf_Druid:public MainObject
{
    public:
        Elf_Druid()
        {
            Hit_Points=100;
            Armor=4;
            Attack=1;
            RAttack=5;
            Move_Speed=7;
            Range=10;
            Icon=char(212);
            Race=2; Crush=3;
        }

            ~Elf_Druid()
            {
                //dtor
            }
    private:
};

#endif // ELF_DRUID_H
