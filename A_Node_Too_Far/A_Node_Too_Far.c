#include<stdio.h>

struct edges
{
char u;
char v;
}e[900];

int main()
{
    int mat[30][30]={0};
    int i,j;
    int E,V;
    while(1)
    {
	scanf("%d",&E);
	if(E==0)
	    break;
        for(i=0;i<E;i++)
         {
           scanf("%d%d",&e[i].u,&e[i].v);
        }
     

   
    }




    return(0);
}

