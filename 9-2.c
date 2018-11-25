
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#define infinity 100000
#define MaxVertexNum 1000
#define zuixiao 42.5
#define banjing 7.5

typedef struct node* Graph;
struct node{
int Nv;
int ne;
int G[MaxVertexNum][MaxVertexNum];
};
struct zuobiao{
int x;
int y;
int dis;
int index;
};
int comp(const void*a,const void*b)//用来做比较的函数。
{
    return (*(struct zuobiao*)a).dis-(*(struct zuobiao*)b).dis;
}
int capacity ;
int size;
struct zuobiao xin[MaxVertexNum];
int Short[MaxVertexNum];
int Before[MaxVertexNum];

Graph ReadG(struct zuobiao*);
int ShortestDist(struct zuobiao* xin, Graph Graph, int dist[], int count[], int S );

int far(int a,int b,int c,int d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
int issafe(struct zuobiao x)
{
    if(x.x>= 50-capacity) return 1;
    if(x.y>= 50-capacity) return 1;
    if(x.x<= -50+capacity) return 1;
    if(x.y<= -50+capacity) return 1;
    return 0;
}

int main()
{

    int Queue[MaxVertexNum];
    int bitch[MaxVertexNum];


     scanf("%d%d",&size,&capacity);

     if(capacity >= 42.5){printf("1");return 0;}


     xin[0].index = 0;
     xin[0].dis = 0;
     xin[0].x= 0;
     xin[0].y= 0;
     for(int i = 1; i<= size; i++){scanf("%d%d",&xin[i].x,&xin[i].y);xin[i].dis = far(xin[i].x,xin[i].y,0,0);xin[i].index = i;}

     qsort(xin,size+1,sizeof(xin[0]),comp);
     Graph my = ReadG(xin);
     int Escape = ShortestDist(xin,my,Short,Before,0);
     if(Escape >0)
      printf("%d\n",Short[Escape]);
     else
     {printf("0");return 0;}

    int rear = 0;
    for(int q = Escape;q != 0;q = Before[q])
    {
        Queue[rear++] = q;
    }

    for(int i = rear-1;i>=0;i--)
    printf("%d %d\n",xin[Queue[i]].x,xin[Queue[i]].y);
    return 0;
}


Graph ReadG(struct zuobiao* xin)
{
      Graph G = (Graph)malloc(sizeof(struct node));
      G->Nv = size;


        for(int i = 0; i<=size; i++)for(int j = 0; j<=size; j++)G->G[i][j] = 0;
        for(int i = 0; i<=size; i++)for(int j = i+1; j<=size; j++)
       {
           if(far(xin[j].x,xin[j].y,0,0)>7.5*7.5){
//           printf("%d  %d\n",far(xin[i].x,xin[i].y,xin[j].x,xin[j].y), capacity*capacity);
           if(i!=0&&(far(xin[i].x,xin[i].y,xin[j].x,xin[j].y) <= capacity*capacity))
           {
            G->G[i][j] = 1;
            G->G[j][i] = 1;
           }
           if(i == 0&&(far(xin[i].x,xin[i].y,xin[j].x,xin[j].y)<= (7.5+capacity)*(7.5+capacity)))
           {
//               printf("fuck = %lf\n",fuck);
            G->G[i][j] = 1;
            G->G[j][i] = 1;
           }}
       }
           for(int i = 0; i<=size; i++)
       {

       for(int j = 0; j<=size; j++)
        printf("%d ",G->G[i][j]);
       printf("\n");}


    return G;
}

int ShortestDist(struct zuobiao* xin,Graph g,int *length,int *Shortest, int x )
{   /* T is initialized by Figure 9.30 on p.303 */
    int  V;
    int beenbefore[MaxVertexNum] ;

    int size = 1;
    int rear = 0;
    int front = 0;
    int Queue[MaxVertexNum];

    for(int i = 0; i< MaxVertexNum; i++)
    {
      beenbefore[i] = 0;
      Shortest[i] = -1;
      length[i] = infinity;
    }
      length[x] = 1;
      Queue[rear++] =x;



     while(front < rear) {


        V = 1000;
        V = Queue[front++];
//         printf("this V = %d\n",V);
         if(issafe(xin[V]) == 1)
            return V;
         beenbefore[V] = 1 ;
  for ( int W = 0; W<g->Nv;W++)
    if(g->G[V][W] != 0)if ( beenbefore[W] == 0){
	    if ( length[V] + g->G[V][W] < length[W] )
        {
	       length[W]=length[V]+1;
	       Shortest[W] = V;
           Queue[rear++]=W;
	    } /* end-if update W */
	}
//	  for(int i = 0 ;i<g->Nv; i++)printf("%d ",dist[i]);printf("\n");
//	    for(int i = 0 ;i<g->Nv; i++)printf("%d ",length[i]);printf("\n");
//	    for(int i = 0 ;i<g->Nv; i++)printf("%d ",Shortest[i]);printf("\n");
    } /* end-for( ; ; ) */
    for(int i = 0; i<g->Nv; i++)
    if(length[i] == infinity)
    length[i] = -1;
    return -1000;

}

