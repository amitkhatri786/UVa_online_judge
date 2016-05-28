#include<stdio.h>

int update_parent(int *parent,int compi,int compj);

int main()
{

    int parent[1000000]={0};
    int compi,compj;
    char command;
    int number_of_computer;
    int T,t; 
    int p,q;
    int blank=0;
    int i;
    int success=0,unsuccess=0;
    t=scanf("%d",&T);

    while(T--)
    {
	for(i=0;i<1000000;i++)
	    parent[i] = i;
	success=0;
	unsuccess=0;
	getchar();
	t=scanf("%d\n",&number_of_computer);
	while((command=getchar()) && isalpha(command))
	{
	    t=scanf("%d%d\n",&compi,&compj);
	    p = update_parent(parent,compi,compj);
	    q = update_parent(parent,compj,compi);
	    if(command == 'c')  
		parent[p]=q;
	    else
	    {
		if(p==q)
		    success++;
		else
		    unsuccess++;
	    }
	}
	if(blank) 
	    printf("\n");
	blank=1;
	    printf("%d,%d\n",success,unsuccess);
    }
    return(0);
}

int  update_parent(int *parent,int compi,int compj)
{
    int i,j;
    if(parent[compi]==compi)
	return(compi);
    else
    {
	while(parent[compi]!=compi)
	    compi = parent[compi];
    }
    return(compi);
}

