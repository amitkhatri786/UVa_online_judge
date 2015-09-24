#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ver_line_upper_right(int ,int ,int ,char (*)[23][12]);
void ver_line_lower_right(int ,int ,int ,char (*)[23][12]);

void ver_line_upper_left(int ,int ,int ,char (*)[23][12]);
void ver_line_lower_left(int ,int ,int ,char (*)[23][12]);

void hor_line_upper(int ,int ,int ,char (*)[23][12]);
void hor_line_lower(int ,int ,int ,char (*)[23][12]);
void hor_line_middle(int ,int ,int ,char (*)[23][12]);

char a[10][23][12]={0};

int main()
{

    int x,y;
    int s;
    int len,total;
    int i,j,k;
    char num[10]={0};
    while(1)
    {
	i= scanf("%d",&s);
	i= scanf("%s",num);
	if(s == 0 && num[0] == '0')
	    break;
	x = 2*s + 3;
	y = s + 2;
	len = strlen(num);
	total = len * x * y;
#if 0
	a = (char ***) calloc (sizeof(char **),len);
	for(i=0;i<len;i++)
	{
	    a[i] = (char **) calloc (sizeof(char *),x);

	    for(j=0;j<x;j++)
		a[i][j] = (char *) calloc (sizeof(char),y);
	}
#endif

	for(i=0;i<len;i++)
	    for(j=0;j<x;j++)
		for(k=0;k<y;k++)
		    a[i][j][k] = ' ';

	for(k=0;k<len;k++)
	{
	    switch(num[k]-48)
	    {
		case 1:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }

		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }


		    break;

		case 2:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 3:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 4:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 5:
		    {
			int i,j;
			j=0;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 6:
		    {
			int i,j;
			j=0;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 7:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 8:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;

		case 9:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x/2;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    break;

		case 0:
		    {
			int i,j;
			j=y-1;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=1;i<x/2;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=0;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			j=y-1;
			for(i=x/2+1;i<x-1;i++)
			    a[k][i][j] = '|';
		    }
		    {
			int i,j;
			i=0;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }
		    {
			int i,j;
			i=x-1;
			for(j=1;j<y-1;j++)
			    a[k][i][j] = '-';
		    }

		    break;


	    }
	}
	for(j=0;j<x;j++)
	{
	    for(i=0;i<len;i++)
	    {
		for(k=0;k<y;k++)
		    printf("%c",a[i][j][k]);
		if(i<len-1)
		    printf(" ");
	    }
	    printf("\n");
	}
	printf("\n");
#if 0
	for(i=0;i<len;i++)
	{   
	    for(j=0;j<x;j++)
		free( a[i][j]);
	    free(a[i]); 
	}   
	free(a);
#endif
    }
    return(0);
}

#if 0
void  ver_line_upper_right (int  x,int y,int k,char (*a)[23][12])
{
    int i,j;
    j=y-1;
    for(i=1;i<x/2;i++)
	a[k][i][j] = '|';
}

void  ver_line_upper_left (int  x,int y,int k,char (*a)[23][12])
{
    int i,j;
    j=0;
    for(i=1;i<x/2;i++)
	a[k][i][j] = '|';
}

void  ver_line_lower_left (int  x,int y,int k,char (*a)[23][12])
{
    int i,j;
    j=0;
    for(i=x/2+1;i<x-1;i++)
	a[k][i][j] = '|';
}

void  ver_line_lower_right (int x,int y,int k,char (*a)[23][12])
{
    int i,j;
    j=y-1;
    for(i=x/2+1;i<x-1;i++)
	a[k][i][j] = '|';
}

void  hor_line_upper (int x,int y,int k,char (*a)[23][12])
{
    int i,j;
    i=0;
    for(j=1;j<y-1;j++)
	a[k][i][j] = '-';
}

void  hor_line_lower (int x,int y,int k,char (*a)[23][12])
{
    int i,j;
    i=x-1;
    for(j=1;j<y-1;j++)
	a[k][i][j] = '-';
}

void  hor_line_middle (int x,int y,int k,char (*a)[23][12])
{
    int i,j;
    i=x/2;
    for(j=1;j<y-1;j++)
	a[k][i][j] = '-';
}
#endif
