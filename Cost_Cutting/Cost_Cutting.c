#include<stdio.h>
#include<stdlib.h>


int max(int a,int b)
{
	return(((a+b)+abs(a-b))/2);
}

int min(int a,int b)
{
	return(((a+b)-abs(a-b))/2);
}

int main()
{
	int t,T;
	int x,y,z;

	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d",&x,&y,&z);
		printf("Case %d: ",t);
		/*	printf("max = %d\n",max(max(x,y),z));
			printf("min = %d\n",min(min(x,y),z)); */
		printf("%d\n",(x+y+z)-max(max(x,y),z)-min(min(x,y),z));

	}

	return(0);
}

