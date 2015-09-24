#include<stdio.h>

int main()
{
    int data[3001]= {0};
    int diff[3001]= {0};
    int i=0;
    int N;
    int t;
    while(1)
    {
	t = scanf("%d",&N);
	if(N==0)
	    break;
	t =   scanf("%d",&data[0]);
	for(i=0; i<N-1;i++)
	{
	    t =   scanf("%d",&data[i+1]);
	    /*	for(i=0; i<N ;i++)
	    //	    printf("%d  ",data[i]);
	    printf("\n");
	     */
	    diff[abs(data[i] - data[i+1])] = 1;
	}
	/*for(i=1; i<N;i++)
	    printf("%d  ",diff[i]);*/
	for(i=1; i<N ;i++)
	{
	    if(diff[i]==0)
		break;
	    /*    printf("%d  ",diff[i]); */
	}
	if(i==N)
	    printf("Jolly\n");
	else
	    printf("Not jolly\n");
	for(i=0;i<N;i++)
	    diff[i]=0;
	N=0;
    }


    return(0);

}

