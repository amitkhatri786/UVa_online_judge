#include<stdio.h>
#include<malloc.h>


struct t{
	struct t *next[26];
	int is_word;
};
typedef struct t TRIE;
TRIE *root=NULL;

struct d{
	char word[16];
	int len;
};
typedef struct d DICTIONAY;
DICTIONAY dictionary[10001];
int dict_count=0;
int my_strlen(char *ch)
{
	int len = 0;
	while(*ch) {
		len++;
		ch++;
	}
	return(len);
}
void my_strcpy(char *dest,char *src)
{
	while(*src){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

TRIE *get_trie_node()
{
	int i;
	TRIE *node;
	node = (TRIE *)malloc(sizeof(TRIE));
	for(i=0;i<26;i++)
		node->next[i] = NULL;
	node->is_word = 0;
	return(node);
}
void delete_trie(TRIE *root)
{
	int i;
	if(!root)
		return;
	for(i=0;i<26;i++){
		if(root->next[i]){
			delete_trie(root->next[i]);
			free(root->next[i]);
			root->next[i] = NULL;
		}
	}
}

void init()
{
	delete_trie(root);
	dict_count =0 ;
	root = get_trie_node();
}

void insert_trie(char *ch)
{
	TRIE *temp;
	int i;
	temp = root;
	while(*ch){
		i = *ch - 'a';
		if(!temp->next[i])
			temp->next[i] = get_trie_node();
		temp = temp->next[i];
		ch++;
	}
	temp->is_word = 1;
}
int search_trie(char *ch)
{
	TRIE *temp;
	int index;
	temp = root;
	while(*ch) {
		index = *ch -'a';
		if(temp->next[index]==NULL)
			return(0);
		temp = temp->next[index];
		ch++;
	}
	if(temp)
		return(temp->is_word);
	return(0);
}

int is_one_edit_diff(int index,char str2[],int len2)
{
	int i,j;
	int diff;
	int len1 = dictionary[index].len;
	int count =0;
	i = 0 ;j = 0;
	while(i<len1 && j < len2) {
		diff = len1 - len2;
		if(diff<0)
			diff *= -1;
		if(diff>1)
			return(0);
		if(dictionary[index].word[i]!=str2[j]){
			count++;
			if(count>1)
				return 0;
			if(len1>len2)
				i++;
			else if(len1<len2)
				j++;
			else{
				i++;
				j++;
			}
		}else{
			i++;
			j++;
		}
	}
	if(i<len1 || j<len2)
		count++;
	return(count ==1);
}


int main()
{
	int T;
	int i,j;
	char word[16];
	int once=0;
	int len;
	TRIE *temp;
	scanf("%d",&T);
	while(T--) {
		init();
		while(scanf("%s",dictionary[dict_count].word)) {
			if(dictionary[dict_count].word[0]!='#'){
				dictionary[dict_count].len = my_strlen(dictionary[dict_count].word);
					insert_trie(dictionary[dict_count].word);
				dict_count++;
			}else
				break;
		}
		while(scanf("%s",word)) {
			if(word[0]!='#') {
				if(search_trie(word)) {
					printf("%s is correct\n",word);
				}else{
					len = my_strlen(word);
					printf("%s:",word);
					for(i=0;i<dict_count;i++) {
						if(is_one_edit_diff(i,word,len)) {
							printf(" %s",dictionary[i].word);
						}
					}
					printf("\n");
				}
			}else
				break;
		}
		if(T)
			printf("\n");
		once = 1;
	}
	return(0);
}
