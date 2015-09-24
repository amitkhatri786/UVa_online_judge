#include<stdio.h>


int main()
{

	int a[104][104]={0};
	char ch;
	int m,n;
	int i,j;
	int t=1;
	scanf("%d%d",&m,&n);
	while(1)
	{

		if(m==0 && n==0)
			break;

		printf("Field #%d:\n",t);
		t++;
		scanf("%c",&ch);
		for(i=1;i<=m;i++)        /*Take extra row and coloumn on both side m*n matrix become (m+1)*(n+1) */
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&ch);
				if(ch=='*')
					a[i][j] = 9999;
				else
					a[i][j] = 0;

			}
			scanf("%c",&ch);
		}


#if 0
		for(i=0;i<m+2;i++)
		{
			for(j=0;j<n+2;j++)
			{
				printf("%8d",a[i][j]);
			}
			printf("\n");
		}

		printf("\n\n\n");
#endif
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				if(a[i][j] >= 9999)
				{
					a[i][j-1]++;
					a[i][j+1]++;
					a[i-1][j-1]++;
					a[i-1][j]++;
					a[i-1][j+1]++;
					a[i+1][j-1]++;
					a[i+1][j]++;
					a[i+1][j+1]++;
				}
			}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]>=9999)
					printf("*");
				else
					printf("%d",a[i][j]);
			}
			printf("\n");
		}

		for(i=0;i<m+2;i++)
			for(j=0;j<n+2;j++)
				a[i][j]=0;
		scanf("%d%d",&m,&n);
		if(m!=0 && n!=0)
			printf("\n");
	}

	return(0);
}


