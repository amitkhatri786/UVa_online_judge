#include<stdio.h>
#include<string.h>

int main()
{
    char a[201]={0};
    char b[201]={0};
    char sum[201]={'0'};
    int T,len;
    int carry=0;
    int l1,l2,i,k;
    i = scanf("%d",&T);
    while(T--)
    {

	l1 = scanf("%s",a);
	l2 = scanf("%s",b);
	l1 = strlen(a);
	l2 = strlen(b);
	//for(i=x-1;i>=0;i--)
	printf("%s",a);

	printf("   ");
	//for(i=y-1;i>=0;i--)
	printf("%s",b);
	printf("\n");
	carry = 0;
	len = l1>l2?l1:l2;
	k=0;
	for(i=0;i<len;i++)
	    sum[i] = '0';
	for(i=l2-1;i>=0;i--)
	{
	    sum[k] = (((sum[k]-48) + (a[i]-48)+ (b[i]-48)) + carry);
	    carry = (a[i]-48) + (b[i]-48) + carry;
	    if(carry >= 10)
		carry =  1;
	    else
		carry = 0;
	    k++;
	}
	for(i=l1-l2-1;i>=0;i--)
	{
	    sum[k] = (((sum[k]-48) + (b[i]-48)) + carry);
	    carry =  (b[i]-48) + carry;
	    if(carry >= 10)
		carry =  1;
	    else
		carry = 0;
	    k++;
	}
	sum[k]='\0';
	//for(i=0;i<=k;i++)
	printf("%s\n",sum);

    }
    return(0);
}
