#include<stdio.h>

void fun(int a[],int index,int r);

int main()
{
    int a[10]={0};

    fun(a,0,3);

    return(0);
}

void fun(int a[],int index,int r)
{

    int i,j;
    if(index==r)
    {
	for(j=0;j<r;j++)
	    printf("%d",a[j]);
	printf("\n");
	return;
    }

    for(i=1;i<=r;i++)
    {
	a[index] = i;
	fun(a,index+1,r);
    }
    return;
}
