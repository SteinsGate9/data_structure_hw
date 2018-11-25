#include "stdio.h"
#include "math.h"
#define maxnum 100000

int findprime(int x);
int hash(int x,int y);

int main()
{
int Msize,N;
int a  = 0 ;
int q = 0;
int corrected;
int HASH[maxnum]; for(int i = 0 ;i < maxnum; i++) HASH[i] = -100;
int fuck[maxnum]; for(int i = 0 ;i < maxnum; i++) fuck[i] = -100;
//printf("%d\n",(int)pow(16,0.5));
scanf("%d%d",&Msize,&N);
corrected = findprime(Msize);
//printf("%d = \n",corrected);
for(int i = 0;i < N; i++)
{
    int tem,result,flag = 0;
    scanf("%d",&tem);
    result = hash(tem,corrected);

     if(HASH[result] == -100)
     {
        HASH[result] = 1;
        fuck[i] = result;
     }
     else
      for(int j = 1;j<= corrected; j++)
     {
      result = (result + j*j)%corrected;
      if(HASH[result] == -100) {HASH[result] = 1;fuck[i] = result; break;}
      else continue;
     }
}
      for(int i = 0; i<N; i++)
      {
          if(i == 0)
          {
           if(fuck[i] != -100)
           printf("%d",fuck[i]);
           else
           printf("-");
          }
          else
          if(fuck[i] != -100)
          printf(" %d",fuck[i]);
          else
          printf(" -");
     }
//printf("??");


return 0;
}
int findprime(int x)
{
    int q;
    for(q = x ; ; q++)
   {
    int flag = 0;
    for(int i = 2; i<= x-1 ; i++)
    {
//        printf("i = %d\n",i);
        if(q%i == 0)
        {flag = 1 ;break;}
    }
    if(flag == 0 )
    return q;
    else  continue;
   }
}
int hash(int x,int y)
{
    return x%y;
}
