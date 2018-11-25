#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5


void Test(int **s,int m,int n,int MaxCapacity);
int main()
{
    int MaxCapacity ,Nlength,Ksequence;

    scanf("%d%d%d",&MaxCapacity,&Nlength,&Ksequence);
    int **S = (int **)malloc(sizeof(int *)*Ksequence);
    for(int i = 0;i <= Ksequence-1;i++) *(S+i) = (int *)malloc(sizeof(int)*Nlength);
    for(int i = 0;i <= Ksequence-1; i++)
    {
        for(int j = 0;j <= Nlength-1;j++){scanf("%d",&S[i][j]);}
    }
    for(int i = 0;i <= Ksequence-1; i++)
    {
        for(int j = 0;j <= Nlength-1;j++){printf("%d ",*(*(S+i)+j));if(j==Nlength-1)printf("\n");}
    }
    Test(S,Ksequence,Nlength,MaxCapacity);
}
void Test(int **S,int m,int n,int MaxCapacity)
{
    for(int i = 0;i <= m-1; i++)
    {   int *jiancha = (int *)malloc(sizeof(int)*n);for(int i=0;i<n;i++)jiancha[i]=0;
        int max = -ERROR;int temp = 0;int flag = 0;
        for(int j = 0;j <= n-1;j++){
            if(j==0) {max = *(*(S+i));temp++;jiancha[*(*(S+i))-1]++;}
            else if(*(*(S+i)+j)<*(*(S+i)+j-1)&&temp<MaxCapacity){temp++;jiancha[*(*(S+i)+j)-1]++;continue;}
            else if(*(*(S+i)+j)>max){max = *(*(S+i)+j);temp=1;jiancha[*(*(S+i)+j)-1]++;continue;}
            else {flag = 1;break;}
        }
        if(flag == 1){printf("NO1\n");continue;}
        else if(flag == 0){for(int i=0;i<n;i++)if(jiancha[i]==0) {printf("%d",i);printf("NO2\n");break;continue;}
        printf("YES3\n");}
        free(jiancha);
    }
    return;
}
