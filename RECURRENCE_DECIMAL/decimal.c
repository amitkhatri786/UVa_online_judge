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
	setbuf(stdin,NULL);
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d",&a,&b);
		process(a,b);
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
	int count=0;
	x = a/b;
	a = a%b;
	if(a==0)
		printf("%d.0",x);
	else
		printf("%d.",x);
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
	}
	else
	{
		for(i=0;i<data[rem].pos;i++)
			printf("%d",div[i]);
		printf("(");
		for(i=data[rem].pos;i<count;i++)
			printf("%d",div[i]);
		printf(")");
#if 0
		for(i=0;i<count;i++)
			printf("%d ",div[i]);
		printf("\nflag = %d pos = %d\n",data[rem].flag,data[rem].pos);
#endif
	}
	printf("\n");
}
