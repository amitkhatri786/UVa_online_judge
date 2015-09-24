#include<stdio.h>

int main()
{

	int n;
	int t,T;
	int i;
	t=1;
	while(1)
	{
		i=0;
		scanf("%d",&n);
		if(n<0)
			break;
		n--;
		n |= n >> 1;
		n |= n >> 2;
		n |= n >> 4;
		n |= n >> 8;
		n |= n >> 16;
		n++;
		while((n=n>>1))
			i++;

		printf("Case %d: %d\n",t++,i);

	}

	return(0);
}

