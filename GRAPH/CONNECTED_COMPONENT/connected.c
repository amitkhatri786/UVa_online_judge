#include<stdio.h>
#include<malloc.h>


#define DEBUG

#define STACK_SIZE 30000

//int mat[100005][100005];
struct graph
{
	int node;
	struct graph *next;
};

typedef struct graph GRAPH;

GRAPH *mat[1000005] =  {0};
GRAPH *stack[STACK_SIZE]= {0};
int visited[100005]={0};

#if 0
int component_count(int start_vertex,int N,int *number_vertex)
{

	int top=0;
	int u,v;
	int total=0;
	stack[top]=start_vertex;
	visited[start_vertex] = 1;

	while(top>=0)
	{
		u = stack[top];
		total++;
		top--;
		for(v=0;v<N;v++)
		{
			if(mat[u][v] == 1 && visited[v] !=1)
			{
				stack[++top] = v;
				visited[v] = 1;
			}
		}
	}
	*number_vertex = total;
#ifdef DEBUG
	printf("Total vrtex in this component is %d\n",total);
#endif
	return(1);
}
#endif

int component_count(int start_vertex,int N,int *number_vertex)
{
	int top = 0;
	GRAPH *u,*v;
	GRAPH *temp;
	int total=0;
	stack[top] = mat[start_vertex];
	visited[start_vertex] = 1;
	while(top >= 0)
	{
		u = stack[top];
		total++;
		top--;
		temp = u;
		while(temp != NULL) 
		{
			if(visited[temp->node] != 1)
			{
				stack[++top] = temp;
				visited[temp->node] = 1;
			}
		
			temp = temp->next;
		}
	}
	*number_vertex = total;
#ifdef DEBUG
	printf("Total vrtex in this component is %d\n",total);
#endif
	return(1);
}

void insert_edges(int u,int v)
{
	GRAPH *head;
	GRAPH *prev;
	
	if(mat[u-1] == NULL)
	{
		head = (GRAPH *)calloc(1,sizeof(GRAPH));
		head->node = v-1;
		head->next = NULL;
		mat[u-1] = head;
	}
	else
	{
		head = mat[u-1];
		while(head!=NULL)
		{
			prev = head;
			head = head ->next;
		}
		prev->next = (GRAPH *)calloc(1,sizeof(GRAPH));
		prev->next-> node = u-1;
		prev->next-> next = NULL;
	}

	if(mat[v-1] == NULL)
	{
		head = (GRAPH *)calloc(1,sizeof(GRAPH));
		head->node = u-1;
		head->next = NULL;
		mat[v-1] = head;
	}
	else
	{
		head = mat[v-1];
		while(head!=NULL)
		{
			prev = head;
			head = head ->next;
		}
		prev->next = (GRAPH *)calloc(1,sizeof(GRAPH));
		prev->next->node = v-1;
		prev->next->next = NULL;
	}
}


int main() 
{
	int n,m; 
	long int C_lib,C_road; 
	int q,a0,a1;
	int city_1,city_2;
	long int cost=0;
	int i,count;
	int component_vertex_count=0;
	int road_cost,lib_cost;
	int j;
	GRAPH *head=NULL;

	scanf("%i", &q);
	for(a0 = 0; a0 < q; a0++)
	{
		cost =0;
		count =0;
		scanf("%i %i %li %li", &n, &m, &C_lib, &C_road);
		for(a1 = 0; a1 < m; a1++)
		{
			scanf("%i %i", &city_1, &city_2);
			insert_edges(city_1,city_2);
			//mat[city_1-1][city_2-1] = 1;
			//mat[city_2-1][city_1-1] = 1;
		}
		for(i=0;i<n;i++)
		{
			if(visited[i] != 1)
			{
				count = count + component_count(i,n,&component_vertex_count);
				road_cost = (component_vertex_count-1) * C_road + C_lib;
				lib_cost  = component_vertex_count * C_lib;
				if(road_cost < lib_cost)
				{
#ifdef DEBUG
					printf("Select road repairing\n");
#endif
					cost = cost + road_cost;
				}
				else
				{
#ifdef DEBUG
					printf("Select library building\n");
#endif
					cost = cost + (lib_cost);
				}
			}
			
		}
#ifdef DEBUG
		printf("Total component count= %d\n",count);
#endif
		printf("%li\n",cost);
		for(i=0;i<n;i++)
			visited[i]=0;
		for(i=0;i<n;i++)
		{
			head = mat[i];
			while(head!=NULL)
			{
				mat[i] = head->next;
				free(head);
				head=NULL;
			}
			mat[i] = NULL;

		}
	}
	return 0;
}
