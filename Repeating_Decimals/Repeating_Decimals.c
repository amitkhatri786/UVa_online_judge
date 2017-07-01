#include<stdio.h>

#define MAX_DATA 100005

struct X
{
	int flag;
	int pos;
};

typedef struct X D;
D data[MAX_DATA]={0};
int div[10000]={0};

void process(int a,int b);

int main()
{
	int a,b;
	int t,T;
	int i;
	int c=1;
	setbuf(stdin,NULL);
	while(scanf("%d %d",&a,&b) != EOF)
	{
		/*if(c>1)
			printf("\n");*/
		process(a,b);
		/*c++;*/
			printf("\n");
		for(i=0;i<MAX_DATA;i++)
		{
			data[i].flag=0;
			data[i].pos=0;
			div[i%10000]=0;
		}
	}
	return(0);
}

void process(int a,int b)
{
	int x;
	int i;
	int rem;
	int print=0;
	int count=0;
	int a1=a,b1=b;
	printf("%d/%d = ",a1,b1);
#if 0
	if(a==0)
		printf("%d.0",x);
	else
		printf("%d.",x);
#endif
	printf("%d.",a/b);
	rem=a%b;
	while(rem!=0 && data[rem].flag!=1)
	{
		data[rem].flag = 1;
		data[rem].pos = count;
		rem = rem*10;
		div[count] = rem/b;
		rem=rem%b;
		count++;
	}
	if(rem==0)
	{
		for(i=0;i<count;i++)
			printf("%d",div[i]);
		printf("(0)");
		printf("\n   %d = number of digits in repeating cycle",1);
	}
	else
	{
		for(i=0;i<data[rem].pos;i++)
		{
			print++;
			printf("%d",div[i]);
		}
		printf("(");
		for(i=data[rem].pos;i<count;i++)
		{
			printf("%d",div[i]);
			print++;
			if(print == 50)
			{
				printf("...");
				break;
			}
		}
		printf(")");
		printf("\n   %d = number of digits in repeating cycle",count-data[rem].pos);
#if 0
		for(i=0;i<count;i++)
			printf("%d ",div[i]);
		printf("\nflag = %d pos = %d\n",data[rem].flag,data[rem].pos);
#endif
	}
	printf("\n");
}
