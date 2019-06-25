#include<stdio.h>

#define MAX(x,y)    ((x>y)?x:y)
#define MIN(x,y)    ((x<y)?x:y)

int main()
{
    int line=0;
    int N,x;
    int x1ll,y1ll,x1ur,y1ur;
    int x2ll,y2ll,x2ur,y2ur;
    int X,Y,XX,YY;
    x = scanf("%d",&N);
    while(N--) {
        scanf("%d %d %d %d",&x1ll,&y1ll,&x1ur,&y1ur);
        scanf("%d %d %d %d",&x2ll,&y2ll,&x2ur,&y2ur);
        X = MAX(x1ll,x2ll);
        Y = MAX(y1ll,y2ll);
        XX = MIN(x1ur,x2ur);
        YY = MIN(y1ur,y2ur);
        if(X<XX && Y<YY)
            printf("%d %d %d %d\n",X,Y,XX,YY);
        else
            printf("No Overlap\n");
        if(N)
            printf("\n");
        line  = 1;

    }
    return(0);
}
