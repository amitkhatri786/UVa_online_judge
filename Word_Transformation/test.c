#include<stdio.h>

int main()
{
char x[10];
char y[10];
while(1)
{
scanf("%s%s",x,y);

printf("%s  %s \n",x,y);
if(x[0] == ' ')
break;
}
return(0);
}
