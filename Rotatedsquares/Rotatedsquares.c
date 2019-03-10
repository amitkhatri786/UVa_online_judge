#include<stdio.h>

char big_mat[1000][1000];
char small_mat[4][1000][1000];
char temp[1000][1000];
enum d{
	ZERO_DEGREE=0,
	NINTY_DEGREE,
	ONE_EIGHTY_DEGREE,
	TWO_SEVENTY_DEGREE,
};

int N,M;
int result[4] = {0};

void analyse(int start_x,int start_y)
{

	int i,j;
	int deg;
	int count;
	int found=1;
	for(deg=0;deg<4;deg++) {
		count=0;
		found = 1;
		for(i=0;i<M;i++) {
			for(j=0;j<M;j++) {
				if(temp[i][j] == small_mat[deg][i][j])
					count++;
				else {
					found = 0;
					break;
				}
			}
			if(!found)
				break;
		}
		if(count == M*M)
			result[deg]++;
	}
}


void solve()
{
	int i,j;
	int m,n;
	int start_x,start_y;
	for(i=0;i<=N-M;i++) {
		for(j=0;j<=N-M;j++) {
			start_x = i;
			start_y = j;
			for(m=0;m<M;m++) {
				for(n=0;n<M;n++) {
					temp[m][n] = big_mat[start_x + m][start_y + n];
				}
			}
			analyse(start_x,start_y);
		}

	}


}

int main()
{
	int i,j;
	int m,n;
	while(1) {
		scanf("%d %d",&N,&M);
		for(i=0;i<4;i++)
			result[i] = 0;
		if(!N && !M )
			break;
		for(i=0;i<N;i++)
			scanf("%s",big_mat[i]);
		for(i=0;i<M;i++)
			scanf("%s",small_mat[ZERO_DEGREE][i]);

		n = 0;
		for(i=0;i<M;i++) {
			m = M-1;
			for(j=0;j<M;j++) {
				small_mat[NINTY_DEGREE][i][j] = small_mat[ZERO_DEGREE][m--][n];
			}
			n++;
		}
		n = 0;
		for(i=0;i<M;i++) {
			m = M-1;
			for(j=0;j<M;j++) {
				small_mat[ONE_EIGHTY_DEGREE][i][j] = small_mat[NINTY_DEGREE][m--][n];
			}
			n++;
		}
		n = 0;
		for(i=0;i<M;i++) {
			m = M-1;
			for(j=0;j<M;j++) {
				small_mat[TWO_SEVENTY_DEGREE][i][j] = small_mat[ONE_EIGHTY_DEGREE][m--][n];
			}
			n++;
		}
		solve();
		printf("%d %d %d %d\n",result[0],result[1],result[2],result[3]);
	}
	return(0);
}
