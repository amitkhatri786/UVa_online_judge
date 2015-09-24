#include<stdio.h>

int dfs(int mat[][15],int start,int V);

int visited[100]={0};
int path[100]={0};
int predecessor[100]={0};
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
	//	mat[c-1][r-1] =1;
    }
    for(i=0;i<V;i++)
    {
	for(j=0;j<V;j++)
	    printf("%d ",mat[i][j]);
	printf("\n");
    }
    for(i=0;i<V;i++)
    {
	if(!visited[i] && dfs(mat,i,V))
	    printf("main cycle has\n");
    }
    printf("\n");
    return(0);
}

int dfs(int mat[][15], int start, int V)
{
    int v;
    int j;

    printf("%d---> ",start+1); 
    visited[start]=1;
    for(v=0;v<V;v++)
    {
	if(mat[start][v])
	{
	    if(visited[v] && predecessor[v]!= start)
	    {
		printf("cycle detected at %d\n",v+1);
		predecessor[v] = start;
		for(j=0;j<V;j++)
		    printf("%d >> ",predecessor[j]+1);
		return 1;
	    }
	    else
	    {
		predecessor[v]=start;
		return (dfs(mat,v,V));
		//printf("%d-->",v+1);
	    }
	}
    }
    return(0);
}

