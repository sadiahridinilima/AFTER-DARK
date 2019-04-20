#ifndef PLAYERS_INFO_FILE_H
#define PLAYERS_INFO_FILE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void printGameScore();
void readGameFile();

typedef struct Player player;
struct Player{
    int num;
    char shortName[10];

    Player()
    {
    ;
    }

};
Player player[100];

void loadingPlayer()
{
 int i=0;
 FILE *fp = fopen("playerInfo.bin","rb");
 while(fread(&player[i],sizeof(player[i]),1,fp)==1)
 {
     i++;

 }
 fclose(fp);

}

void writeScoringFile(char* name,int goal)
{
    Goal sc(name,goal);
    FILE *fp = fopen("scoreOpen.bin","ab");
    fwrite(&sc,sizeof(sc),1,fp);
    fclose(fp);
}



typedef struct pointTable pointTable;
struct pointTable

{
    char name[10];
    int idNumber;
    pointTable()
    {
        ;
    }
    pointTable(int id)
    {
        idNumber=id;
        strcpy(name,player[id].name);
    }
};
pointTable pt1[10]={12,16,19,1,2,9,3,7,10,4};
pointTable pt2[10];






#endif // PLAYERS_INFO_FILE_H
