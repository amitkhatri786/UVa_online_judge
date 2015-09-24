#include<stdio.h>

int main()
{

	int T,t;
	char ch=0;
	int count=0;
        scanf("%d",&T);
        scanf("%c",&ch);
        count = 0;
	for(t=1;t<=T;t++)
	{
               count = 0;
		while((ch=getchar())!='\n')
		{
			switch(ch)
			{

				case 'a':
				case 'd':
				case 'g':
				case 'j':
				case 'm':
				case 'p':
				case 't':
				case 'w':
				case ' ':
					count = count + 1;
					break;
				case 'b':    
				case 'e':    
				case 'h':    
				case 'k':    
				case 'n':    
				case 'q':    
				case 'u':    
				case 'x':    
					count= count + 2;
					break;
				case 'c':    
				case 'f':    
				case 'i':    
				case 'l':    
				case 'o':    
				case 'r':    
				case 'v':    
				case 'y':    
					count = count + 3;
					break;

				case 's':    
				case 'z':  
					count = count + 4;
					break;
			}
		}

		printf("Case #%d: %d\n",t,count);
                count = 0;
	}
	return(0);
}

