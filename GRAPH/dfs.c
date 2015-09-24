#include<stdio.h>

void bfs(int mat[][15],int start,int V);
void bfs_re(int mat[][15], int start, int V);
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
		c = 0;
		for(j=0;j<V;j++)
		{
			printf("%d ",mat[i][j]);
			if (mat[i][j])
				c++;
		}
		printf("\n");
	}
#if 0
	bfs(mat,0,V);
#else
	bfs_re (mat, 0, V);
#endif
	printf("\n");
	return(0);
}

int visited[15]={0};
void bfs_re(int mat[][15], int start, int V)
{
	int i;
	printf ("%d ---->", start+1);
	if (visited[start])
		return;
	visited[start] = 1;
	for (i=0;i< V;i++)
		if (mat[start][i] && !visited[i])
			bfs_re(mat, i, V);
	return;
}

void bfs(int mat[][15], int start, int V)
{
	int queue[100]={0};
	int visited[15]={0};
	int front,rear; 
	int v;
	int i;
	front = -1;
	rear = -1;
	visited[start] = 1;

	front = 0;
	rear = 0;
	queue[rear] = start;

	while(front <= rear )
	{
		//Pop from the front 
		v = queue[front];
		front++;
		printf ("%d --->  ",v+1);
		visited[v]=1;
		for(i=0;i<V;i++)
		{
			if(mat[v][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				queue[++rear] = i;
			}
		}  
	}
}

