#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) {
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
}


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}
void merge_pass( ElementType list[], ElementType sorted[], int N, int length )
{
  int TmpPos = 0;
  int afterlength = length *2;
  int todo = (N/length %2 == 0?N/(length*2):N/(length*2)+1);
  int lpos = 0,rpos = 0;
//  printf("length = %d todo = %d\n",length,todo);
    for(int i = 0; i< todo; i++){
        lpos = i*afterlength;
        rpos = lpos + length;

        int lend = lpos + length -1 ;
        int rend = rpos + length -1 ;
//        printf("   lpos = %d rpos = %d \n   lend = %d rend = %d\n",lpos,rpos,lend,rend);
        while(lpos <= lend && rpos <= rend && rpos < N){
        if ( list[ lpos ] <= list[ rpos ] )
	sorted[ TmpPos++ ] = list[ lpos++ ];
        else
	sorted[ TmpPos++ ] = list[ rpos++ ];
        }
//        printf("fuck?\n");
//        printf("   lpos = %d rpos = %d \n   lend = %d rend = %d\n",lpos,rpos,lend,rend);
//
//    output(sorted, N);

    while( lpos <= lend ) /* Copy rest of first half */
        sorted[ TmpPos++ ] = list[ lpos++ ];
    while( rpos <= rend && rpos < N  ) /* Copy rest of second half */
        sorted[ TmpPos++ ] = list[ rpos++ ];
  }
  int flag = (N/length %2 == 0?1:0);
  if(flag)
  {
    for(int j = todo*afterlength; j < N; j++)
    sorted[j]=list[j];
  }




  return ;
}
