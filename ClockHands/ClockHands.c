#include<stdio.h>

int main()
{
	int h,m;
	double angle;
	while(1)
	{
		scanf("%d:%d",&h,&m);
		if(h==0 && m==0)
			break;
		angle = ((float) ((60*h - 11*m)))/2;
		if(angle < 0.0)
			angle = -angle; 
		if(angle > (float)(180.0) )
			printf("%.3f\n",360-angle);
		else
			printf("%.3f\n",angle);
	}
	return (0);
}

