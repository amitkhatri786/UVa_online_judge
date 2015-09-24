#include<stdio.h>

int main()
{
	int x,y;
	int t,T;
	int new_x,new_y;
	int new_orig_x,new_orig_y; 
	while(1)
	{
		scanf("%d",&T);
		if(T==0)
			break;

		scanf("%d%d",&new_orig_x,&new_orig_y);
		for(t=1;t<=T;t++)
		{

			scanf("%d%d",&x,&y);
			new_x = x - new_orig_x;
			new_y = y - new_orig_y;
			if(new_x== 0 || new_y == 0)
				printf("divisa\n");

			if(new_x>0 && new_y>0)
				printf("NE\n");

			if(new_x>0 && new_y<0)
				printf("SE\n");
			if(new_x <0 && new_y>0)
				printf("NO\n");
			if(new_x<0 && new_y<0)
				printf("SO\n");
		}
	}
	return(0);
}  

