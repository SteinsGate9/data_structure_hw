#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxNum 30
typedef struct TreeNode *Tree;
typedef enum { push, pop, null} Operation;
struct TreeNode {
    int  Element;
    Tree  Left;
    Tree  Right;
};

typedef struct StackNode *Stack;
struct StackNode {
    int what;
    int flag;
    Stack next;
};

typedef struct OperationNode {
    Operation op;
    int x;
}queue;
Stack CreateStack();
void Push(Stack t, int x);
void Pop(Stack t);
Operation GetOp();











 int main()
 {
   queue a[MaxNum];
   int i =0;
   int times;
   int curse = 0;
   int flag = 0;
   int now = 0;
   int result[MaxNum] = {0};
   int popnum = 0;
   Operation fuck[2*MaxNum];
   Stack treeStack = CreateStack();
   Stack tempnode ;
   scanf("%d",&times);
   Operation previous;
   Operation next;

       int temp;
     while(popnum != times)
   {
       switch(GetOp()){
       case push:
            scanf("%d",&temp);
            a[i].op = push;
            a[i++].x = temp;
            break;

       case pop:
            a[i].op = pop;
            a[i++].x = -100;
            popnum++;
            break;
       }
   }

   for(int i = 0;i<= 2*times-1;i++)printf("x = %d\n",a[i].x);
       for(int i = 0; i <= 2*times-1; i++)
       {
          if(a[i].op == push){printf("push %d\n",a[i].x);Push(treeStack,a[i].x);continue;}
          else if(a[i].op == pop)
          shit:  {
             if(treeStack->next->flag == 1){printf("fatherpop:%d\n",treeStack->next->what);result[curse++] = treeStack->next->what;Pop(treeStack);goto shit;}
             else if(a[i-1].op == push){if(i == 2*times -1) {printf("sonpop:%d\n",treeStack->next->what);result[curse++] = treeStack->next->what;Pop(treeStack);}
                                        else if(a[i+1].op == push){printf("fatherset:%d\n",treeStack->next->what);treeStack->next->flag =1;}
                                        else {printf("sonpop:%d\n",treeStack->next->what);result[curse++] = treeStack->next->what;Pop(treeStack);} }
             else if(a[i-1].op == pop) {if(treeStack->next->flag != 1)treeStack->next->flag = 1;}//¸¸Ç×½Úµã
            }
       }

       while(treeStack->next && treeStack->next->flag == 1)
       {
         result[curse++] = treeStack->next->what; Pop(treeStack);
       }








   for(int i = 0; i <= times-1; i++){printf("%d",result[i]);if(i != times-1)printf(" ");}


 return 0;
 }










 Operation GetOp()
{
    char s[10];
    scanf("%s",&s);
    if(strcmp(s,"Push") == 0)   return push;
    if(strcmp(s,"Pop") == 0)    return pop;
}


Stack CreateStack()
{
    Stack  c= (Stack)malloc(sizeof(struct StackNode));
    c->next = NULL;
    c->flag = 0;
    return c;
}
void Push(Stack t, int x)
{
    Stack  c= (Stack)malloc(sizeof(struct StackNode));
    c->what = x;
    if(t->next)c->next = t->next;
    else c->next = NULL;
    t->next = c;
}
void Pop(Stack t)
{
    if(t->next)
    {
        Stack temp = t->next;
        if(t->next->next)t->next = t->next->next;
        else t->next = NULL;
        free(temp);
    }
}
