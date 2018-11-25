#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxNum 30


typedef struct person{
int father;
int level;
}person;

typedef struct person* wahat;
int result[MaxNum];
person allthefuckingnodes[MaxNum]; //suoyou
int whetheryouarealone[MaxNum]; //1 shi gujia guaren

int decideLevel(int x);



int main()
{
    int N,M;
    int maxlevel = -100;
    int fatherid,childid,childnum;





do{
    maxlevel = -1;
    scanf("%d",&N);
    scanf("%d",&M);   //shit
    if(M == 0)whetheryouarealone[1] = 1;
    else{                          //GUJIAGUAREN
        allthefuckingnodes[1].level = 1;
        whetheryouarealone[1] = 0;
        }
    for(int i = 1; i <= MaxNum;i++)result[i] = 0;
    for(int i = 2; i <= N;i++)
    {
        whetheryouarealone[i] = 1;
        allthefuckingnodes[i].level = 1;
    }
    for(int i = 1; i <= M;i++)
    {
       scanf("%d%d",&fatherid,&childnum);
       if(i == 1&&childnum == 0)whetheryouarealone[1] = 1;
       while(childnum --)
       {
        scanf("%d",&childid);
        allthefuckingnodes[childid].father = fatherid;
        whetheryouarealone[fatherid] = 0;
       }
    }
    for(int i = 1; i <= N;i++)
    {
        int templevel = 0;
        if(whetheryouarealone[i] == 1)
        {
            templevel = decideLevel(i);
            result[allthefuckingnodes[i].level]++;}

        if(allthefuckingnodes[i].level > maxlevel)
            maxlevel = allthefuckingnodes[i].level;


    }

for(int i = 1 ;i<= maxlevel; i++){printf("%d",result[i]);if(i != maxlevel)printf(" ");else printf("\n");}


}while(N != 0);


    return 0;

}

int decideLevel(int x)
{
    int times = 1;
    int i2 = x;
    if(x == 1) return 1;

        while(allthefuckingnodes[i2].father != 1)
        {
           i2 = allthefuckingnodes[i2].father;
           allthefuckingnodes[x].level++;
        }
        allthefuckingnodes[x].level++;
        return allthefuckingnodes[x].level;
}








