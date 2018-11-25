#include <stdio.h>
#include <stdlib.h>
struct  Node;
typedef struct Node* ptonode;
typedef double ElementType;
struct  Node{
   char shit;ElementType element;ptonode next;
};
typedef ptonode Stack;

#define Infinity 1e9
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );
Stack CreateStack();
ElementType Calculate2(ElementType num1,ElementType num2,char c);
int Priority(char c);
Stack CreateStack();
ElementType Pop(Stack a);
char Pop2(Stack a);
ElementType Pop(Stack a);
void Push2(char x,Stack b);
void Push(ElementType x,Stack b);





int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);

//    Push(1000,a);
//    Push(100,a);
//    printf("%f\n",Pop(a));
//    printf("%f\n",Pop(a));
//    printf("fucyou");
//    printf("%f",atoi(expr));
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}
ElementType Calculate2(ElementType num1,ElementType num2,char c)
{
	switch(c)
  {
	case '+':return num1 + num2;
	case '-':return num1 - num2;
	case '*':return num1 * num2;
	case '/':return num1 / num2;
  }
}

int Priority(char c)
{
    if( c == '+'||c == '-')
     return 1;
    if( c == '*'||c == '/')
     return 2;
}
Stack CreateStack()
{
   ptonode a = (ptonode)malloc(sizeof(struct Node));
   a->next = NULL;
   return a;
}
char Pop2(Stack a)
{   char temp;
     if(a->next != NULL)
    {
        temp = a->next->shit;
        ptonode temp2 = a->next;
        if(a->next->next != NULL)
        a->next = a->next->next;
        else a->next = NULL;
        free(temp2);
         return temp;
    }
    else if(a->next == NULL)
    return '0';

}
ElementType Pop(Stack a)
{   ElementType temp;
     if(a->next != NULL)
    {
        temp = a->next->element;
        ptonode temp2 = a->next;
       if(a->next->next != NULL)
        a->next = a->next->next;
        else a->next = NULL;
        free(temp2);
        return temp;
    }
    else
        return Infinity;
}
void Push2(char x,Stack b)
{

       ptonode a = (ptonode)malloc(sizeof(struct Node));
       a->shit = x;
       a->next = b->next;
       b->next = a;

     return;
}
void Push(ElementType x,Stack b)
{
    ptonode a = (ptonode)malloc(sizeof(struct Node));


       a->element = x;
       a->next = b->next;
       b->next = a;

     return;
}
ElementType EvalPostfix( char *expr )
{
    Stack a = CreateStack();
    Stack b = CreateStack();
    char *curse =  expr;
    int xiaoshu = 0;
    int fuhao = 1;
    double power = 1;
    double temp=0;
    while(*curse != '\0')
    {
          if(*curse == '-'&& *(curse+1) != ' '&& *(curse+1) != '\0')
          {fuhao = -1;curse++;}
          if(*curse >= '0' && *curse <= '9')
         {
            while(*curse >= '0' && *curse <= '9')
            {
               temp = temp*10+(*curse++-'0');
            }
            if(*(curse)== '.')
           {
                curse ++;
           }
            while(*curse >= '0' && *curse <= '9')
            {
               temp = temp*10+(*curse++-'0');
               power*=10;
            }
            Push(fuhao*temp/power,a);
            fuhao = 1;
            power = 1;
            temp  = 0;
         }


      if(*curse == '*'||*curse == '+'||*curse == '-'||*curse == '/')
    {


           ElementType x = Pop(a);ElementType y = Pop(a);
           if(*curse == '/' && x == 0)return Infinity;
           if(x==Infinity||y==Infinity)return Infinity;

           Push(Calculate2(y,x,*curse++),a);

    }


        if(*curse == ' ')
        curse ++;
    }

       if(a->next->next != NULL)
        return Infinity;

        return a->next->element;


}
