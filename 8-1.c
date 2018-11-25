
#include <stdio.h>
#include <stdlib.h>
typedef int* queue;
typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
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

LGraph ReadG(); /* details omitted */

bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    int a ,b;
    Vertex TopOrder[MaxVertexNum];
    scanf("%d%d",&a,&b);
    LGraph G = ReadG(a,b);

    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

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
        gg->G[i].FirstEdge->Next = NULL;

    }

    while(b--)
    {
        int q,m,w;

      scanf("%d%d",&q,&m);
      PtrToAdjVNode temp = (PtrToAdjVNode)malloc((sizeof(struct AdjVNode)));
      temp->AdjV = m;
      temp->Next = NULL;


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

bool TopSort( LGraph Graph, Vertex TopOrder[] )
{
    int Indegree[MaxVertexNum]={0};
    int  front = 0;
    int  rear = 0; int  V;
    queue Q = (int *)malloc(sizeof(int)*(Graph->Nv+10));
    for(int i = 0;i <= Graph->Nv+9; i++)Q[i] = -1;

    int  Counter = 0,t=0,now = 0;

    PtrToAdjVNode temp =NULL;



 for(int i = 0; i<Graph->Nv; i++)
  {
//      printf("this nv = %d\n",g->Nv);
    PtrToAdjVNode x = Graph->G[i].FirstEdge;
    while(x)
    {

//            printf("%d->%d\n",i,x->AdjV);
      Indegree[x->AdjV] ++;
      x= x->Next;
//      printf("????\n");
    }
//      printf("indegree = %d\n",Indegree[i]);
  }

    for (int i = 0; i< Graph->Nv; i++ )
    if ( Indegree[i] == 0 )
    {
      Q[rear++] = i;
    }
    while ( front < rear ) {
    V = Q[front++];
//    printf("pop V = %d\n",V);
	TopOrder[ Counter++ ] = V; /* assign next */
	temp = Graph->G[V].FirstEdge;
	while (temp){
	    if ( --Indegree[temp->AdjV] == 0 )
	    { Q[rear++] = temp->AdjV;}
	   temp = temp->Next;
	}
	}  /* end-while */

    if ( Counter != Graph->Nv )
	   return false;

    /* free memory */
     return true;



}



