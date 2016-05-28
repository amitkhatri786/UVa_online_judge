#include<stdio.h>
#include<string.h>

int main()
{
    unsigned long long int ways[11][30002]={0};
    long long int coins[12]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    int S;
    long long input=0;
    long long input1=0;
    int i,j;

    for(i=0;i<=30000;i++)
	ways[0][i] = 1;
    for(i=0;i<11;i++)
	ways[i][0] = 1;
    for(i=1;i<11;i++)
    {
	for(j=1;j<=30000;j++)
	{
	    if(j<coins[i])
		ways[i][j] = ways[i-1][j];
	    else
		ways[i][j] = ways[i][j - coins[i]] + ways[i-1][j];
	}
    }
    while((scanf("%lld.%lld",&input,&input1)<=2))
    {

        if(input == 0 && input1 == 0)
		return(0);	
	S = input*100 + input1;
	printf("%3lld.%.2lld%17lld\n",input,input1,ways[10][S]);

    }
    return(0);
}

