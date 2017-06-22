#include<stdio.h>
#include<malloc.h>


//#define DEBUG

#define STACK_SIZE 16000000

//int mat[100005][100005];
struct graph
{
	int node;
	struct graph *next;
};

typedef struct graph GRAPH;


int stack[STACK_SIZE] = { 0 };


int component_count(int start_vertex, int N,int visited[],GRAPH *mat[])
{


	int top = 0;
	GRAPH *u, *v;
	int temp;

	stack[top] = start_vertex;
	visited[start_vertex] = 1;
	while (top >= 0)
	{
		temp = stack[top];
		top--;
		u = mat[temp];
		while (u != NULL)
		{
			if (visited[u->node] != 1)
			{
				stack[++top] = u->node;
				visited[u->node] = 1;
			}
			u = u->next;
		}
	}

	return(1);
}


void insert_edges(GRAPH *mat[],int u, int v)
{
	GRAPH *head;
	GRAPH *temp;



	head = mat[u - 1];
	temp = (GRAPH *)calloc(1, sizeof(GRAPH));
	temp->node = v - 1;
	temp->next = head;
	mat[u-1] = temp;

	head = mat[v - 1];
	temp = (GRAPH *)calloc(1, sizeof(GRAPH));
	temp->node = u - 1;
	temp->next = head;
	mat[v-1] = temp;
}


int main()
{
	int n, m;
	long int C_lib, C_road;
	int q, a0, a1;
	int city_1, city_2;
	long int cost = 0;
	int i, count;
	// int component_vertex_count = 0;
	long int road_cost, lib_cost;
	int j;
	GRAPH *head = NULL;

	scanf("%i", &q);
	for (a0 = 0; a0 < q; a0++)
	{
		cost = 0;
		count = 0;
		scanf("%i %i %li %li", &n, &m, &C_lib, &C_road);
		GRAPH *mat[100005] ={0};
		for (a1 = 0; a1 < m; a1++)
		{
			scanf("%i %i", &city_1, &city_2);
			insert_edges(mat,city_1, city_2);
			//insert_edges(mat,city_2, city_1);
		}
		if (C_lib < C_road)
		{
			cost = n*C_lib;
		}
		else
		{
			int visited[100005] = { 0 };
			for (i = 0; i<n; i++)
			{
				if (visited[i] != 1)
					count = count + component_count(i, n, visited,mat);
			}
			cost = (n - count) *C_road + count*C_lib; //Number of edges = n - connected component
		}
#ifdef DEBUG
		printf("Total component count= %d\n", count);
#endif
		printf("%ld\n", cost);
	}
	return 0;
}

