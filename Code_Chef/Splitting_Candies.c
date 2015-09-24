#include<stdio.h>

int main()
{
	int T;
	long long int N;
	long long int K;
	scanf("%d",&T);
	while(T--)
	{

		scanf("%lld%lld",&N,&K);

		if(K==0  && N==0)
			printf("0 0\n");
		else if(K==0 &&  N >0)

			printf("0 %lld\n",N);
		else
			printf("%lld %lld\n",N/K,N%K);
	}
	return(0);
}

