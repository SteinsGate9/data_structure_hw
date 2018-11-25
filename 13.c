#include <stdlib.h>
#include <stdio.h>
#define MAXNUM 100
int main()
{
int input[MAXNUM],sorted[MAXNUM],already[MAXNUM];
int n,m=0,temp=0,current=0,out=0;scanf("%d",&n);
for(int i = 0; i<n ;i++){scanf("%d",&input[i]);sorted[input[i]] = m++;already[i] = 0;}
for(int i=0; i<n;i++)printf("%d ",sorted[i]);
for(int i = 0; i<n ; i++)
{
    if(already[i] != 1&&sorted[i] != i)
    {
      while(input[sorted[i]]!=sorted[i])
        {
        i = input[sorted[i]];out++;already[i] = 1;
        }
    }
    else continue;
} printf("%d",out);
return 0;
}
