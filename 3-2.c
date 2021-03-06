#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push:

            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:

            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:

            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}
void PrintStack( Stack S, int Stacknum )
{

    if(Stacknum == 1)
    if(IsEmpty(S,1) == 0)
    for(int i = S->Top1-1;i>=0;i--)printf("%d ",S->Array[i]);printf("\n");

    if(Stacknum == 2)
    if(IsEmpty(S,2) == 0)
    for(int i = S->Top2+1;i<=S->Capacity-1;i++)printf("%d ",S->Array[i]);printf("\n");

}

Operation GetOp()
{
    char s[10];
    scanf("%s",&s);
    if(strcmp(s,"Push") == 0) return push;
    if(strcmp(s,"Pop") == 0) return pop;
    if(strcmp(s,"End")== 0)  return end;

}
Stack CreateStack( int MaxElements )
{
    Stack a = (Stack)malloc(sizeof(struct StackRecord));
    a->Capacity = MaxElements;
    a->Array = (ElementType *)malloc(sizeof(ElementType)*a->Capacity);
    a->Top1 = 0;
    a->Top2 = a->Capacity-1;
    return a;
}
int IsEmpty( Stack S, int Stacknum )
{
   if(Stacknum == 1) return S->Top1 == 0?1:0;
   else if(Stacknum == 2) return S->Top2 == S->Capacity-1?1:0;
}
int IsFull( Stack S )
{
    if(S->Top1-S->Top2 == 1) return 1;
    else return 0;
}
int Push( ElementType X, Stack S, int Stacknum )
{
   if(IsFull(S) == 0)
   {if(Stacknum == 1) S->Array[S->Top1++]=X;
    else S->Array[S->Top2--]=X; return 1;
   }
   else return 0;
}
ElementType Top_Pop( Stack S, int Stacknum )
{   if(IsEmpty(S,Stacknum) == 0){
    if(Stacknum ==  1) return S->Array[--S->Top1];
    else return S->Array[++S->Top2];}
    else if (IsEmpty(S,Stacknum)== 1)return ERROR;
}
