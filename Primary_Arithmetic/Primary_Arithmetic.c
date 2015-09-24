#include<string.h>
#include<stdio.h>

int main()
{

	unsigned int x,y;
	int carry=0;
	int count=0;
	int i,j;
	while(1)
	{
		carry = 0;
		count =0 ;
		scanf("%u%u",&x,&y);
		if(x==0 && y ==0)
			break;


		while ( x !=0 || y !=0 )
		{

				carry = (x%10 + y%10 + carry)/10;
			if(carry)
				count++; 
			x = x/10;
			y = y/10;

		}
#if 0
		while ( x != 0 && y != 0 )
		{
			if(x%10 + y%10 + carry  >9)
			{
				count++;
				carry = (x%10 + y%10 + carry) / 10; 
			}
			else 
				carry = 0;

			x= x/10;
			y= y/10;

		}
		while(x !=0 )
		{
			if(x%10+carry  >9) 
			{	
				count++;
				carry = (x%10 + carry) / 10;
			}
			else
				carry =0;
			x = x/10;

		}

		while(y !=0 )
		{
			if(y%10 + carry  >9)
			{			
				count++;
				carry = (y%10 + carry) / 10; 
			}
			else
				carry = 0;

			y = y/10;
		}

#endif
		if(count == 0)
			printf("No carry operation.\n");
		else
		{
			if(count == 1)
				printf("%d carry operation.\n",count);
			else
				printf("%d carry operations.\n",count);

		}
	}
	return(0);
}





