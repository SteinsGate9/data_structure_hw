#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};
int shit;
Tree BuildTree1();
Tree BuildTree2();
int Isomorphic( Tree T1, Tree T2 );

int main()
{
    Tree T1, T2,T3,T4;
    T1 = BuildTree1();
    T2 = BuildTree2();
//    T3 = (Tree)malloc(sizeof(struct TreeNode));
//    T4 = (Tree)malloc(sizeof(struct TreeNode));
//    T3->Left = NULL;
//    T3->Right  = NULL;
//    T4->Left = NULL;
//    T4->Right  = NULL;

    printf("%d\n", Isomorphic(T1, T2));

    return 0;
}

Tree BuildTree1()
{
    Tree n1 = (Tree)malloc(sizeof(struct TreeNode));
    n1->Element = 3;

    n1->Left = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Element = 5;

    n1->Right= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Element = 6;
    n1->Right->Right = NULL;

    n1->Right->Left= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Left->Element = 10;
    n1->Right->Left->Left = NULL;
    n1->Right->Left->Right =NULL;

    n1->Right->Left->Left= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Left->Left->Element = 100;
    n1->Right->Left->Left->Left = NULL;
    n1->Right->Left->Left->Right =NULL;

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

Tree BuildTree2()
{
     Tree n1 = (Tree)malloc(sizeof(struct TreeNode));
    n1->Element = 3;

    n1->Left = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Element = 6;
    n1->Left->Right = NULL;

    n1->Right= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Element = 5;
    n1->Right->Left = NULL;

    n1->Right->Right= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Right->Element = 1;
    n1->Right->Right->Left = NULL;
    n1->Right->Right->Right =NULL;

    n1->Left->Left = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Left->Element = 10;
    n1->Left->Left->Left = NULL;



    n1->Left->Left->Right  = (Tree)malloc(sizeof(struct TreeNode));
    n1->Left->Left->Right->Element =100;
    n1->Left->Left->Right->Left = NULL;
    n1->Left->Left->Right->Right = NULL;

    n1->Right->Left= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Left->Element = 8;
    n1->Right->Left->Right =NULL;

    n1->Right->Left->Left= (Tree)malloc(sizeof(struct TreeNode));
    n1->Right->Left->Left->Element = 9;
    n1->Right->Left->Left->Left = NULL;
    n1->Right->Left->Left->Right =NULL;





    return n1;
}
int Isomorphic( Tree T1, Tree T2 )
{

     Tree temp1 = T1;
     Tree temp2 = T2;
if(T1 == NULL &&T2 == NULL) return 1;
if(T1->Left == NULL && T1->Right == NULL && T2->Left == NULL && T2->Right == NULL){printf(">");return 1;}
else {
    shit ++;


     if(T1->Left == NULL)
     {   if(T2->Right == NULL)
          {if(T1->Right != NULL&& T2->Left != NULL)
            if(T1->Right->Element == T2->Left->Element)
             if(Isomorphic(T1->Right,T2->Left)  == 1) return 1;}
         else if(T2->Left == NULL)
         {if(T1->Right != NULL&& T2->Right != NULL)
            if(T1->Right->Element == T2->Right->Element)
              if(Isomorphic(T1->Right,T2->Right)  == 1) return 1;
         }
     }
     else if(T1->Left!=NULL && T2->Right!=NULL)
        {
         if(T1->Left->Element == T2->Right->Element){
        if(T1->Right != NULL && T2->Left != NULL)
        {if(T1->Right->Element == T2->Left->Element)
          if(Isomorphic(T1->Left,T2->Right) == 1&&Isomorphic(T1->Right,T2->Left) == 1)return 1;
        }
        else if(T1->Right == NULL&&T2->Left == NULL)if(Isomorphic(T1->Left,T2->Right) == 1) return 1;
        else return 0;
         }
        }
//    printf("%d\n",shit);
     else if(T1->Left!=NULL && T2->Left!=NULL)
        {
            if(T1->Left->Element == T2->Left->Element){
        if(T1->Right != NULL && T2->Right != NULL)
        {printf("?\n");
          if(T1->Right->Element == T2->Right->Element)
          if(Isomorphic(T1->Left,T2->Left) == 1&&Isomorphic(T1->Right,T2->Right) == 1)return 1;
        }
        else if(T1->Right == NULL&&T2->Right == NULL)if(Isomorphic(T1->Left,T2->Left) == 1) return 1;
        else return 0;
            }
        }






       return 0;
    }


}
