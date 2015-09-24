#include<stdio.h>

int main()
{
    int x,t;
    int a[10];
    int j,i=0;
    scanf("%d",&x);
    while(x!=0)
    {
	t  = x % -2;
	if(t<0)
	    t = -t;
	a[i++] = t;
	x = x / -2;
    }
    for(j=i-1;j>=0;j--)
	printf("%d",a[j]);

    printf("\n");
    return(0);

}

