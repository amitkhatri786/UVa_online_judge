#include<stdio.h>

int main()
{

	int n;
	int i;
	int t,T;
        t=1;
	while(1)
	{
		scanf("%d",&n);
		if(n<0)
			break;

		while((n&(n-1))!=0)   /*check number is power of 2 or not */
			n++;

		/* printf("%d\n",n); */
		i=0;

		while((n=n>>1))
			i++;

		printf("Case %d: %d\n",t++,i);
	}

	return(0);
}

