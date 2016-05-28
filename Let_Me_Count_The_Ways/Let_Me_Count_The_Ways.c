#include<stdio.h>

int main()
{
    long long int ways[5][30002]={0};
    long long int coins[5]={1,5,10,25,50};
    int S;
    int i,j;

    for(i=0;i<=30000;i++)
	ways[0][i] = 1;
    for(i=0;i<5;i++)
	ways[i][0] = 1;
    for(i=1;i<5;i++)
    {
	for(j=1;j<=30000;j++)
	{
	    if(j<coins[i])
		ways[i][j] = ways[i-1][j];
	    else
		ways[i][j] = ways[i][j - coins[i]] + ways[i-1][j];
	}
    }
    while((scanf("%d",&S)==1))
    {

	if(ways[4][S] == 1 || S==0)
	    printf("There is only 1 way to produce %d cents change.\n",S);
	else
	    printf("There are %lld ways to produce %d cents change.\n",ways[4][S],S);

    }
    return(0);
}

