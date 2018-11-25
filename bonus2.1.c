#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define maxnum 100000
#define maxpara 1e9

int comp(const void *a, const void *b)
{
    return (*(long int *)a- *(long int *)b);
}
int main()
{
    long int shit[maxnum];
    long int maxp;
    long int num,before = 0, end = 0;
    long int max=-100;
    scanf("%ld%ld",&num,&maxp);
    for(int i = 0;i < num ;i ++)
        scanf("%ld",&shit[i]);
    qsort(shit,num,sizeof(long int),comp);
    while(1)
    {
        while(shit[end] <= shit[before]*maxp){end++;if(end==num)break;}
        max = end-before>max?:end-before,max;
        if(end == num)break;
        while(shit[before] * maxp <shit[end]){before++;}
    }

    printf("%ld",max);
    return 0;
}
