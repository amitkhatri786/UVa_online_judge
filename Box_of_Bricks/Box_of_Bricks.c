#include<stdio.h>

int main()
{

    int avg;
    int a[51]={0};
    int i,j,n;
    int t=1;
    int number_ways;

    while(1)
    {
	j = scanf("%d",&n);
	if(n!=0)
	{
	    avg = 0;
	    for(i=0;i<n;i++)
	    {
		j = scanf("%d",&a[i]);
		avg = avg + a[i];
	    }
	    avg = avg/n;
	    number_ways = 0;
	    for(i=0;i<n;i++)
	    {
		if( a[i] > avg )
		    number_ways =  number_ways + ( a[i] - avg );
	    }
	    printf("Set #%d\nThe minimum number of moves is %d.\n\n",t++,number_ways); 

	}
	else
	    break;
    }

    return(0);
}

