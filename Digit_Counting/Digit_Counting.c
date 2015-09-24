#include<stdio.h>

int a[10]={0};

int main()
{
    int i,j,N;
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {

	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
	    j = i;
	    while(j>0)
	    {
		a[j%10] = a[j%10] + 1;
		j = j/10;
	    }
	}

	for(i=0;i<9;i++)
	{
	    printf("%d ",a[i]);
	    a[i] = 0;
	}

	printf("%d\n",a[9]);
        a[9]=0;
    }
    return(0);
}


