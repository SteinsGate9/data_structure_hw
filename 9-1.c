
#define infinity 100000
#include <stdio.h>
#include <stdlib.h>



typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */
void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );


int main()
{
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, count, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", count[V]);
    printf("\n");

    return 0;
}










void ShortestDist( MGraph g,int *dist,int *Shortest, Vertex x )
{   /* T is initialized by Figure 9.30 on p.303 */
    Vertex  V;
    int beenbefore[MaxVertexNum] ;

    int length[MaxVertexNum];
    int size = 1;
    for(int i = 0; i< MaxVertexNum; i++)
    {
      dist[i] = infinity;
      beenbefore[i] = 0;

      Shortest[i] = -1;
      length[i] = 0;
    }
      length[x] = 1;
      dist[x] = 0;



     while(size >= 1) {
        int min =10000;
        int flag=-100;

        V = 1000;
        for(int i =0  ; i<g->Nv ;i++)
        {
            if(dist[i]< min&&beenbefore[i] != 1)
          {
         V = i;
         min = dist[i];
          }
        }
         printf("this V = %d\n",V);
        if ( V >g->Nv+1 || V< 0)
    break;
         beenbefore[V] = 1 ;
      for ( int W = 0; W<g->Nv;W++)
  if(g->G[V][W] != 0)
	if ( beenbefore[W] == 0){
	    if ( dist[V] + g->G[V][W] <= dist[W] ) {
	      if(dist[V] + g->G[V][W] < dist[W])
	      {dist[W] = g->G[V][W]+ dist[V];
	       length[W]=length[V]+1;
	       Shortest[W] = V;
	      }
	      else
	      {
	          if(length[W] > length[V]+1)
	          {
                 length[W] = length[V]+1;
                 Shortest[W] = V;
	          }
	      }



	    } /* end-if update W */


	}
	  for(int i = 0 ;i<g->Nv; i++)printf("%d ",dist[i]);printf("\n");
	    for(int i = 0 ;i<g->Nv; i++)printf("%d ",length[i]);printf("\n");
	    for(int i = 0 ;i<g->Nv; i++)printf("%d ",Shortest[i]);printf("\n");
    } /* end-for( ; ; ) */


    for(int i = 0; i<g->Nv; i++)
    if(dist[i] == infinity)
    dist[i] = -1;

}

MGraph ReadG(){
 MGraph f= (MGraph)malloc(sizeof(struct GNode));
 f->Nv = 8;
 f->Ne = 11;
 for(int i = 0; i<f->Nv; i++)
    for(int j = 0; j<f->Nv ; j++)
 f->G[i][j] = 0;
f->G[0][4]  = 5;
f->G[0][7] = 10;
f->G[1][7]  = 40;
f->G[3][0]  = 40;
f->G[3][1]  = 20;
f->G[3][2]  = 100;
f->G[3][7]  = 70;
f->G[4][7]  = 5;
f->G[6][2]  = 1;
f->G[7][5]  = 3;
f->G[7][2]  = 50;

return f;



}

