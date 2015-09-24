#include<stdio.h>

void topo_sort(int mat[][101],int V);

int main()
{

    int mat[101][101]={0};
    int i,j,k;
    int V,E;
    int r,c;
    while((scanf("%d%d",&V,&E)==2) && (V || E))
{
    for(i=0;i<E;i++)
    {
	k=scanf("%d%d",&r,&c);
	mat[r-1][c-1] =1;
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
    for(i=0;i<V;i++)
     for(j=0;j<V;j++)
	mat[i][j] = 0;
    printf("\n");
}
    return(0);
}

void topo_sort(int mat[][101],  int V)
{
    int queue[1000]={0};
    int indegree[101]={0};
    int front,rear; 
    int topo_order[101]={0};
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
    for(i=V-1;i>=0;i--)
	if(indegree[i] == 0)
	    queue[++rear] = i;

    while(front <= rear )
    {
	v = queue[front];
	front++;
	topo_order[counter++] = v+1;
	for(i=V-1;i>=0;i--)
	    if(mat[v][i] == 1 && --indegree[i] == 0)
		queue[++rear] = i;
    }

    for(i=0;i<V-1;i++)
	printf("%d ",topo_order[i]);
     printf("%d",topo_order[i]);
}

