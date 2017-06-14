#include<stdio.h>
#include<math.h>

int main()
{

	double pi = 2*acos(0.0);
	int n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%.*f\n",n,pi);


	}
	return(0);
}

