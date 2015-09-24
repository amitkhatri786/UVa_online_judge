#include<stdio.h>

void topo_sort(int mat[][15],int V);

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
#if 0
    for(i=0;i<V;i++)
    {
	for(j=0;j<V;j++)
	    printf("%d ",mat[i][j]);
	printf("\n");
    }
#endif
    topo_sort(mat,V);
    printf("\n");
    return(0);
}

void topo_sort(int mat[][15],  int V)
{
    int queue[100]={0};
    int indegree[15]={0};
    int front,rear; 
    int topo_order[15]={0};
    int counter=0;
    int v;
    int i,j;
    front = -1;
    rear = -1;

    for(i=0;i<V;i++)
	for(j=0;j<V;j++)
	    if(mat[j][i] == 1)
		indegree[i]++;


    front = 0;
    //rear = 0;
    for(i=0;i<V;i++)
	if(indegree[i] == 0)
	    queue[++rear] = i;

    while(front <= rear )
    {
	v = queue[front];
	front++;
	topo_order[v] = ++counter;
	printf("%d ",v+1);
	//visited[v]=1;
	for(i=0;i<V;i++)
	    if(mat[v][i] == 1 && --indegree[i] == 0)
		queue[++rear] = i;
    }
#if 0
    printf("ORDER IS -->> \n");
    for(i=0;i<V;i++)
	printf("%d  ",topo_order[i]);
#endif
}

