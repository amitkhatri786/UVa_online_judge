#include <stdio.h>
#include <stdlib.h>

long int power[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int diffnumber(int x,int y);
int main()
{

    int array[100000]={0};
    int low,high,t;
    int i,n,x,CASE;
    i=0;
    CASE = 1;
    while(1)
    {
	t=scanf("%d",&n);
	if(n==0)
	    break;

	for(i=0;i<n;i++)
	{
	  t=  scanf("%d",&x);
	    array[i] = x;
	}     

	/*for(i=0;i<n;i++)
	  printf("%d\n",array[i]); */

	printf("Case %d:\n",CASE++);  
	for(i=0;i<n;i++)
	{
	    low=high=array[i];
	    while(array[i+1]==array[i]+1 && i<n-1) 
	    {
		high = array[i+1];
		i++;
	    }
	    /* printf("  low = %d high = %d\n",low,high);
	    //printf(" Range = %d\n ",diffnumber(low,high)); */
	    if(low == high )
		printf("0%d\n",low);
	    else
	    {
		if(x=diffnumber(low,high))
		    printf("0%d-%d\n",low,x);
	    }
	}
       printf("\n");
	for(i=0;i<n;i++)
	    array[i] = 0;
    }

    return(0);

}

int diffnumber(int x,int y)
{

    int i,l;
    int sum=0;
    i=0;
    while(y!=0)
    {
	l = x%10;

	if ( x == y)
	    break;

/*	if( y%10 != l) */
	    sum = sum + (y%10) * (power[i++]);
	y = y/10;
	x = x/10;

    }
    return(sum);

}


