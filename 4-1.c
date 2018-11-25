#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

typedef struct QueueNode *Queue;
struct QueueNode {
    Tree tree;
    Queue next;
};




void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}
Tree BuildTree();
void Level_order ( Tree T, void (*visit)(Tree ThisNode) );
void Pop(Queue t);
void Push(Queue t,Tree x);








int main()
{
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}


















Tree BuildTree()
{
    Tree n1 = (Tree)malloc(sizeof(struct TreeNode));
    n1->Element = 3;

    n1->Left = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Element = 5;

    n1->Right= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Element = 6;
    n1->Right->Left = NULL;

    n1->Right->Right= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Right->Element = 10;
    n1->Right->Right->Left = NULL;
    n1->Right->Right->Right =NULL;

    n1->Left->Left = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Left->Element = 1;
    n1->Left->Left->Left = NULL;
    n1->Left->Left->Right = NULL;


    n1->Left->Right  = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Right->Element =8;
    n1->Left->Right->Right = NULL;


    n1->Left->Right->Left= (Tree)malloc(sizeof(struct TreeNode));
     n1->Left->Right->Left->Element =9;
      n1->Left->Right->Left->Left = NULL;
       n1->Left->Right->Left->Right =NULL;



    return n1;
}
void Pop(Queue t)
{

   if(t->next)
   {
   Queue temp = t->next;
    if(t->next->next){t->next = t->next->next;}
    else t->next = NULL;
   free(temp);}
}
void Push(Queue t,Tree x)
{
    Queue temp = t;
    Queue m = (Queue)malloc(sizeof(struct QueueNode));
    m->tree =x ;
    while(temp->next != NULL)temp=temp->next;
    temp->next = m;m->next = NULL;
}
void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    if(T)
    {


    Tree temp = T;
   Queue q= (Queue)malloc(sizeof(struct QueueNode ));
   int flag = 0;
   int a = 0;
   q->next = NULL;
   Push(q,temp);
   while(q->next != NULL || flag == 0)
   {
     temp = q->next->tree;Pop(q);
     if(temp->Left){Push(q,temp->Left);}
     if(temp->Right){Push(q,temp->Right);}
     (*visit)(temp);
     flag  = 1;


   }
     }
    else
   return;
}
