#include<stdio.h>

void bfs(int mat[][15],int start_x,int start_y,int V);

struct queue{
    int x;
    int y;
};

int count=0;

typedef struct queue Q;
int main()
{

    int mat[15][15]={0};
    int i,j,k;
    int V,E;
    int r,c;
    scanf("%d",&V);
#if 0
    for(i=0;i<E;i++)
    {
	scanf("%d%d",&r,&c);
	mat[r-1][c-1] =1;
	mat[c-1][r-1] =1;
    }
#endif
    for(i=0;i<V;i++)
    {
	for(j=0;j<V;j++)
	    printf("%d ",mat[i][j]);
	printf("\n");
    }
    bfs(mat,0,0,V);
    printf("\ncount is %d \n",count);
    return(0);
}

void bfs(int mat[][15], int start_x, int start_y, int V)
{
    Q queue[100]={0};
    int visited[15][15]={0};
    int front,rear; 
    int v_x,v_y;
    int i;
    int t;
    front = -1;
    rear = -1;
    visited[start_x][start_y] = 1;

    front = 0;
    rear = 0;
    queue[rear].x = start_x;
    queue[rear].y = start_y;
    //	front = front + 1;

    while(front <= rear )
    {
	v_x = queue[front].x;
	v_y = queue[front].y;
	front++;
	printf("%d %d,",v_x+1,v_y+1);
	count++;
	visited[v_x][v_y] = 1;

	if(v_x-2>=0  && v_y+1<=V-1 && visited[v_x-2][v_y+1] == 0)
	{
	    visited[v_x-2][v_y+1] = 1;
	    t = ++rear;
	    queue[t].x = v_x-2;
	    queue[t].y = v_y+1;
	}	
	if(v_x+2<=V-1  && v_y-1>=0 && visited[v_x+2][v_y-1] == 0)
	{
	    visited[v_x+2][v_y-1] = 1;
	    t = ++rear;
	    queue[t].x = v_x+2;
	    queue[t].y = v_y-1;
	}
	if(v_x-1 >=0 && v_y+2 <=V-1 && visited[v_x-1][v_y+2] == 0)
	{
	    visited[v_x-1][v_y+2] = 1;
	    t = ++rear;
	    queue[t].x = v_x - 1;
	    queue[t].y = v_y + 2;
	}	
	if(v_x+1 <=V-1 && v_y-2 >=0 && visited[v_x+1][v_y-2] == 0)
	{
	    visited[v_x+1][v_y-2] = 1;
	    t = ++rear;
	    queue[t].x = v_x + 1;
	    queue[t].y = v_y - 2;
	}	
	if(v_x+1 <=V-1 && v_y+2 <= V-1 && visited[v_x+1][v_y+2] == 0)
	{
	    visited[v_x+1][v_y+2] = 1;
	    t = ++rear;
	    queue[t].x = v_x + 1;
	    queue[t].y = v_y + 2;
	}	
	if(v_x-1 >=0 && v_y-2 >= 0 && visited[v_x-1][v_y-2] == 0)
	{
	    visited[v_x-1][v_y-2] = 1;
	    t = ++rear;
	    queue[t].x = v_x - 1;
	    queue[t].y = v_y - 2;
	}	
	if(v_x+2 <=V-1 && v_y+1 <= V-1 && visited[v_x+2][v_y+1] == 0)
	{
	    visited[v_x+2][v_y+1] = 1;
	    t = ++rear;
	    queue[t].x = v_x + 2;
	    queue[t].y = v_y + 1;
	}	
	if(v_x-2 >=0 && v_y-1 >= 0 && visited[v_x-2][v_y-1] == 0)
	{
	    visited[v_x-2][v_y-1] = 1;
	    t = ++rear;
	    queue[t].x = v_x - 2;
	    queue[t].y = v_y - 1;
	}	


#if 0
	for(i=0;i<V;i++)
	{
	    if(mat[v][i] == 1 && visited[i] == 0)
	    {
		visited[i] = 1;
		queue[++rear] = i;

	    }
	} 
#endif 
    }
}

