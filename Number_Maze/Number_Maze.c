#include<stdio.h>

int graph[1001][1001][4]={0};
void create_graph(int mat[][1001],int row,int col);
int opt[4][2]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int main()
{

    int mat[1001][1001]={0};
    int i,j,k;
    int T;
    int row,col;

    scanf("%d",&T);
    while(T--)
    {
	scanf("%d%d",&row,&col);
	for(i=0;i<row;i++)
	    for(j=0;j<col;j++)
		scanf("%d",&mat[i][j]);
    }

    for(i=0;i<row;i++)
    {
	for(j=0;j<col;j++)
	    printf("  %d",mat[i][j]);
	printf("\n");
    }
    create_graph(mat,row,col);
   for(i=0;i<row;i++)
    {
	for(j=0;j<col;j++)
	{
	    for(k=0;k<4;k++)
	    {
		printf(" %d",graph[i][j][k]);
	    }
	printf("  ");
	}
	printf("\n");
    }
    return(0);

}

void create_graph(int mat[][1001],int row,int col)
{
    int i,j;
    int x,y,k;
    for(i=0;i<row;i++)
    {
	for(j=0;j<col;j++)
	{
	    //if(i==0 || j == 0 || i == row-1 || j== col-1)
	    //printf("%d,%d ",i,j);
	    for(k=0;k<4;k++)
	    {
		x = i + opt[k][0];
		y = j + opt[k][1];
		if(x<0 || y<0 || x == row || y== col)
		    continue;
		printf("%d %d ",x,y);
		graph[x][y][k] = 1;
		graph[y][x][k] = 1;

	    }

	}
    }

		printf("\n");

}

