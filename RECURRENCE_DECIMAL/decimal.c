#include<stdio.h>

#define MAX_DATA 100005

struct X
{
	int flag;
	int pos;
};

typedef struct X D;
D data[MAX_DATA]={0};
int rec[10000]={0};

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
			rec[i%10000]=0;
		}
	}
	return(0);
}

void process(int a,int b)
{
	int x;
	int i;
	int isrec=0;
	int count=0;
	x = a/b;
	a = a%b;
	if(a==0)
		printf("%d.0",x);
	else
		printf("%d.",x);
	while(a%b!=0)
	{
		a = a*10;
		rec[count] = a/b;
		count++;
		if(data[a%b].flag == 1)
		{
			isrec=1;
			break;
		}
		data[a%b].flag = 1;
		data[a%b].pos  = count;
		a = a%b;
	}
	if(isrec==0)
	{
		for(i=0;i<count;i++)
			printf("%d",rec[i]);
	}
	else
	{
		if(b%10==0)
			count++;
		for(i=0;i<data[a%b].pos-1;i++)
			printf("%d",rec[i]);
		printf("(");
		for(;i<count-1;i++)
			printf("%d",rec[i]);
		printf(")");
	}
	printf("\n");
}
