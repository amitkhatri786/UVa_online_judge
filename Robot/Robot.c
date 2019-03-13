#include<stdio.h>

struct point{
	int row;
	int col;
};

enum d{
	NORTH=0,
	EAST,
	SOUTH,
	WEST,
};

struct q{
	int row;
	int col;
	int dir;
	int time;
};
typedef struct q Q;
Q queue[10001];

int mat[50][50];
int N,M;
enum d init_dir;
int visited[50][50][4];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int is_valid(int row,int col)
{

	if(row <= 0 || row >N || col <= 0 || col > M)
		return(0);
	if(mat[row-1][col-1] == 1)
		return(0);
	if(mat[row-1][col] == 1)
		return(0);
	if(mat[row][col - 1] == 1)
		return(0);
	if(mat[row][col] == 1)
		return(0);

	return(1);
}

void bfs(struct point start,struct point end)
{
	int i;
	int front,rear;
	int t_r,t_c;
	Q temp;
	front = 0;
	rear = 0;
	queue[rear].row = start.row;
	queue[rear].col = start.col;
	queue[rear].time = 0;
	queue[rear].dir = init_dir;
	visited[start.row][start.col][init_dir] = 1;
	rear++;
	while(front<rear) {
		temp = queue[front];
		front++;
		if(temp.row == end.row && temp.col == end.col) {
				printf("%d\n",temp.time);
				return;
		}

		if(visited[temp.row][temp.col][(temp.dir+1)%4] == 0) {
			queue[rear].row = temp.row;
			queue[rear].col = temp.col;
			queue[rear].time = temp.time+1;
			queue[rear].dir = (temp.dir+1)%4;
			visited[temp.row][temp.col][(temp.dir+1)%4] = 1;
			rear++;
		}
		if(visited[temp.row][temp.col][(temp.dir+3)%4] == 0) {
			queue[rear].row = temp.row;
			queue[rear].col = temp.col;
			queue[rear].time = temp.time+1;
			queue[rear].dir = (temp.dir+3)%4;
			visited[temp.row][temp.col][(temp.dir+3)%4] = 1;
			rear++;
		}

		for(i=1;i<=3;i++) {
			t_r = temp.row + i * dir[temp.dir][0];
			t_c = temp.col + i * dir[temp.dir][1];
			if(is_valid(t_r,t_c)) {
				if(visited[t_r][t_c][temp.dir] == 0) {
					queue[rear].row = t_r;
					queue[rear].col = t_c;
					queue[rear].time = temp.time+1;
					queue[rear].dir = temp.dir;
					visited[t_r][t_c][temp.dir] = 1;
					rear++;
				}	
			}
			else
				break;	
		}
	}
	printf("-1\n");
}

int main()
{
	struct point start,end;
	char x[15];
	int i,j,k;
	while(1) {
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)
			break;

		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				for(k=0;k<4;k++)
					visited[i][j][k] = 0;

		scanf("%d %d %d %d ",&start.row,&start.col,&end.row,&end.col);
		scanf("%s",x);
		if(x[0] == 'n')
			init_dir = NORTH;
		if(x[0] == 's')
			init_dir = SOUTH;
		if(x[0] == 'e')
			init_dir = EAST;
		if(x[0] == 'w')
			init_dir = WEST;
		bfs(start,end);
	}
	return(0);
}
