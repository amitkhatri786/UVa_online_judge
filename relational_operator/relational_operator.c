#include<stdio.h>

int main()
{

	int t,T;
	int x,y;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d",&x,&y);
		if(x<y)
			printf("<\n");
		if(x>y)
			printf(">\n");
		if(x==y)
			printf("=\n");
	}
	return(0);
}



