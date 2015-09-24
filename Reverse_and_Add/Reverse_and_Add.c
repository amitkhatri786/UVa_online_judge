#include<stdio.h>

unsigned int reverse(unsigned int a)
{
	unsigned int sum = 0;
	while ( a != 0)
	{
		sum = sum*10 + a%10;
		a = a/10;
	}
	return(sum);
}

int main()
{
	unsigned int x;
	unsigned int sum =0;
	int t,T,i;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		sum = 0;
		i=0;
		scanf("%u",&x);
		while( x != reverse(x) )
		{
			i++;
			/*		printf("Reverse sum is  %u\n",reverse(x)); */
			sum = x + reverse(x);
			x = sum;

		}

		printf("%d %u\n",i,sum);
	}
	return(0);
}
