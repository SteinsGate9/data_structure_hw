#include<stdio.h>



int find(int *x ,int a)

{
    int root,tail,q;
    tail = a;
    while(x[a] > 0)
            a = x[a];
        root = a;

    for(int c = tail; c != root; c = q )
    {
        q = x[c];
        x[c] = root;

    }
    return root ;
}
int main()
{

  int number;
  int jilu;
  int conection[100001];
scanf("%d",&number);
jilu = 1;
while(number--)
    conection[jilu++] = -1;

jilu --;

int op1,op2;
getchar();
while(1)
{   char OP;

    OP = getchar();
    if(OP == 'S')
        break;

    scanf("%d%d",&op1,&op2);
     getchar();
    int a = find(conection,op1);
    int b = find(conection,op2);
    if( OP == 'C'){
        if(a == b)
            printf("yes\n");
        else
            printf("no\n");}
    if( OP == 'I')
{
        
            {
              if(conection[a] > conection[b]){
              conection[a] = b;
              conection[b]--;}
              else{
                conection[b] = a;
                conection[a]--;
              }
            }


        }
//        for (int i = 1; i<= jilu; i++ ){
//        printf("%d ",conection[i]);}
//        printf("\n");
}
int fuck  = 0;
for (int i = 1; i<= jilu; i++ ){
//        printf("%d ",conection[i]V);
    if( conection[i] < 0)
        fuck = fuck+1;
}
if ( fuck > 1)
    printf("There are %d components.",fuck ) ;
else
    printf("The network is connected.");
return 0 ;
}
