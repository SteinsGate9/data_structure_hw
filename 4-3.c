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
    int num;
}queue;
Stack CreateStack();
void Push(Stack t, int x);
void Pop(Stack t);
Operation GetOp();











 int main()
 {
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

          if(previous == pop)
           {printf("?");
            if(tempnode != NULL)
            tempnode->flag = 1;
            scanf("%d",&temp);
            Push(treeStack,temp);
            previous = push;
           }
           else
           {
            scanf("%d",&temp);
            Push(treeStack,temp);
            previous = push;
           }

            break;

      shit: case pop:

            if(treeStack->next->flag == 1){printf("fatherpop:%d\n",treeStack->next->what);result[curse++] = treeStack->next->what;Pop(treeStack);goto shit;}
            else if(previous == push){tempnode = treeStack->next;}
            else if(previous == pop){if(treeStack->next->flag != 1)treeStack->next->flag = 1;else goto shit;}//¸¸Ç×½Úµã
            previous = pop;
            popnum ++;
            break;
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
