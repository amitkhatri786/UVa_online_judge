#include<stdio.h>
#include<malloc.h>

struct t{
	struct t *next[10];
	int isleaf;
};
typedef struct t TRIE;
TRIE *root;

TRIE *get_trie_node()
{
	TRIE *node;
	int i;
	node = (TRIE *)malloc(sizeof(TRIE));
	node->isleaf = 0;
	for(i=0;i<10;i++)
		node->next[i] = NULL;
	return(node);
}

int my_strlen(char *ch)
{
	int len = 0;
	while(*ch) {
		ch++;
		len++;
	}
	return(len);
}

void delete_trie(TRIE *root)
{
	int i;
	if(!root)
		return;

	for(i=0;i<10;i++){
		if(!root->next[i]) {
			delete_trie(root->next[i]);
			free(root->next[i]);
			root->next[i] = NULL;
		}
	}
}

void init()
{
	delete_trie(root);
	free(root);
	root = get_trie_node();
}

int insert_trie(char *ch)
{
	TRIE *temp;
	int index;
	int len;
	int i;
	temp = root;
	len = my_strlen(ch);
	for(i=0;i<len;i++) {
		index = ch[i] - '0';
		if(i == (len-1) && temp->next[index] != NULL) {
			return 1;
		}
		if(temp->next[index] == NULL)
			temp->next[index] = get_trie_node();
		temp = temp->next[index];
		if(temp->isleaf == 1)
			return 1;
	}
	temp->isleaf = 1;
	return(0);
}

int main()
{
	int T;
	int N;
	int found=0;
	char phone[41];
	scanf("%d",&T);
	while(T--) {
		init();
		found = 0;
		scanf("%d",&N);
		while(N--) {
			scanf("%s",phone);
			if(found)
				continue;
			if(insert_trie(phone) == 1) {
				printf("NO\n");
				found = 1;
			}
		}
		if(!found)
			printf("YES\n");
	}
	return(0);
}
