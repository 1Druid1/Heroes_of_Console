#ifndef ELF_HUNTER_H
#define ELF_HUNTER_H

class Elf_Hunter:public MainObject
{
    public:
         Elf_Hunter()
        {
            Hit_Points=100;
            Armor=1;
            Attack=3;
            Move_Speed=8;
            Range=0;
            Icon=char(210);
            Race=2; Crush=1;
        }

         ~Elf_Hunter()
        {
            //dtor
        }
    private:
};

#endif // ELF_HUNTER_H
