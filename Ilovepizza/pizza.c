#include<stdio.h>

int main()
{

	int t[6]={0};
	int i=0;
	int N;
	char c;
	int min;
	scanf("%d",&N);
	scanf("%c",&c);
	while(N--)
	{
		for(i=0;i<6;i++)
			t[i]=0;
		while((c=getchar())!='\n')
		{
			switch(c)
			{
				case 'M':
					t[0]++;
					break;
				case 'A':
					t[1]++;
					break;
				case 'R':
					t[2]++;
					break;
				case 'I':
					t[3]++;
					break;
				case 'G':
					t[4]++;
					break;
				case 'T':
					t[5]++;
					break;
				default:
					break;
			}
		}
		t[1]=t[1]/3;
		t[2]=t[2]/2;
		min = t[0];
		for(i=0;i<6;i++)
		{
			if(min > t[i])
				min=t[i];
		}
		printf("%d\n",min);

	}
	return(0);
}

