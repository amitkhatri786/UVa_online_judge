/* MAIN LOGIC IS COLOR THE DISCONNECTED GAPH
AND FIND THE MINIMUM NODES WHICH COMES
GRAPH CAN BE COLOR BY ONLY 2 COLOR OTHERWISE IS IMPOSSIBLE ANS
DO BFS  ON EACH NODE IF IT IS NOT COLORED. 
BY THIS WAY YOU CAN COLOR EACH COMPONENT OF GRAPH
 */

#include<stdio.h>

int bfs(int mat[][201],int start,int V);

int color[201]={0};

int main()
{

    int mat[201][201]={0};
    int i,j,k;
    int V,E;
    int r,c;
    int t;
    int sol=0;
    int ans=0;
    k = scanf("%d",&t);
    for(i=0;i<201;i++)
      color[i] = -1;
    while(t--)
    {
	k = scanf("%d%d",&V,&E);
	for(i=0;i<E;i++)
	{
	    k = scanf("%d%d",&r,&c);
	    mat[r][c] =1;
	    mat[c][r] =1;
	}
	/*	for(i=0;i<V;i++)
		{
		for(j=0;j<V;j++)
		printf("%d ",mat[i][j]);
		printf("\n");
		}
	 */
	for(i=0;i<V;i++)
	{
	    if(color[i] == -1)
	    {
		sol = bfs(mat,i,V);
		if(sol != -1 )
		    ans = ans + sol;
		else
		{	
		    ans = sol;
		    break;
		}
	    }
	}
	printf("%d\n",ans);
	for(i=0;i<V;i++)
	{
	    for(j=0;j<V;j++)
		mat[i][j] = 0;
	    color[i]= -1;
           
	}
       ans=0;sol=0;
    }
    return(0);
}


int bfs(int mat[][201], int start, int V)
{
    int queue[2000]={0};
    int front,rear; 
    int v,x;
    int total=0;
    int i;
    front = -1;
    rear = -1;
    int color_count=0;

    color[start] = 1;
    front = 0;
    rear = 0;
    queue[rear] = start;
	while(front <= rear )
	{
	    v = queue[front];
	    front++;
	    total++;
            if(color[v]==1)
               color_count++;
	    for(i=0;i<V;i++)
	    {
		if(mat[v][i] == 1 && color[i] == -1)
		{
		    color[i] = 1 - color[v];
		    queue[++rear] = i;
		}
		else
		{
		    if(mat[v][i] == 1 && color[i] == color[v])
			return(-1);
		}
	    }  
	}
/*	printf("total = %d\n",total); 
        printf("\n color_count = %d and total-color_count = %d\n",color_count,total-color_count); */
     if(total ==1 ) 
      return 1; 
     return(min(color_count,total-color_count));
} 

int min(int a, int b)
{

    if(a>b)
	return(b);
    else
	return(a);
}

