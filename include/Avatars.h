#ifndef AVATARS_H_INCLUDED
#define AVATARS_H_INCLUDED

#include <iostream>
using namespace std;

void Avatar_Human()
{
    char h[7][12];
            h[0][0]=' '; h[0][1]=' '; h[0][2]='_'; h[0][3]='_'; h[0][4]='_'; h[0][5]='/'; h[0][6]='|'; h[0][7]='\\'; h[0][8]='_'; h[0][9]='_'; h[0][10]=' '; h[0][11]=' ';
            h[1][0]=' '; h[1][1]='/'; h[1][2]=' '; h[1][3]=' '; h[1][4]=' '; h[1][5]=' '; h[1][6]=' '; h[1][7]=' '; h[1][8]=' '; h[1][9]=' '; h[1][10]='\\'; h[1][11]=' ';
            h[2][0]='|'; h[2][1]='\\'; h[2][2]='_'; h[2][3]='_'; h[2][4]='_'; h[2][5]='_'; h[2][6]='_'; h[2][7]='_'; h[2][8]='_'; h[2][9]='_'; h[2][10]='/'; h[2][11]='|';
            h[3][0]='|'; h[3][1]='\\'; h[3][2]='_'; h[3][3]='_'; h[3][4]='0'; h[3][5]='_'; h[3][6]='|'; h[3][7]='_'; h[3][8]='0'; h[3][9]='_'; h[3][10]='/'; h[3][11]='|';
            h[4][0]='|'; h[4][1]=' '; h[4][2]=' '; h[4][3]='|'; h[4][4]=' '; h[4][5]='|'; h[4][6]=' '; h[4][7]='|'; h[4][8]=' '; h[4][9]='|'; h[4][10]=' '; h[4][11]='|';
            h[5][0]='\\'; h[5][1]=' '; h[5][2]=' '; h[5][3]='|'; h[5][4]=' '; h[5][5]='|'; h[5][6]=' '; h[5][7]='|'; h[5][8]=' '; h[5][9]='|'; h[5][10]=' '; h[5][11]='|';
            h[6][0]=' '; h[6][1]=' '; h[6][2]='\\'; h[6][3]='_'; h[6][4]='_'; h[6][5]='|'; h[6][6]='_'; h[6][7]='|'; h[6][8]='_'; h[6][9]='/'; h[6][10]=' '; h[6][11]=' ';
            for(int i=0; i<7; i++){
                    cout<<'\t';
                for(int j=0; j<12; j++)
                    cout<<h[i][j];
                cout<<endl;
            }

}


void Avatar_Elf()
{
    char e[6][18];
            e[0][0]=' '; e[0][1]=' '; e[0][2]=' '; e[0][3]=' '; e[0][4]=' '; e[0][5]=' '; e[0][6]=' '; e[0][7]=' '; e[0][8]='_'; e[0][9]='\\'; e[0][10]='|'; e[0][11]='/'; e[0][12]='_'; e[0][13]=' '; e[0][14]=' '; e[0][15]=' '; e[0][16]=' '; e[0][17]=' ';
            e[1][0]='_'; e[1][1]='_'; e[1][2]=' '; e[1][3]=' '; e[1][4]=' '; e[1][5]=' '; e[1][6]='/'; e[1][7]='_'; e[1][8]='_'; e[1][9]='_'; e[1][10]='_'; e[1][11]='_'; e[1][12]='\\'; e[1][13]=' '; e[1][14]=' '; e[1][15]=' '; e[1][16]='_'; e[1][17]='_';
            e[2][0]=' '; e[2][1]='\\'; e[2][2]='\\'; e[2][3]=' '; e[2][4]=' '; e[2][5]='_'; e[2][6]='+'; e[2][7]=' '; e[2][8]='_'; e[2][9]=' '; e[2][10]=' '; e[2][11]='_'; e[2][12]=' '; e[2][13]=' '; e[2][14]='+'; e[2][15]=' '; e[2][16]='/'; e[2][17]='/';
            e[3][0]=' '; e[3][1]=' '; e[3][2]='|'; e[3][3]='_'; e[3][4]='+'; e[3][5]=' '; e[3][6]=' '; e[3][7]='o'; e[3][8]=' '; e[3][9]=' '; e[3][10]='o'; e[3][11]=' '; e[3][12]=' '; e[3][13]='+'; e[3][14]='_'; e[3][15]='|'; e[3][16]=' '; e[3][17]=' ';
            e[4][0]=' '; e[4][1]=' '; e[4][2]=' '; e[4][3]=' '; e[4][4]='+'; e[4][5]=' '; e[4][6]=' '; e[4][7]=' '; e[4][8]='_'; e[4][9]='_'; e[4][10]=' '; e[4][11]=' '; e[4][12]=' '; e[4][13]='+'; e[4][14]=' '; e[4][15]=' '; e[4][16]=' '; e[4][17]=' ';
            e[5][0]=' '; e[5][1]=' '; e[5][2]=' '; e[5][3]=' '; e[5][4]=' '; e[5][5]='+'; e[5][6]='_'; e[5][7]='_'; e[5][8]='_'; e[5][9]='_'; e[5][10]='_'; e[5][11]='_'; e[5][12]='+'; e[5][13]=' '; e[5][14]=' '; e[5][15]=' '; e[5][16]=' '; e[5][17]=' ';
            for(int i=0; i<6; i++){
                    cout<<'\t';
                for(int j=0; j<18; j++)
                    cout<<e[i][j];
                cout<<endl;
            }
}


void Avatar_Evil()
{
    char ev[7][20];
            ev[0][0]='/'; ev[0][1]='|'; ev[0][2]='_'; ev[0][3]='='; ev[0][4]='='; ev[0][5]='='; ev[0][6]='='; ev[0][7]='='; ev[0][8]='='; ev[0][9]='='; ev[0][10]='='; ev[0][11]='='; ev[0][12]='='; ev[0][13]='='; ev[0][14]='='; ev[0][15]='='; ev[0][16]='='; ev[0][17]='_'; ev[0][18]='|'; ev[0][19]='\\';
            ev[1][0]='\\'; ev[1][1]='\\'; ev[1][2]='_'; ev[1][3]='\\'; ev[1][4]='\\'; ev[1][5]='-'; ev[1][6]='-'; ev[1][7]='-'; ev[1][8]='-'; ev[1][9]='-'; ev[1][10]='-'; ev[1][11]='-'; ev[1][12]='-'; ev[1][13]='-'; ev[1][14]='-'; ev[1][15]='/'; ev[1][16]='/'; ev[1][17]='_'; ev[1][18]='/'; ev[1][19]='/';
            ev[2][0]=' '; ev[2][1]=' '; ev[2][2]=' '; ev[2][3]=' '; ev[2][4]='|'; ev[2][5]=' '; ev[2][6]=' '; ev[2][7]='('; ev[2][8]=')'; ev[2][9]=' '; ev[2][10]=' '; ev[2][11]='('; ev[2][12]=')'; ev[2][13]=' '; ev[2][14]=' '; ev[2][15]='|'; ev[2][16]=' '; ev[2][17]=' '; ev[2][18]=' '; ev[2][19]=' ';
            ev[3][0]=' '; ev[3][1]=' '; ev[3][2]=' '; ev[3][3]=' '; ev[3][4]='|'; ev[3][5]=' '; ev[3][6]=' '; ev[3][7]=' '; ev[3][8]=' '; ev[3][9]=' '; ev[3][10]=' '; ev[3][11]=' '; ev[3][12]=' '; ev[3][13]=' '; ev[3][14]=' '; ev[3][15]='|'; ev[3][16]=' '; ev[3][17]=' '; ev[3][18]=' '; ev[3][19]=' ';
            ev[4][0]=' '; ev[4][1]=' '; ev[4][2]=' '; ev[4][3]='/'; ev[4][4]=' '; ev[4][5]=' '; ev[4][6]='/'; ev[4][7]='|'; ev[4][8]=' '; ev[4][9]=' '; ev[4][10]=' '; ev[4][11]=' '; ev[4][12]='|'; ev[4][13]='\\'; ev[4][14]=' '; ev[4][15]=' '; ev[4][16]='\\'; ev[4][17]=' '; ev[4][18]=' '; ev[4][19]=' ';
            ev[5][0]=' '; ev[5][1]=' '; ev[5][2]=' '; ev[5][3]='|'; ev[5][4]=' '; ev[5][5]=' '; ev[5][6]='\\'; ev[5][7]='\\'; ev[5][8]='-'; ev[5][9]='-'; ev[5][10]='-'; ev[5][11]='-'; ev[5][12]='/'; ev[5][13]='/'; ev[5][14]=' '; ev[5][15]=' '; ev[5][16]='|'; ev[5][17]=' '; ev[5][18]=' '; ev[5][19]=' ';
            ev[6][0]=' '; ev[6][1]=' '; ev[6][2]=' '; ev[6][3]='\\'; ev[6][4]='_'; ev[6][5]='_'; ev[6][6]='_'; ev[6][7]='_'; ev[6][8]='_'; ev[6][9]='_'; ev[6][10]='_'; ev[6][11]='_'; ev[6][12]='_'; ev[6][13]='_'; ev[6][14]='_'; ev[6][15]='_'; ev[6][16]='/'; ev[6][17]=' '; ev[6][18]=' '; ev[6][19]=' ';
            for(int i=0; i<7; i++){
                    cout<<'\t';
                for(int j=0; j<20; j++)
                    cout<<ev[i][j];
                cout<<endl;
            }
}


#endif // AVATARS_H_INCLUDED