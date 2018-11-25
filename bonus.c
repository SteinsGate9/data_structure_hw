#include<stdio.h>
#include<malloc.h>
#define MAXNUM 30
typedef struct tree* treenode;
struct tree{
    treenode left;
    treenode right;
    int treeid;
    int level;
 };
typedef struct stack* stacknode;
struct stack{
   stacknode next;
   treenode  mytree;
};
int post[MAXNUM];
int inde[MAXNUM];
int result[MAXNUM][MAXNUM];
treenode Buildtree(int post[], int inde[], int index);
void Push(stacknode t,treenode x);
void Pop(stacknode t);
stacknode top(stacknode bce);





int main()
{
   int n;
   int num = 0;
   int layer = 0;
   result[0][0] = 1;
   stacknode BCE = (stacknode)malloc(sizeof(struct stack));
   BCE->next = NULL;
   scanf("%d",&n);
   for(int i=1; i<=n; i++)result[0][i] = 0;
   for(int i=1; i<=n; i++)scanf("%d",&inde[i]);
   for(int i=1; i<=n; i++)scanf("%d",&post[i]);
   treenode ACE = Buildtree(post,inde,n);

   Push(BCE,ACE);
   result[0][1] = ACE->treeid;
   while(BCE->next!=NULL)
   {

        treenode temp = top(BCE)->mytree;
        Pop(BCE);

       if(temp->left)
       {
          treenode tempson = temp->left;
          tempson->level = temp->level + 1;
//          printf("level = %d node = %d\n",tempson->level,tempson->treeid);
          if(tempson->level > layer) {layer = tempson->level;num =0;}
          Push(BCE,tempson);
          result[layer][0] ++;num++;
          result[layer][num] = tempson->treeid;
       }
       if(temp->right)
       {
          treenode tempson = temp->right;
          tempson->level = temp->level + 1;
//          printf("level = %d node = %d\n",tempson->level,tempson->treeid);
          if(tempson->level > layer) {layer = tempson->level;num =0;}
          Push(BCE,tempson);
          result[layer][0] ++;num++;
          result[layer][num] = tempson->treeid;
       }


   }
   int cure = 0 ;
   int c= 0;
      while(result[cure][0] != 0)
      {
        if(c==0)
        { if(cure % 2 == 1)
          for(int i = 1; i <= result[cure][0]; i++)printf("%d",result[cure][i]);
          else
          for(int i = 1; i <= result[cure][0]; i++)printf("%d",result[cure][result[cure][0]-i+1]);
          cure++;c++;
        }
        else {
          if(cure % 2 == 1)
          for(int i = 1; i <= result[cure][0]; i++)printf(" %d",result[cure][i]);
          else
          for(int i = 1; i <= result[cure][0]; i++)printf(" %d",result[cure][result[cure][0]-i+1]);
          cure++;
        }
      }



return 0;
}

treenode Buildtree(int post[], int inde[], int index)
{
    treenode fuck = (treenode)malloc(sizeof(struct tree));
    int current = post[index];
    int realn  = index;

    if(index<=0)
        return NULL;
    while(current != inde[index--]){;}index++;
    fuck->treeid = current;
    fuck->level = 0;
//    printf("%d\n",current);
    fuck->left = Buildtree(post,inde,index-1);
    fuck->right= Buildtree(post+index-1,inde+index,realn-index);

    return fuck;
}

void Pop(stacknode t)
{

   if(t->next)
   {
   stacknode temp = t->next;
    if(t->next->next){t->next = t->next->next;}
    else t->next = NULL;
   free(temp);}
}
void Push(stacknode t,treenode x)
{
    stacknode temp = t;
    stacknode m = (stacknode)malloc(sizeof(struct stack));
    m->mytree = x ;
    while(temp->next != NULL)temp=temp->next;
    temp->next = m;m->next = NULL;
}
stacknode top(stacknode bce)
{
    if(bce->next != NULL)
        return bce->next;

}
