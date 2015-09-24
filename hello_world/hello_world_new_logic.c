#include<stdio.h>
#include<math.h>

int main()
{

	int n;
	int i;
	int t,T;
        int array[100]={0};
        t=1;
	while(1)
	{
		scanf("%d",&n);
		if(n<0)
			break;

		printf("Case %d: ",t++);
                printf("%.0f\n",ceil((double) log(n)/log(2)));

//		while((n&(n-1))!=0)   /*check number is power of 2 or not */
//			n++;

		/* printf("%d\n",n); */
//		i=0;

//		while((n=n>>1))
//			i++;
 // printf("%d\n",i);

	//	printf("Case %d: %d\n",t++,i);
	}

	return(0);
}

