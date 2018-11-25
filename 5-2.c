#include <stdlib.h>
#include <stdio.h>
#define MAXNUM 100

int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int max1(int a ,int b)
{

    return a>b?a:b;
}

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    int layer;
    BinTree Left;
    BinTree Right;
};
typedef struct Stacknode *Stack;
struct Stacknode{
    BinTree x;
    Stack next;
};
typedef struct  Queuenode *Queue;
struct  Queuenode{
    BinTree  x;
    Queue next;
};

BinTree BuildTree(int x); /* details omitted */
int CheckBST ( BinTree T, int K );
void Inversal(BinTree X,int *x);
int result[MAXNUM];


int maxlayer;

int max;
// new
void Pop(Stack x);
void Push(Stack t,BinTree x);
void Print(BinTree t);
void Push2(Queue x,BinTree t);
void Pop2(Queue x);
BinTree all[MAXNUM];

int findlayer(BinTree x);
int main()
{

    maxlayer = 1;


    int K,in1,in2;
    scanf("%d", &K);
    BinTree T[MAXNUM];
    for(int i = 0; i<= K-1; i++)
    {
        T[i] = (BinTree)malloc(sizeof(struct TNode));
        T[i]->Key = i;
        T[i]->Left = NULL;
        T[i]->Right =NULL;
    }

    for(int i = 0;i <= K-1; i++)
    {
        scanf("%d%d",&in1,&in2);
        if(in1 != -1)
        T[i]->Left = T[in1];
        if(in2 != -1)
        T[i]->Right = T[in2];
    }


for(int i = 0; i<= K-1; i++ )
{
  scanf("%d",&result[i]);
}

    max = 0;
    qsort(result,K,sizeof(int),comp);
    Inversal(T[0],result);
    Print(T[0]);
    return 0;
}



void Inversal(BinTree X,int *x)
{
    if(x==NULL)return ;
    if(X->Left) {Inversal(X->Left,x);}
    {
    X->Key = x[max++];
//    printf("%d node is %d\n ",max-1,X->Key);
    }
    if(X->Right) {Inversal(X->Right,x);}



    return;
}


void Push2(Queue t,BinTree x)
{
    Queue temp = (Queue)malloc(sizeof(struct Queuenode));
    temp->x = x;
    temp->next = NULL;
    Queue temp2 = t;
    if(temp2->next)
    {
       while(temp2->next)temp2= temp2->next;
      temp2->next = temp;
    }
    else
    {
      t->next = temp;
    }


}
void Pop2(Queue t)
{
    if(t->next)
    {

        if(t->next->next){t->next = t->next->next;}
        else t->next = NULL;
       }
}
void Print(BinTree T) {
    int a = 0;
    Queue temp = (Queue) malloc(sizeof(struct Queuenode));
    temp->next = NULL;
    Push2(temp, T);
//    printf("maxlayer = %d\n",maxlayer);
    while (temp->next != NULL) {
        BinTree temp2 = temp->next->x;
        Pop2(temp);
        if(a == 0)
       {
           a = 1;
       printf("%d",temp2->Key);
       }
       else
        printf(" %d",temp2->Key);

        if (temp2->Left) { Push2(temp, temp2->Left); }
        if (temp2->Right) { Push2(temp, temp2->Right); }
         }
    }




