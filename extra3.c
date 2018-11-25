#include <stdio.h>
#define maxnum 10000
typedef struct shit Shit;
struct shit{
  int tou;
  int wei;
  int num;
};
int main()
{
  int k ;
  int i =0,j=0;
  int max=0;
  int M = -100;
  int flag= 0;
  int fla2 = 0;
  int maxcurse1=0;
  int maxcurse2=0;
  int result[maxnum];

  Shit a[maxnum];

  scanf("%d",&k);
  while(k--)
  {
    scanf("%d",&result[i]);
  if(flag == 0)  {
    if(result[i] < 0){i++;continue;}
    if(result[i] >= 0)
    {
      if(i != 0)j++;
      fla2 = 1;
      flag = 1;
      maxcurse1 = result[i];
      maxcurse2 = result[i];
      max = result[i];
      M = result[i];
      a[j].num = M;
      a[j].tou = result[i];
      a[j].wei = result[i];
//      printf("start = %d result =%d\n",j,M);
    }
  }
  else
  {
    max+= result[i];
    if(max > M)
    {
        if(result[i-1] == 0&&M == 0)
     {

     maxcurse1 = result[i];
       a[j].tou = maxcurse1;}
    maxcurse2 = result[i];
    M = max;
     a[j].num = M;
     a[j].wei = maxcurse2;
//    printf("this %d M =%d\n",i,M);
    }
    else if( max<=0 )
    {
      flag = 0;
      max= 0;
      a[j].num = M;
//      printf(" j = %d,num = %d\n",j,a[j].num);
      a[j].tou = maxcurse1;
      a[j].wei = maxcurse2;
      M = 0;

    }


  }
  i++;
  }
  int  fuck = -100;
  if(fla2 == 1)
  {for(int i = 0; i<= j; i++) if(a[i].num > fuck){fuck = a[i].num;max=i;}
  printf("%d %d %d",fuck,a[max].tou,a[max].wei);
  }
  else if(fla2 == 0)
  {
  printf("0 %d %d",result[0],result[i-1]);
  }



    return 0;
  }



