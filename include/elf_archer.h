#ifndef ELF_ARCHER_H
#define ELF_ARCHER_H

class Elf_Archer:public MainObject
{
    public:
         Elf_Archer()
        {
            Hit_Points=100;
            Armor=1;
            Attack=4;
            Move_Speed=8;
            Range=11;
            Icon=char(209);
            Race=2; Crush=2;
        }

        ~Elf_Archer()
        {
            //dtor
        }
    private:
};

#endif // ELF_ARCHER_H
