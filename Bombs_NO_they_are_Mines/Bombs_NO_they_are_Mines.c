#include<stdio.h>

#define MAX_SIZE 1002

int bfs(int mat[][MAX_SIZE],int start_x, int start_y,int end_x,int end_y, int N,int M);

struct queue{
    int x;
    int y;
};
typedef struct queue Q;

int path[4][2]={
    {-1,0},
    {1,0},
    {0,-1},
    {0,1},
};


int mat[MAX_SIZE][MAX_SIZE]={0};
Q queue[MAX_SIZE*MAX_SIZE]={0};

int main()
{

    int i,j,k;
    int N,M;
    int l,m;
    int ans;
    int r,c;
    int num_bomb_row;
    int number_of_bomb;
    int start_x,start_y,end_x,end_y;
    while((scanf("%d%d",&N,&M)==2) && N != 0 && M != 0)
    {
	l = scanf("%d",&num_bomb_row);
	for(i=0;i<num_bomb_row;i++)
	{
	    l = scanf("%d%d",&r,&number_of_bomb);
	    for(j=0;j<number_of_bomb;j++)
	    {
		l = scanf("%d",&c);
		mat[r][c]=1;
	    }

	}
	l = scanf("%d%d",&start_x,&start_y);
	l = scanf("%d%d",&end_x,&end_y);
#if 0
	for(l=0;l<N;l++)
	{
	    for(m=0;m<M;m++)
		printf("%3d ",mat[l][m]);
	    printf("\n");
	}
#endif

	ans = bfs(mat,start_x,start_y,end_x,end_y,N,M);
	/*printf("Shortest path is %d \n",distace[end_x-1][end_y-1]); */
	printf("%d\n",ans);
	for(l=0;l<N;l++)
	    for(m=0;m<M;m++)
		mat[l][m] = 0;
    }
    return(0);
}

int bfs(int mat[][MAX_SIZE],int start_x, int start_y,int end_x,int end_y, int N,int M)
{
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
	/*	printf("%d %d,",v_x,v_y); */

	if(v_x==end_x && v_y==end_y)
	    return(distace[end_x][end_y]);

	visited[v_x][v_y] = 1;
	for(i=0;i<4;i++)
	{
	    temp_x = path[i][0];
	    temp_y = path[i][1];
	    if(isvalid_location(v_x+temp_x,v_y+temp_y,N,M) && visited[v_x+temp_x][v_y+temp_y] == 0 && mat[v_x+temp_x][v_y+temp_y]==0)
	    {
		/*	printf("temp_x = %d, temp_y = %d  >>>",temp_x,temp_y);*/
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
