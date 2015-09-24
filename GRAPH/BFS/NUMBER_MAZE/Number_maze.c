#include<stdio.h>

#define MAX_SIZE 1001

int bfs(int mat[][MAX_SIZE],int start_x, int start_y,int end_x,int end_y, int N,int M);
int is_empty(int visited[][MAX_SIZE],int N,int M);
void min_ditance_queue(int distace[][MAX_SIZE],int visited[][MAX_SIZE], int N,int M,int *v_x,int *v_y);

int path[4][2]={
    {-1,0},
    {1,0},
    {0,-1},
    {0,1},
};


int mat[MAX_SIZE][MAX_SIZE]={0};

int main()
{

    int i,j,k;
    int N,M;
    int l,m;
    int ans;
    int r,c;
    int T;
    int num_bomb_row;
    int number_of_bomb;
    int start_x,start_y,end_x,end_y;
    l = scanf("%d",&T);
    while(T--)
    {
	l = scanf("%d",&N);
	l = scanf("%d",&M);
	for(i=0;i<N;i++)
	    for(j=0;j<M;j++)
		l = scanf("%d",&mat[i][j]);
#if 0
	for(l=0;l<N;l++)
	{
	    for(m=0;m<M;m++)
		printf("%3d ",mat[l][m]);
	    printf("\n");
	}
#endif

	ans = bfs(mat,0,0,N-1,M-1,N,M);
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
    int v_x,v_y;
    int i,j;
    int temp_x,temp_y;

    for(i=0;i<N;i++)
	for(j=0;j<M;j++)
	    distace[i][j]=9999999;

    distace[start_x][start_y]=mat[start_x][start_y];
    while(is_empty(visited,N,M))
    {
	min_ditance_queue(distace,visited,N,M,&v_x,&v_y);
	/*printf("%d %d,",v_x,v_y);  */
	visited[v_x][v_y] = 1;
	for(i=0;i<4;i++)
	{
	    temp_x = path[i][0];
	    temp_y = path[i][1];
	    if(isvalid_location(v_x+temp_x,v_y+temp_y,N,M) && visited[v_x+temp_x][v_y+temp_y] == 0 \
		    /*&& mat[v_x+temp_x][v_y+temp_y] !=0 */ \
		    && (distace[v_x+temp_x][v_y+temp_y] > (distace[v_x][v_y] + mat[v_x+temp_x][v_y+temp_y])))
	    {
		/*	printf("temp_x = %d, temp_y = %d  >>>",temp_x,temp_y);*/
		distace[v_x+temp_x][v_y+temp_y] = distace[v_x][v_y] + mat[v_x+temp_x][v_y+temp_y];
	    }
	}
    }
#if 0
    printf("\n");
    for(i=0;i<N;i++)
    {
	for(j=0;j<M;j++)
	    printf("%5d  ",distace[i][j]);
	printf("\n");
    }
#endif
    return(distace[end_x][end_y]);
}

int is_empty(int visited[][MAX_SIZE],int N,int M)
{

    int i,j;
    int flag = 1;
    for(i=0;i<N;i++)
	for(j=0;j<M;j++)
	    if(visited[i][j] == 0)
	    { 
		flag=0;
		goto out;
	    }
out:
    if(flag==1)
	return(0);
    else
	return(1);
}

void min_ditance_queue(int distace[][MAX_SIZE],int visited[][MAX_SIZE], int N,int M,int *v_x,int *v_y)
{
    int min=9999999;
    int i,j;
    for(i=0;i<N;i++)
    {
	for(j=0;j<M;j++)
	{
	    if(min > distace[i][j] && visited[i][j] != 1)
	    {
		min = distace[i][j];
		*v_x = i;
		*v_y = j;
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
