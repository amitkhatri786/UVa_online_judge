#include<stdio.h>
#include<string.h>

struct bevarage_order{
    char B1[52];
    char B2[52];
};

typedef struct bevarage_order BORDER;

void topo_sort(int mat[][101],int V);

char bevarages[101][52]={0};
int topo_order[101]={0};

int main()
{

    BORDER b[201]={0};
    char tmp[52]={0};
    int mat[101][101]={0};
    int i,j,k;
    int V,E;
    int r,c;
    int t=1;
    while((scanf("%d",&V)==1))
    {
	for(i=0;i<V;i++)
	{
	    k = scanf("%s",tmp);
	    strcpy(bevarages[i],tmp);
	}
	k = scanf("%d",&E);
	for(i=0;i<E;i++)
	{
	    k = scanf("%s%s",b[i].B1,b[i].B2);
	    for(j=0;j<V;j++)
	    {
		if(strcmp(b[i].B1,bevarages[j])==0)
		{
		    r = j;
		    break;
		};
	    }
	    for(j=0;j<V;j++)
	    {
		if(strcmp(b[i].B2,bevarages[j])==0)
		{
		    c = j;
		    break;
		};
	    }
	    mat[r][c] =1;
	}
#if 0
	for(i=0;i<V;i++)
	{
	    for(j=0;j<V;j++)
		printf("%d ",mat[i][j]);
		//printf("[%s,%s] ",bevarages[i],bevarages[j]);
	    printf("\n");
	}
	for(i=0;i<V;i++)
	    printf("%d  %s\n",i,bevarages[i]);
#endif
	topo_sort(mat,V);
        printf("Case #%d: Dilbert should drink beverages in this order: ",t++);
	for(i=0;i<V-1;i++)
	    printf("%s ",bevarages[topo_order[i]-1]);
	printf("%s.",bevarages[topo_order[i]-1]);
	for(i=0;i<V;i++)
	{
	    for(j=0;j<V;j++)
		mat[i][j] = 0;
	    topo_order[i]=0;
	} 
	getchar();
	printf("\n\n");
       
    }
    return(0);
}

void topo_sort(int mat[][101],  int V)
{
    int queue[1000]={0};
    int indegree[101]={0};
    int front,rear; 
    int counter=0;
    int v;
    int i,j;
    front = -1;
    rear = -1;

    for(i=0;i<V;i++)
	for(j=0;j<V;j++)
	    if(mat[j][i] == 1)
		indegree[i]++;


    front = 0;
    for(i=0;i<V;i++)
	if(indegree[i] == 0)
	    queue[++rear] = i;

    while(front <= rear )
    {
	v = queue[front];
	front++;
	topo_order[counter++] = v+1;
	for(i=0;i<V;i++)
	    if(mat[v][i] == 1 && --indegree[i] == 0)
		queue[++rear] = i;
    }

}

