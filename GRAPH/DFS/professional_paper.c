#include<stdio.h>

void dfs(int mat[][15],int start,int V);

int visited[100]={0};
int path[100]={0};
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
    dfs(mat,0,V);
    printf("\n");
    return(0);
}

void dfs(int mat[][15], int start, int V)
{
    int v;

    printf("%d---> ",start+1); 
    visited[start] = 1;
    for(v=0;v<V;v++)
	if(mat[start][v] == 1 && visited[v] != 1)
	{ 
	    //visited[start] = 1;
	    dfs(mat,v,V);
	}
    //  return;
}

