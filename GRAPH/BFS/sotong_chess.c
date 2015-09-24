#include<stdio.h>

#define MAX_SIZE 101

int bfs(int start_x, int start_y,int end_x,int end_y, int N,int M);

struct queue{
    int x;
    int y;
};
typedef struct queue Q;

int path[8][2]={
    {-2,1},
    {2,-1},
    {-1,2},
    {1,-2},
    {1,2},
    {-1,-2},
    {2,1},
    {-2,-1}
};



int main()
{

    int i,j,k;
    int N,M;
    int ans;
    int r,c;
    int T;
    int start_x,start_y,end_x,end_y;
    scanf("%d",&T);
    while(T--)
    {
	scanf("%d%d",&N,&M);
	scanf("%d%d%d%d",&start_x,&start_y,&end_x,&end_y);
	ans = bfs(start_x-1,start_y-1,end_x-1,end_y-1,N,M);
	//printf("Shortest path is %d \n",distace[end_x-1][end_y-1]);
	printf("Shortest path is %d \n",ans);
    }
    return(0);
}

int bfs(int start_x, int start_y,int end_x,int end_y, int N,int M)
{
    Q queue[MAX_SIZE*MAX_SIZE]={0};
    int visited[MAX_SIZE][MAX_SIZE]={0};
    int distace[MAX_SIZE][MAX_SIZE]={0};
    int front,rear; 
    int v_x,v_y;
    int i;
    int t;
    int temp_x,temp_y;
    front = -1;
    rear = -1;
    visited[start_x][start_y] = 1;

    front = 0;
    rear = 0;
    queue[rear].x = start_x;
    queue[rear].y = start_y;

    while(front <= rear )
    {
	v_x = queue[front].x;
	v_y = queue[front].y;
	front++;
	//	printf("%d %d,",v_x+1,v_y+1);

	if(v_x==end_x && v_y==end_y)
	    return(distace[end_x][end_y]);

	visited[v_x][v_y] = 1;
	for(i=0;i<8;i++)
	{
	    temp_x = path[i][0];
	    temp_y = path[i][1];
	    if(isvalid_location(v_x+temp_x,v_y+temp_y,N,M) && visited[v_x+temp_x][v_y+temp_y] == 0)
	    {
		//	printf("temp_x = %d, temp_y = %d  >>>",temp_x,temp_y);
		visited[v_x+temp_x][v_y+temp_y] = 1;
		distace[v_x+temp_x][v_y+temp_y] = distace[v_x][v_y] + 1;
		t = ++rear;
		queue[t].x = v_x+temp_x;
		queue[t].y = v_y+temp_y;
	    }
	}
#if 0
	if(v_x-2>=0  && v_y+1<=M-1 && visited[v_x-2][v_y+1] == 0)
	{
	    visited[v_x-2][v_y+1] = 1;
	    distace[v_x-2][v_y+1] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x-2;
	    queue[t].y = v_y+1;
	}	
	if(v_x+2<=N-1  && v_y-1>=0 && visited[v_x+2][v_y-1] == 0)
	{
	    visited[v_x+2][v_y-1] = 1;
	    distace[v_x+2][v_y-1] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x+2;
	    queue[t].y = v_y-1;
	}
	if(v_x-1 >=0 && v_y+2 <=M-1 && visited[v_x-1][v_y+2] == 0)
	{
	    visited[v_x-1][v_y+2] = 1;
	    distace[v_x-1][v_y+2] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x - 1;
	    queue[t].y = v_y + 2;
	}	
	if(v_x+1 <=N-1 && v_y-2 >=0 && visited[v_x+1][v_y-2] == 0)
	{
	    visited[v_x+1][v_y-2] = 1;
	    distace[v_x+1][v_y-2] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x + 1;
	    queue[t].y = v_y - 2;
	}
	if(v_x+1 <=N-1 && v_y+2 <= M-1 && visited[v_x+1][v_y+2] == 0)
	{
	    visited[v_x+1][v_y+2] = 1;
	    distace[v_x+1][v_y+2] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x + 1;
	    queue[t].y = v_y + 2;
	}	
	if(v_x-1 >=0 && v_y-2 >= 0 && visited[v_x-1][v_y-2] == 0)
	{
	    visited[v_x-1][v_y-2] = 1;
	    distace[v_x-1][v_y-2] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x - 1;
	    queue[t].y = v_y - 2;
	}	
	if(v_x+2 <=N-1 && v_y+1 <= M-1 && visited[v_x+2][v_y+1] == 0)
	{
	    visited[v_x+2][v_y+1] = 1;
	    distace[v_x+2][v_y+1] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x + 2;
	    queue[t].y = v_y + 1;
	}	
	if(v_x-2 >=0 && v_y-1 >= 0 && visited[v_x-2][v_y-1] == 0)
	{
	    visited[v_x-2][v_y-1] = 1;
	    distace[v_x-2][v_y-1] = distace[v_x][v_y]+1;
	    t = ++rear;
	    queue[t].x = v_x - 2;
	    queue[t].y = v_y - 1;
	}	
#endif

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

int isvalid_location(int x,int y,int N,int M)
{

    if(x>=0 && y>=0 && x<=N-1 && y<= M-1)
	return(1);
    else
	return(0);

}
