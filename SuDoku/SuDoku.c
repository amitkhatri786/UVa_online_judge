#include<stdio.h>

struct data
{
	int row;
	int col;
};

typedef struct data D;

D d[90] = {0};
int zero_count = 0;

int main()
{
	int i,j;
	int n;
	int x;
	int ans;
	int t;
	int last;
	int first=0;
	int sudoku[9][9]={0};
	while((last = scanf("%d",&n)))
	{
		if(last == -1)
			break;
		if(first)
			printf("\n");
		first=1;
		for(i=0;i<n*n;i++)
		{
			for(j=0;j<n*n;j++)
			{
				x = scanf("%d",&t);
				if(t!=0)
					sudoku[i][j] = t;
				else
				{
					d[zero_count].row = i;
					d[zero_count].col = j;
					zero_count++;
				}
			}
		}
#ifdef DEBUG
		for(i=0;i<n*n;i++)
		{
			for(j=0;j<n*n;j++)
				printf("%d ",sudoku[i][j]);
			printf("\n");
		}
#endif
		ans = solve(sudoku,n,0);
		if(ans)
		{
			for(i=0;i<n*n;i++)
			{
				for(j=0;j<n*n;j++)
				{
					if(j!=0)
						printf(" ");
					printf("%d",sudoku[i][j]);
				}
				printf("\n");
			}
		}
		else
			printf("NO SOLUTION\n");
		zero_count = 0;
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				sudoku[i][j]=0;
	}
	return(0);
}

int solve(int sudoku[][9],int n,int k)
{
	int i;

	if(k >= zero_count)
		return 1;
	else
	{
		for(i=1;i<=n*n;i++)
			if(validity(sudoku,d[k].row,d[k].col,n,i))
			{
				sudoku[d[k].row][d[k].col] = i;

				if(!(solve(sudoku,n,k+1)))
					sudoku[d[k].row][d[k].col] = 0;
				else
					return 1;
			}

	}
	return 0;
}

int validity(int sudoku[][9],int row,int col,int n,int value)
{
	int i,j;
	int start_x,start_y;
	for(i=0;i<n*n;i++)
		if(sudoku[row][i] == value)
			return 0;

	for(i=0;i<n*n;i++)
		if(sudoku[i][col] == value)
			return 0;

	start_x = row - (row % n);
	start_y = col - (col % n);

	for(i=start_x;i<=(start_x+(n-1));i++)
		for(j=start_y;j<=(start_y +(n-1));j++)
			if(sudoku[i][j] == value)
				return 0;
	return(1);
}
