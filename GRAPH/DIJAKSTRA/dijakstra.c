#include<stdio.h>

void bfs(int mat[][15],int start,int V);

int main()
{

    int mat[15][15]={0};
    int i,j,k;
    int V,E;
    int r,c,w;
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++)
    {
	scanf("%d%d%d",&r,&c,&w);
	mat[r-1][c-1] = w;
    }
    for(i=0;i<V;i++)
    {
	for(j=0;j<V;j++)
	    printf("%d ",mat[i][j]);
	printf("\n");
    }
    bfs(mat,0,V);
    printf("\n");
    return(0);
}

void bfs(int mat[][15], int start, int V)
{
    int visited[15]={0};
    int D[15]={0};
    int u,v;
    int i;
    for(i=0;i<15;i++)
	D[i] = 999999;

    D[start] = 0;
    while(isempty(visited,V))
    {
	u = min_ditance_queue(D,visited,V);
	for(v=0;v<V;v++)
	{
	    if(mat[u][v] != 0 && (D[v] > (D[u] + mat[u][v])))
		D[v] = D[u] + mat[u][v];	
	}  
	visited[u]=1;
    }

    for(i=0;i<V;i++)
	printf("%d        =    %d\n",i,D[i]);	

}

int isempty(int visited[],int V)
{

    int i;
    int flag = 1;
    for(i=0;i<V;i++)
	if(visited[i] == 0 )
	    break;

    if(i==V)
	return(0);
    else
	return(1);
}

int min_ditance_queue(int D[],int visited[], int V)
{
    int pos,min=-99999;
    int i;
    for(i=0;i<V;i++)
    {
	if(min >= D[i] && visited[i] != 1)
	{
	    min = D[i];
	    pos = i;
	}
    }
    return(pos);

}
