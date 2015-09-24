#include<stdio.h>

int main()
{

    unsigned char ch;
    int cost[258]={0};
    int count[258]={0};
    int total=0;
    int val;
    int line;
    int T;
    int K;
    int i;
    int t;
    t = scanf("%d",&T);
    while(T--)
    {
	t = scanf("%d\n",&K);
	for(i=0;i<K;i++)
	{
	    t = scanf("%c%d\n",&ch,&val);
	    cost[ch] = val;
	}
	t = scanf("%d\n",&line);
	while(line)
	{
	    if((ch=getchar())!='\n')
		count[ch] = count[ch] +1;
	    else
		line--;
	}
	for(i=0;i<256;i++)
	    total = total + cost[i] * count[i];
	printf("%.2lf$\n",total/100.0);
	for(i=0;i<256;i++)
	{
	    cost[i]=0;
	    count[i]=0;
	}
	total=0;
    }
    return(0);
}
