#ifndef PLAYERS_H
#define PLAYERS_H
#include <stdbool.h>
class Players
{
    public:
            Players()
            {
                FlagStep=false;
                Winner=false;
                Loser=false;
                for(int i=0; i<20; i++)
                    Nick[i]=' ';
                Nick[20-1]='\0';

            }

            //Setting side
            void setSide(char pside){
                side=pside;
            }

            //Set nickname
            void setnick(const char *nickmas){
                for(int i=0; i<20-2;i++)
                    Nick[i]=nickmas[i];
            }

            //set race
            void setRace(int race){
                Race=race;
            }

            //set stepFlag
            void setPStep(bool flagstep){
                FlagStep=flagstep;
            }

            void setWinner(bool Win){
                Winner=Win;
            }

            void setLoser(bool lose){
                Loser=lose;
            }

            //get stepFlag
            bool getPStep(){
                return FlagStep;
            }
            //get race
            int getRace(){
                return Race;
            }

            //getting player nickname
            char* getNickname(){
                return Nick;
            }

            char getSide(){
                return side;
            }

            bool getWinner(){
                return Winner;
            }

            bool getLoser(){
                return Loser;
            }

            ~Players()
            {
                //dtor
            }
    private:
        char Nick[20], side;
        bool FlagStep, Winner, Loser;
        int Race;
};

#endif // PLAYERS_H
