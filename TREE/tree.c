#include<stdio.h>
#include<stdlib.h>


struct tree
{

	struct tree *left;
	int data;
	struct tree *right;
};

typedef struct tree TREE;

TREE *create_node(int d);
void inorder_traversal(TREE *root);
TREE *insert_node(TREE *root,int d);
void delete_tree(TREE *root);
void level_order_traversal(TREE *root);
TREE *delete_node(TREE *root,int d);
TREE *find_min(TREE *root);



int main()
{

	TREE *root=NULL;
	int i;
	int a[20];
	int d;

	for(i=0;i<15;i++)
	{
		d = random()%1000;
		a[i]=d;
		printf("%d-->",d);
		root = insert_node(root,d);
	}
	printf("\n");
	inorder_traversal(root);
	printf("\n");
	level_order_traversal(root);
	printf("\n");
	for(i=0;i<15;i++)
	{
		root = delete_node(root,a[random()%15]);
		inorder_traversal(root);
		printf("\n");
	}
	root=NULL;
	delete_tree(root);
	root = NULL;
	printf("\n");

	return(0);
}

TREE *create_node(int d)
{
	TREE *node;
	node = (TREE *)malloc(sizeof(TREE));
	node->data = d;
	node->left=NULL;
	node->right = NULL;
	return(node);
}

TREE *insert_node(TREE *root,int d)
{
	if(root==NULL)
		return(create_node(d));
	else if(root->data > d)
		root->left = insert_node(root->left,d);
	else if(root->data < d)
		root->right = insert_node(root->right,d);

	return(root);
}

void inorder_traversal(TREE *root)
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		printf("%d ",root->data);
		inorder_traversal(root->right);
	}
}

void delete_tree(TREE *root)
{
	if(root!=NULL)
	{
		delete_tree(root->left);
		delete_tree(root->right);
		free(root);
	}
}

void level_order_traversal(TREE *root)
{
	TREE *queue[100]={NULL};
	TREE *deque_data=NULL;
	int level=1;
	int i;
	int count=1;
	int front = -1;
	int rear = -1;
	queue[0]=root;
	front++;
	rear++;
	while(front<=rear)
	{	
		deque_data = queue[front];
		printf("-->%d",deque_data->data);
		front++;
		if(deque_data->left !=NULL)
			queue[++rear]=deque_data->left;
		if(deque_data->right)
			queue[++rear]=deque_data->right;
	}

}

TREE *delete_node(TREE *root,int d)
{
	TREE *temp;
	if(root == NULL)
		return(root);
	else if(root->data > d)
		root->left = delete_node(root->left,d);
	else if(root->data < d)
		root->right = delete_node(root->right,d);
	else {
		if(root->left==NULL ) /* Right child present*/
		{
			temp = root->right;
			free(root);
			return(temp);
		}
		else if(root->right == NULL ) /* Left child present */
		{
			temp = root->left;
			free(root);
			return(temp);
		}
		/* both Child present */
		temp = find_min(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right,temp->data);
	}

	return(root);
}

TREE *find_min(TREE *root)
{

	TREE *temp;
	temp = root;
	while(temp->left != NULL)
	{
		temp = temp -> left;
	}
	return(temp);
}

