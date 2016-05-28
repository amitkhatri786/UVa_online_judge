#include<stdio.h>

int main()
{

    int mul,temp;
    int i,j;
    int carry=0;
    int a[3000]={0};
    int n;
    int len;
    int T,t;
    while(1)
    {

	temp = scanf("%d",&n);
	if(temp!=1)
	    break;
	printf("%d!\n",n);
	len=0;
	a[0] = 1;
	for(j=2;j<=n;j++)
	{
	    carry=0;
	    mul=j;
	    i=0;
	    while(i<=len)
	    {

		temp = (a[i]*mul+carry)%10;
		carry = (a[i]*mul+carry)/10;
		a[i] = temp;
		i++;
	    }
	    while(carry > 0)
	    {
		temp = (a[i]*mul+carry)%10;
		carry = (a[i]*mul+carry)/10;
		a[i] = temp;
		i++;
	    }

	    len = i-1;

	}
	for(i=len;i>=0;i--)
	    printf("%d",a[i]);
	printf("\n");
	for(i=0;i<3000;i++)
	    a[i] = 0;

    }
    return(0);
}


