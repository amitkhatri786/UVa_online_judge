#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *rev(char *);

int main()
{

    int mul,temp;
    int i,j;
    int carry=0;
    char a[3000]={0};
    int n;
    int len;
    int T,t;
    char ch;
    while(1)
    {

	temp = scanf("%d",&n);
	if(temp!=1)
	    break;
	printf("%d!\n",n);
	len=0;
	memset(a,48,3000);
	ch = 49;
	a[0] = ch;
	for(j=2;j<=n;j++)
	{
	    carry=0;
	    mul=j;
	    i=0;
	    while(i<=len)
	    {
		ch = a[i]-48;
		temp = (ch*mul+carry)%10;
		carry = (ch*mul+carry)/10;
		a[i] = 48 + (temp & 0x000000ff);
		i++;
	    }
	    while(carry > 0)
	    {
		ch = a[i]-48;
		temp = (ch*mul+carry)%10;
		carry = (ch*mul+carry)/10;
		a[i] = 48 + (temp & 0x000000ff);
		i++;
	    }

	    len = i-1;

	}
	a[len+1] = '\0';
	for(i=len;i>=0;i--)
	    printf("%c",a[i]);
	printf("\n");

    }
    return(0);
}

char *rev(char *ch)
{
    char *start,*end;
    char *temp;
    start = ch;
    end = ch + (strlen(ch)-1);
    while(start<end)
    {
	*start ^= *end;
	*end ^= *start;
	*start ^= *end;
	start++;
	end--;
    }

    return(ch);
}

