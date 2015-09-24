#include<stdio.h>

void dfs(int mat[][15], int u,int sum,int *max,int *position, int V);

int visited[100]={0};
int path[100]={0};
int weight[100]={0};
int main()
{

    int mat[15][15]={0};
    int i,j,k;
    int V,E;
    int r,c,w;
    int max=-9999;
    int position=-1;
    scanf("%d%d",&V,&E);
    for(i=0;i<V;i++)
	for(j=0;j<V;j++)
	    mat[i][j]=99999;
    for(i=0;i<E;i++)
    {
	scanf("%d%d%d",&w,&r,&c);
	mat[r-1][c-1] =w;
	mat[c-1][r-1] =w;
    }
    for(i=0;i<V;i++)
    {
	for(j=0;j<V;j++)
	    printf("%5d ",mat[i][j]);
	printf("\n");
    }
    dfs(mat,0,0,&max,&position,V);
    printf("\nmax %d at position %d\n",max,position);
    printf("\n");
    for(i=0;i<V;i++)
    {
	printf("%d  ",weight[i]);
	if(weight[i] > max )
	{
	    max=weight[i];
	    position=i;
	};
	weight[i]=0;
	visited[i]=0;
    }
    printf("\nmax %d at position %d\n",max,position);
    dfs(mat,position,0,&max,&position,V);
    printf("\n");
    max=-9999;
    for(i=0;i<V;i++)
    {
	printf("%d  ",weight[i]);
	if(weight[i] > max )
	{
	    max=weight[i];
	    position=i;
	};
	weight[i]=0;
	visited[i]=0;
    }
    printf("\nmax %d at position %d\n",max,position);
    printf("\n");
    return(0);
}

void dfs(int mat[][15], int u,int sum,int *max,int *position, int V)
{
    int v;
    int m,p;
    printf("%d---> ",u+1); 
    visited[u] = 1;
    weight[u]=sum;    
    printf("max =%d position %d\n",*max,*position);
    for(v=0;v<V;v++)
	if(mat[u][v] != 99999 && visited[v] != 1)
	{

	    dfs(mat,v,sum+mat[u][v],&m,&p,V);
	}
}

