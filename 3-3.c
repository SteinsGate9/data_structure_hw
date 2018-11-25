#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push:
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject:
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}
void PrintDeque( Deque D )
{
    for(PtrToNode n = D->Front->Next;n != NULL;n = n->Next){printf("%d ",n->Element);}
}
Operation GetOp()
{
    char s[10];
    scanf("%s",&s);
    if(strcmp(s,"Push") == 0)   return push;
    if(strcmp(s,"Pop") == 0)    return pop;
    if(strcmp(s,"Inject") == 0) return inject;
    if(strcmp(s,"Eject") == 0)  return eject;
    if(strcmp(s,"End")== 0)     return end;
}
Deque CreateDeque()
{
    Deque a = (Deque)malloc(sizeof(struct DequeRecord));
    a->Rear = a->Front = (PtrToNode)malloc(sizeof(PtrToNode));
    a->Front->Last = NULL;
    a->Rear->Next = NULL;
    return a;
}
int Push( ElementType X, Deque D )
{
  PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
  temp->Element = X;
  if(temp != NULL)
  {
    if(D->Front->Next != NULL){temp->Next = D->Front->Next;D->Front->Next->Last = temp;}
    else {temp->Next = NULL;  D->Rear = temp;}
  D->Front->Next = temp;
  temp->Last = D->Front;
  return 1;
  }
  return 0;
}
ElementType Pop( Deque D )
{
  if(D->Front->Next != NULL)
  {PtrToNode temp2 = D->Front->Next;ElementType temp ;
  if(D->Front->Next!=D->Rear){temp = D->Front->Next->Element;D->Front->Next->Next->Last = D->Front;D->Front->Next = D->Front->Next->Next;
  }
  else {temp = D->Front->Next->Element;D->Front->Next = NULL;D->Rear = D->Front;}
  return temp;
  }
  else return ERROR;
}
int Inject( ElementType X, Deque D )
{
 PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
 temp->Element = X;
  if(temp != NULL)
  {temp->Next = NULL;temp->Last= D->Rear;D->Rear->Next = temp;D->Rear = temp;

  return 1;
  }
  return 0;
}
ElementType Eject( Deque D )
{
  if(D->Rear!=D->Front)
  {ElementType temp;PtrToNode a= D->Rear;
   temp = D->Rear->Element;D->Rear= D->Rear->Last;D->Rear->Next=NULL;free(a);
  return temp;
  }
  else return ERROR;
}
