#include <stdlib.h>
#include <stdio.h>
#define MAXNUM 100
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
int whetheralone[MAXNUM];
void Pop(Stack x);
void Push(Stack t,BinTree x);
void Print(BinTree t);
void Push2(Queue x,BinTree t);
void Pop2(Queue x);
int Decide(BinTree t);
int n;
int max1(int a ,int b)
{

    return a>b?a:b;
}

int main()
{
  BinTree fuck[MAXNUM];

  int k;
  int i = 0;
  int max = -100;
  int max2= -100;
  scanf("%d",&k);
  for(int i = 0; i<k; i++)
  {
    fuck[i] = (BinTree)malloc(sizeof(struct TNode));
    fuck[i]->Left = NULL;
    fuck[i]->Right = NULL;
    fuck[i]->Key = i;
    fuck[i]->layer = 1;
    whetheralone[i] = 1;

  }
  getchar();
  for(int i = 0;i <k; i++)
  {

    char in1,in2;
    in1 = getchar();

    getchar();
    in2 = getchar();
    getchar();
    if(in1 != '-')
 {
//printf("this = %d\n",in1-'0');
     fuck[i]->Left = fuck[in1-'0'];

    // BinTree[i]->layer = BinTree[atoi(in1)]->layer+1;
    }
    if(in2 != '-')
    {fuck[i]->Right = fuck[in2 - '0'];
    // BinTree[i]->layer = BinTree[atoi(in1)]->layer+1;
    }
    if(in1 != '-' || in2 != '-')
    whetheralone[i] = 0;

//    printf("%d\n",i);
  }


  for(int j = 0; j<k ; j++)
    {

     if(Decide(fuck[j]) > max){max = Decide(fuck[j]);max2 = j;}
    }
    Print(fuck[max2]);




  return 0;
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
    if(whetheralone[temp2->Key] == 1)
        {if(a == 0)
       {
           a = 1;
       printf("%d",temp2->Key);
       }
       else
        printf(" %d",temp2->Key);
        }


        if (temp2->Left) { Push2(temp, temp2->Left); }
        if (temp2->Right) { Push2(temp, temp2->Right); }
         }
    }
int Decide(BinTree t)
{
   if(t == NULL) return 0;
//   printf("this node = %d\n",t->Key);
   return  max1(Decide(t->Left),Decide(t->Right))+1;


}
