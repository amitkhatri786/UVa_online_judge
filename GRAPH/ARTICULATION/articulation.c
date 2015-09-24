#include<stdio.h>

void dfs(int mat[][15],int start,int V);

int visited[100]={0};
int path[100]={0};
int numdfs[100]={0};
int low[100]={0};
int parent[100]={0};
int counter=0;

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
	numdfs[i]=-1;
	parent[i]=-1;
    }
    dfs(mat,0,V);
    for(i=0;i<V;i++)
	printf(" parent of  %d is %d\n",i,parent[i]);
    for(i=0;i<V;i++)
	printf("low = %d numdfs= %d\n",low[i],numdfs[i]);
    printf("\n");
    return(0);
}

void dfs(int mat[][15], int u, int V)
{
    int v;

    //printf("%d---> ",start+1); 
    numdfs[u]=low[u]=counter++;
    for(v=0;v<V;v++)
	if(mat[u][v] == 1 && numdfs[v] == -1)
	{
	    parent[v]=u;
	    dfs(mat,v,V);
	    if(low[v]>= numdfs[u])
		printf("%d node is articulation\n",u+1);
	    low[u]=min(low[u],low[v]); 

	}
	else if(parent[v] !=u);
	{
	    low[u]=min(low[u],low[v]);
	}
    //  return;
}

int min(int a,int b)
{

    if(a>b)
	return b;
    else
	return a;
}
