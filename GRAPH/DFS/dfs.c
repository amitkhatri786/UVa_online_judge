#include<stdio.h>

void dfs(int mat[][15],int start,int V);
void print_cycle(int stack[],int node,int upto, int V);

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
	dfs(mat,i,V);
	printf("\n");
    }
    return(0);
}

void dfs(int mat[][15],int start, int V)
{

    int visited[100]={0};
    int path[100]={0};
    int top=-1;
    int stack[100];
    int s[101]={0};
    int j=0;
    int i;
    int u,v;
    int flag =0;

    top++;
    stack[top] = start;
    visited[start] = 1;
    while(top >= 0)
    {
       flag = 0;
	u = stack[top];
	top--;
	s[j++] = u;
	printf("%d --->",u+1);
	for(v=V-1;v>=0;v--)
	{
	    if(mat[u][v] == 1 && visited[v] == 1)
	    {
		if(isinstack(s,v,V))
		{ //printf("already in stack\n");
                   printf("\n%d node form a cycle\n",v+1);
                   print_cycle(s,v,j,V);
                   return;
		}
	    }
	    if(mat[u][v] == 1 && visited[v] != 1)
	    {
		stack[++top] = v;
		visited[v] = 1;
		flag = 1;
	    }
                    
	}
	if(flag == 0)
	{
	    printf("\nnode %d is does no have adjecent \n",u+1);
	    j--;
	}
    }
}

void print_cycle(int stack[],int node,int upto, int V)
{
    int i=0;
    int j;
    for(i=0;i<V;i++)
	if(stack[i]== node)
	    break;
    printf("Cycle is ----> ");
    for(j=i;j<upto;j++)
	printf("%d >>> ",stack[j]+1);

}

int isinstack(int stack[],int node,int V)
{
    int i=0;
    for(i=0;i<V;i++)
	if(stack[i] == node)
	    return 1;

    return 0;

}

#if 0
void dfs(int mat[][15], int start, int V)
{
    int v;

    printf("%d---> ",start+1); 
    if(visited[start])
	return;
    visited[start] = 1;
    for(v=0;v<V;v++)
	if(mat[start][v] == 1 && visited[v] == 0)
	    dfs(mat,v,V);
    //  return;
}
#endif

