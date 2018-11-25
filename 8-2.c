#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define max_m 100
#define MaxVertexNum 100
typedef int Vertex;
typedef struct node* queue;
struct node{
  int max[max_m+1];
  int capacity;
  int front;
  int rear;
};
typedef enum{false,true} bool;
queue initial();
void enqueue(queue x,int p);
int dequeue(queue x);
bool empty(queue x);
bool full(queue x);



typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    int weight;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(int a, int b);
int TopSort( LGraph Graph );
int IndeGree(LGraph g ,int V);
int earlist[max_m];
int Max(LGraph G);





int main()
{

    int i;
    int a,b;

    scanf("%d%d",&a,&b);
    LGraph G = ReadG(a,b);

    if ( TopSort(G) != -1 )
       {
        printf("%d\n",TopSort(G));
       }
    else
        printf("Impossible\n");
    return 0;
}

LGraph ReadG(int a, int b)
{
    LGraph gg = (PtrToGNode)malloc((sizeof(struct GNode)));
    gg->Nv = a;
    gg->Ne = b;
    for(int i = 0;i < a;i++)
    {
        gg->G[i].FirstEdge = (PtrToAdjVNode)malloc((sizeof(struct AdjVNode)));
        gg->G[i].FirstEdge->AdjV = -1;
        gg->G[i].FirstEdge->weight = -1;
        gg->G[i].FirstEdge->Next = NULL;
    }

    while(b--)
    {
        int q,m,w;

      scanf("%d%d%d",&q,&m,&w);
      PtrToAdjVNode temp = (PtrToAdjVNode)malloc((sizeof(struct AdjVNode)));
      temp->AdjV = m;
      temp->Next = NULL;
      temp->weight = w;

      PtrToAdjVNode temp2 = gg->G[q].FirstEdge;
      while(temp2->Next)
        temp2= temp2->Next;
//      printf("ok");
      {
      temp2->Next = temp;
//      printf("%d--->%d\n",q,gg->G[q].FirstEdge->Next->AdjV);
      }
    }
    return gg;





}
int Max(LGraph G)
{
    int max = 0;


    return max;
}
queue initial()
{
    queue x = (struct node*)malloc(sizeof(struct node));
    for(int i = 0 ; i<= max_m; i++) x->max[i] =0 ;
    x->front = 0;
    x->rear = 0;
    x->capacity = 0;
    return x;
}
void enqueue(queue x,int p)
{
   if(full(x) != true)
   {
    x->max[(++x->rear)%(max_m+1)] = p;
    x->rear = x->rear%(max_m +1);
    x->capacity++;
   }
}
int dequeue(queue x)
{
    int  p = 0;
    if(empty(x) == false)
   {
    p = x->max[(++x->front)%(max_m+1)];
    x->front = (x->front)%(max_m+1);
////    printf("front = %d ",x->max[(++x->front)%(max_m+1)] );
//    printf("p = %d",p);
    x->capacity--;
   }
   return p;
}
bool empty(queue x)
{
    if ((x->rear)%(max_m+1) != x->front &&x->capacity != 0)
        return false;
    else return true;
}
bool full(queue x)
{
    if((x->rear+1)%(max_m+1) == x->front &&x->capacity == max_m)
        return true;
    else return false;
}
int IndeGree(LGraph g ,int V)
{
  int count = 0;

  for(int i = 0; i<g->Nv; i++)
  {
//      printf("this nv = %d\n",g->Nv);
    PtrToAdjVNode x = g->G[i].FirstEdge;
    while(x)
    {
      if(x->AdjV == V) {
//            printf("%d->%d\n",i,x->AdjV);
            count++;}
      x= x->Next;
//      printf("????\n");
    }
  }
  return count;

}
int TopSort( LGraph Graph)
{

    queue  Q = initial();

    int  Counter = 0,t=0,now = 0;
    int Indegree[max_m];
    PtrToAdjVNode temp ;
    Vertex  V, W;

    for(int i = 0;i< Graph->Nv; i++) {Indegree[i] = 0;earlist[i]= 0;}
    for(int i = 0;i< Graph->Nv; i++)
    {
//        printf("fuck");
      Indegree[i] = IndeGree(Graph,i);
//      printf("indegree = %d\n",Indegree[i]);
    }

    for (int i = 0; i< Graph->Nv; i++ )
    if ( Indegree[i] == 0 )
    {enqueue(Q,i);}
    while ( empty(Q) != true ) {
    V = dequeue(Q);
    Counter++;
	temp = Graph->G[V].FirstEdge;
	int jiedian = V;
	while (temp){
	    if ( --Indegree[temp->AdjV] == 0 )
            {
                enqueue(Q,temp->AdjV);
            }
        if( temp->AdjV != -1){
                  if(earlist[jiedian]+ temp->weight > earlist[temp->AdjV])
                    {
                        earlist[temp->AdjV] = earlist[jiedian]+ temp->weight  ;
//                        printf("this %d er = %d\n",temp->AdjV,earlist[temp->AdjV]);
                    }
                             }


                  temp = temp->Next;

            }

	}
	  /* end-while */

    if ( Counter != Graph->Nv )
	   return -1;

    free(Q); /* free memory */
    int fuckyou = -100;
    for(int i = 0;i <Graph->Nv; i++)
    {
        if(earlist[i] > fuckyou)
            fuckyou = earlist[i];
    }

       return fuckyou;



}
