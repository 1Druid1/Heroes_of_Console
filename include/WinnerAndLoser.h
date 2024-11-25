#ifndef WINNERANDLOSER_H_INCLUDED
#define WINNERANDLOSER_H_INCLUDED

void WinnerPicture(){
    char** WinnerPict;
    const int I=7;
    const int J=31;
    WinnerPict=new char*[I];
    for(int i=0; i<I; i++)
        WinnerPict[i]=new char[J];
    for(int i=0; i<I; i++){
        for(int j=0; j<J; j++)
            WinnerPict[i][j]=' ';
    }
    WinnerPict[0][10]='/'; WinnerPict[0][11]='\\'; WinnerPict[0][15]='_'; WinnerPict[0][16]='_'; WinnerPict[0][18]='_'; WinnerPict[0][19]='_';
    WinnerPict[0][20]='_'; WinnerPict[0][22]='_'; WinnerPict[0][23]='_'; WinnerPict[0][24]='_';
    WinnerPict[1][1]='_'; WinnerPict[1][2]='_'; WinnerPict[1][3]='_'; WinnerPict[1][4]='_'; WinnerPict[1][5]='_'; WinnerPict[1][6]='_'; WinnerPict[1][7]='_';
    WinnerPict[1][8]='_'; WinnerPict[1][9]='|'; WinnerPict[1][12]='|'; WinnerPict[1][14]='/'; WinnerPict[1][17]='|'; WinnerPict[1][1]='_'; WinnerPict[1][21]='|';
    WinnerPict[1][25]='|';
    WinnerPict[2][0]='|'; WinnerPict[2][1]='_'; WinnerPict[2][2]='_'; WinnerPict[2][3]='_'; WinnerPict[2][4]='_'; WinnerPict[2][5]='_'; WinnerPict[2][6]='_';
    WinnerPict[2][7]='_'; WinnerPict[2][8]='_'; WinnerPict[2][9]='|'; WinnerPict[2][11]='/'; WinnerPict[2][13]='\\'; WinnerPict[2][16]='_';
    WinnerPict[2][17]='|'; WinnerPict[2][19]='_'; WinnerPict[2][20]='_'; WinnerPict[2][21]='|'; WinnerPict[2][23]='_'; WinnerPict[2][24]='_';
    WinnerPict[2][25]='|'; WinnerPict[2][26]='_'; WinnerPict[2][27]='/'; WinnerPict[2][30]='|';
    WinnerPict[3][0]='|'; WinnerPict[3][1]='_'; WinnerPict[3][2]='_'; WinnerPict[3][3]='_'; WinnerPict[3][4]='_'; WinnerPict[3][5]='_'; WinnerPict[3][6]='_';
    WinnerPict[3][7]='_'; WinnerPict[3][8]='_'; WinnerPict[3][9]='|'; WinnerPict[3][11]='\\'; WinnerPict[3][14]='\\'; WinnerPict[3][15]='_';
    WinnerPict[3][16]='_'; WinnerPict[3][17]='_';  WinnerPict[3][18]='_'; WinnerPict[3][19]='_'; WinnerPict[3][20]='_'; WinnerPict[3][6]='_';
    WinnerPict[3][21]='_'; WinnerPict[3][22]='_'; WinnerPict[3][23]='_'; WinnerPict[3][24]='_'; WinnerPict[3][25]='_'; WinnerPict[3][26]='_';
    WinnerPict[3][30]='|';
    WinnerPict[4][9]='|'; WinnerPict[4][12]='\\'; WinnerPict[4][14]='|'; WinnerPict[4][25]='|'; WinnerPict[4][27]='\\'; WinnerPict[4][28]='_'; WinnerPict[4][29]='_';
    WinnerPict[4][30]='|';
    WinnerPict[5][10]='\\'; WinnerPict[5][11]='/';  WinnerPict[5][13]='|'; WinnerPict[5][24]='/';
    WinnerPict[6][14]='\\';  WinnerPict[6][24]='|'; WinnerPict[6][30]='\0';
    cout<<endl;
    for(int i=0; i<I; i++){
        for(int j=0; j<J; j++)
            cout<<WinnerPict[i][j];
        cout<<endl;
    }
    for(int i=0; i<I; i++)
        delete []WinnerPict[i];
    delete []WinnerPict;
}

void LoserPicture(){
    const int I=15;
    const int J=19;
    char los[I][J];

los[0][0]=' ';los[0][1]=' ';los[0][2]=' ';los[0][3]=' ';los[0][4]=' ';los[0][5]=' ';los[0][6]=' ';los[0][7]=' ';los[0][8]=' ';los[0][9]=' ';los[0][10]=' ';los[0][11]=' ';los[0][12]=' ';los[0][13]=' ';los[0][14]='/';los[0][15]='|';los[0][16]=' ';los[0][17]=' ';los[0][18]=' ';
los[1][0]=' ';los[1][1]=' ';los[1][2]=' ';los[1][3]=' ';los[1][4]=' ';los[1][5]=' ';los[1][6]=' ';los[1][7]=' ';los[1][8]=' ';los[1][9]=' ';los[1][10]=' ';los[1][11]=' ';los[1][12]=' ';los[1][13]='/';los[1][14]=' ';los[1][15]='/';los[1][16]=' ';los[1][17]=' ';los[1][18]=' ';
los[2][0]=' ';los[2][1]=' ';los[2][2]=' ';los[2][3]=' ';los[2][4]=' ';los[2][5]=' ';los[2][6]=' ';los[2][7]=' ';los[2][8]='/';los[2][9]='|';los[2][10]='_';los[2][11]='_';los[2][12]='/';los[2][13]=' ';los[2][14]='/';los[2][15]='_';los[2][16]='_';los[2][17]='|';los[2][18]='\\';
los[3][0]=' ';los[3][1]=' ';los[3][2]=' ';los[3][3]=' ';los[3][4]=' ';los[3][5]=' ';los[3][6]=' ';los[3][7]=' ';los[3][8]='\\';los[3][9]='v';los[3][10]='v';los[3][11]='v';los[3][12]='v';los[3][13]='v';los[3][14]='v';los[3][15]='v';los[3][16]='v';los[3][17]='v';los[3][18]='/';
los[4][0]=' ';los[4][1]=' ';los[4][2]=' ';los[4][3]=' ';los[4][4]=' ';los[4][5]=' ';los[4][6]=' ';los[4][7]=' ';los[4][8]=' ';los[4][9]=' ';los[4][10]='/';los[4][11]='/';los[4][12]=' ';los[4][13]='/';los[4][14]=' ';los[4][15]=' ';los[4][16]=' ';los[4][17]=' ';los[4][18]=' ';
los[5][0]=' ';los[5][1]='_';los[5][2]=' ';los[5][3]='_';los[5][4]=' ';los[5][5]='_';los[5][6]=' ';los[5][7]='_';los[5][8]=' ';los[5][9]='/';los[5][10]='_';los[5][11]=' ';los[5][12]='/';los[5][13]='/';los[5][14]=' ';los[5][15]=' ';los[5][16]=' ';los[5][17]=' ';los[5][18]=' ';
los[6][0]='/';los[6][1]=' ';los[6][2]=' ';los[6][3]=' ';los[6][4]=' ';los[6][5]=' ';los[6][6]=' ';los[6][7]=' ';los[6][8]=' ';los[6][9]=' ';los[6][10]=' ';los[6][11]='\\';los[6][12]='/';los[6][13]=' ';los[6][14]=' ';los[6][15]=' ';los[6][16]=' ';los[6][17]=' ';los[6][18]=' ';
los[7][0]='|';los[7][1]=' ';los[7][2]=' ';los[7][3]=' ';los[7][4]='X';los[7][5]=' ';los[7][6]=' ';los[7][7]=' ';los[7][8]='X';los[7][9]=' ';los[7][10]=' ';los[7][11]='|';los[7][12]=' ';los[7][13]=' ';los[7][14]=' ';los[7][15]=' ';los[7][16]=' ';los[7][17]=' ';los[7][18]=' ';
los[8][0]=' ';los[8][1]='\\';los[8][2]=' ';los[8][3]=' ';los[8][4]=' ';los[8][5]=' ';los[8][6]=' ';los[8][7]=' ';los[8][8]=' ';los[8][9]=' ';los[8][10]='/';los[8][11]=' ';los[8][12]=' ';los[8][13]=' ';los[8][14]=' ';los[8][15]=' ';los[8][16]=' ';los[8][17]=' ';los[8][18]=' ';
los[9][0]=' ';los[9][1]=' ';los[9][2]='|';los[9][3]=' ';los[9][4]=' ';los[9][5]='-';los[9][6]='-';los[9][7]='-';los[9][8]=' ';los[9][9]='|';los[9][10]=' ';los[9][11]=' ';los[9][12]=' ';los[9][13]=' ';los[9][14]=' ';los[9][15]=' ';los[9][16]=' ';los[9][17]=' ';los[9][18]=' ';
los[10][0]=' ';los[10][1]=' ';los[10][2]=' ';los[10][3]='\\';los[10][4]='_';los[10][5]='_';los[10][6]='_';los[10][7]='_';los[10][8]='/';los[10][9]=' ';los[10][10]=' ';los[10][11]=' ';los[10][12]=' ';los[10][13]=' ';los[10][14]=' ';los[10][15]=' ';los[10][16]=' ';los[10][17]=' ';los[10][18]=' ';
los[11][0]=' ';los[11][1]=' ';los[11][2]=' ';los[11][3]='/';los[11][4]='/';los[11][5]=' ';los[11][6]='/';los[11][7]='/';los[11][8]=' ';los[11][9]=' ';los[11][10]=' ';los[11][11]=' ';los[11][12]=' ';los[11][13]=' ';los[11][14]=' ';los[11][15]=' ';los[11][16]=' ';los[11][17]=' ';los[11][18]=' ';
los[12][0]=' ';los[12][1]=' ';los[12][2]='/';los[12][3]='/';los[12][4]=' ';los[12][5]='/';los[12][6]='/';los[12][7]=' ';los[12][8]=' ';los[12][9]=' ';los[12][10]=' ';los[12][11]=' ';los[12][12]=' ';los[12][13]=' ';los[12][14]=' ';los[12][15]=' ';los[12][16]=' ';los[12][17]=' ';los[12][18]=' ';
los[13][0]=' ';los[13][1]=' ';los[13][2]='\\';los[13][3]=' ';los[13][4]='/';los[13][5]='/';los[13][6]=' ';los[13][7]=' ';los[13][8]=' ';los[13][9]=' ';los[13][10]=' ';los[13][11]=' ';los[13][12]=' ';los[13][13]=' ';los[13][14]=' ';los[13][15]=' ';los[13][16]=' ';los[13][17]=' ';los[13][18]=' ';
los[14][0]=' ';los[14][1]=' ';los[14][2]=' ';los[14][3]='|';los[14][4]='/';los[14][5]=' ';los[14][6]=' ';los[14][7]=' ';los[14][8]=' ';los[14][9]=' ';los[14][10]=' ';los[14][11]=' ';los[14][12]=' ';los[14][13]=' ';los[14][14]=' ';los[14][15]=' ';los[14][16]=' ';los[14][17]=' ';los[14][18]=' ';

    for(int i=0; i<I; i++){
            cout<<'\t';
        for(int j=0; j<J; j++)
            cout<<los[i][j];
        cout<<endl;
    }
}

#endif // WINNERANDLOSER_H_INCLUDED
