#include<stdio.h>
#include<stdlib.h>


int cmp(const void *p1, const void *p2)
{
    return ( *(int*)p1 - *(int*)p2 );
}

int main()
{

    int n;
    int t;
    int i;
    int a[5001]={0};
    while(scanf("%d",&n))
    {
	if(n==0)
	    break;
	for(i=0;i<n;i++)
	    t = scanf("%d",&a[i]);
	printf("%d\n",huffman_code(a,n));
/*	for(i=0;i<n;i++)
	    a[i] = 0;     
*/
    }
    return(0);
}

int huffman_code(int *a,int n)
{
    int cost=0;
    int i;
    int step;
    int j;
    qsort(a,n,sizeof(int),cmp);
    for(step=1;step<=n-1;step++)
    {
	cost = cost + a[0] + a[1];
	a[0] = a[0] + a[1];
	for(j=1;j<n-step;j++)
	    a[j] = a[j+1];
	qsort(a,n-step,sizeof(int),cmp);
    }

    return(cost);
}
