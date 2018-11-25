#include <stdlib.h>
#include <stdio.h>
#define MAXNUM 20



typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
int CheckBST ( BinTree T, int K );
void Inversal(BinTree X,int *maxnum,int *maxheight);
int result[MAXNUM];
int n ;
int aaaa;
int main()
{
    BinTree T;
    int K, out;

    T = BuildTree();
    scanf("%d", &K);
    out = CheckBST(T, K);
    if ( out < 0 )
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);

    return 0;
}


int CheckBST ( BinTree T, int K )
{

    for(int i =0; i<= MAXNUM; i++)result[i] = 101;
    int b = 0;
    int maxheight = 1;
    int flag = 0;
    aaaa = 1;
    n = 0;
    printf("before1 n = %d\n",n);
   Inversal(T,&b,&maxheight);

    for(int i = 0; i<= b-1; i++) {
        if (result[i] > result[i+1])
        {
            flag = 1;

            break;
        }
    }
    if(b == 1) flag = 1;
    if(flag == 0 )
        return result[b-K];
    else
    {
        return  -maxheight;
    }

}
void Inversal(BinTree X,int *maxnum,int *maxheight)
{

    if(X->Left) {aaaa++;Inversal(X->Left,maxnum,maxheight);}
    printf("before n = %d",n);
    {result[n++] = X->Key;(*maxnum)++;printf("the %d = %d\n",n-1,result[n-1]);}

    if(X->Right) {aaaa++;Inversal(X->Right,maxnum,maxheight);}
    if(*maxheight < aaaa) *maxheight = aaaa;
    aaaa --;
    return;
}

BinTree BuildTree()
{
    BinTree  head = (BinTree)malloc(sizeof(struct TNode));
    BinTree  head2 = head;
    int x;
    scanf("%d",&x);
    head->Key = x;head->Left = NULL;head->Right =NULL;
    while(x != -1)
    {
        scanf("%d",&x);
        if(x == -1)break;
        BinTree  n1 = (BinTree)malloc(sizeof(struct TNode));
        n1->Key = x; n1->Right = NULL; n1->Left =   NULL;
        while(head2->Left != NULL&&x < head2->Key || head2->Right != NULL && x > head2->Key) {
            if (x > head2->Key && head2->Right)head2 = head2->Right;
            if (x < head2->Key && head2->Left)head2 = head2->Left;
        }
        if(x > head2->Key){head2->Right = n1;}
        if(x < head2->Key){head2->Left = n1;}
        head2 = head;
    }
    return head;
}
