#include<stdio.h>

int main()
{

    int n;
    int oddbits[32]={0};
    int evenbits[32]={0};
    int i;
    int even=0,odd=0;
    int count=0;
    while(scanf("%d",&n))
    {
	if(n==0)
	    break;
	i=0;
	count=0;
	even=0;odd=0;
	while(i<32)
	{
	    if(n & 1<<i)
	    {
		count++;
		if(count%2!=0)
		    oddbits[i]=1;
		else
		    evenbits[i]=1;
	    }
	    i++;
	}
	for(i=0;i<32;i++)
	    even = even + (1<<i) * evenbits[i];
	for(i=0;i<32;i++)
	    odd = odd + (1<<i) * oddbits[i];
	printf("%d %d\n",odd,even);
	for(i=0;i<32;i++)
	{
	    evenbits[i]=0;
	    oddbits[i]=0;
	}
    }
    return(0);
}

