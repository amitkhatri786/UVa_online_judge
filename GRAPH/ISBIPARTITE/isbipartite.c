#include<stdio.h>

int bfs(int mat[][15],int start,int V);

int main()
{

    int mat[15][15]={0};
    int i,j,k;
    int V,E;
    int r,c;
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++)
    {
	scanf("%d%d",&r,&c);
	mat[r-1][c-1] =1;
	mat[c-1][r-1] =1;
    }
    for(i=0;i<V;i++)
    {
	for(j=0;j<V;j++)
	    printf("%d ",mat[i][j]);
	printf("\n");
    }
    if(bfs(mat,0,V))
	printf("YES\n");
    else
	printf("NO\n");
    printf("\n");
    return(0);
}

int bfs(int mat[][15], int start, int V)
{
    int queue[100]={0};
    int color[15]={0};
    int front,rear; 
    int v;
    int i;
    front = -1;
    rear = -1;
    for(i=0;i<15;i++)
	color[i]=-1;

    color[start] = 1;

    front = 0;
    rear = 0;
    queue[rear] = start;
    //	front = front + 1;

    while(front <= rear )
    {
	v = queue[front];
	front++;
	printf("%d --->  ",v+1);
	//	color[v]=1;
	for(i=0;i<V;i++)
	{
	    if(mat[v][i] == 1 && color[i] == -1)
	    {
		color[i] = 1 - color[v];
		queue[++rear] = i;

	    }
	    else
	    {
		if(mat[v][i] == 1 && color[i] == color[v])
		    return(0);

	    }
	}  
    }
    printf("\n SET 1 ==  ");
    for(i=0;i<V;i++)
	if(color[i]==1)
	    printf("%d ---> ",i+1);
    printf("\n SET 2 ==  ");
    for(i=0;i<V;i++)
	if(color[i]==0)
	    printf("%d ---> ",i+1);
printf("\n");
    return(1);
}

