#include<stdio.h>


int main()
{
    char ch;

    while((ch = getchar())!=EOF)
    {
	if(ch == '\n')
	    printf("%c",ch);
	else

	    printf("%c",ch-7);
    }


    return(0);
}

