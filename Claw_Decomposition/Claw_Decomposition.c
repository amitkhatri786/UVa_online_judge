#include<stdio.h>

int bfs(int mat[][301],int start,int V);

int color[301]={0};

int main()
{

    int mat[301][301]={0};
    int i,j,k;
    int V,E;
    int r,c;
    int t;
    int sol=0;
    int ans=0;
    for(i=0;i<301;i++)
	color[i] = -1;
    while((scanf("%d",&V) == 1 ) && V)  
    {
	while((scanf("%d%d",&r,&c)==2) && r && c)
	{
	    mat[r-1][c-1] =1;
	    mat[c-1][r-1] =1;
	}
	/*	for(i=0;i<V;i++)
		{
		for(j=0;j<V;j++)
		printf("%d ",mat[i][j]);
		printf("\n");
		}
	 */
	if(bfs(mat,0,V))
	    printf("YES\n");
	else
	    printf("NO\n");

	for(i=0;i<V;i++)
	{
	    for(j=0;j<V;j++)
		mat[i][j] = 0;
	    color[i]= -1;

	}
    }
    return(0);
}


int bfs(int mat[][301], int start, int V)
{
    int queue[2000]={0};
    int front,rear; 
    int v,x;
    int total=0;
    int i;
    front = -1;
    rear = -1;
    int color_count=0;

    color[start] = 1;
    front = 0;
    rear = 0;
    queue[rear] = start;
    while(front <= rear )
    {
	v = queue[front];
	front++;
	total++;
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
		    return(-1);
	    }
	}  
    }
    /*	printf("total = %d\n",total); 
	printf("\n color_count = %d and total-color_count = %d\n",color_count,total-color_count); */
    return(1);
} 
