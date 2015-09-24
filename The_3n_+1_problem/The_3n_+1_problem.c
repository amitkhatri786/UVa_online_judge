#include<stdio.h>

void swap(int *,int *);
int a[1000001]={0};

int main()
{

    int m,n;
    int i,j;
    long int num;
    int max_cycle=0,cycle;
    while((scanf("%d%d",&m,&n))!=EOF)
    {
	printf("%d %d",m,n);
	if(m>n)
	    swap(&m,&n);

	a[1] = 1;
	for(i=2;i<=n;i++)
	{
	    cycle = 0;
	    num = i;
	    while(num != 1 && num >= i)
	    {
		if(num %2 ==0 )
		    num = num >>1; 
		else
		    num = 3 * num +1;
		cycle = cycle + 1;
	    }
	    a[i] = cycle + a[num];

	}
	for(i=m;i<=n;i++)
	    if(max_cycle < a[i])
		max_cycle = a[i];

	printf(" %d\n",max_cycle);
	max_cycle =0;
        for(i=0;i<=1000001;i++)
         a[i]=0;
    }
    return(0);

}

void swap(int *m,int *n)
{

    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}


