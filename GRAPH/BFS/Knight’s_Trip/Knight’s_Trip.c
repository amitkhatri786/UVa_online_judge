#include<stdio.h>

#define MAX_SIZE 1000000

int bfs(int start_x, int start_y,int end_x,int end_y, int N,int M);

struct queue{
    int x;
    int y;
};
typedef struct queue Q;

Q queue[MAX_SIZE]={0};
int visited[MAX_SIZE][MAX_SIZE]={0};
int distace[MAX_SIZE][MAX_SIZE]={0};

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
    int ans;
    int r,c;
    int T;
    int start_x,start_y,end_x,end_y;
    while((scanf("%d%d",&end_x,&end_y)==2))
    {
	ans = bfs(0,0,end_x,end_y,MAX_SIZE,MAX_SIZE);
	printf("Shortest path is %d \n",ans);
	for(i=0;i<MAX_SIZE;i++)
	    for(j=0;j<MAX_SIZE;j++)
	    {
		visited[i][j]=0;
		distace[i][j]=0;
	    }	
    }
    return(0);
}

int bfs(int start_x, int start_y,int end_x,int end_y, int N,int M)
{
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
	if(v_x==end_x && v_y==end_y)
	    return(distace[end_x][end_y]);

	visited[v_x][v_y] = 1;
	for(i=0;i<8;i++)
	{
	    temp_x = path[i][0];
	    temp_y = path[i][1];
	    if(isvalid_location(v_x+temp_x,v_y+temp_y,N,M) && visited[v_x+temp_x][v_y+temp_y] == 0)
	    {
		visited[v_x+temp_x][v_y+temp_y] = 1;
		distace[v_x+temp_x][v_y+temp_y] = distace[v_x][v_y] + 1;
		t = ++rear;
		queue[t].x = v_x+temp_x;
		queue[t].y = v_y+temp_y;
	    }
	}
    }
}

int isvalid_location(int x,int y,int N,int M)
{

    if(x>=0 && y>=0 && x<=N-1 && y<= M-1)
	return(1);
    else
	return(0);

}
