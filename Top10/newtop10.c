#include <stdio.h>
#include <malloc.h>

#define CHARS 26

struct l
{
	int index;
	struct l *next;
};
typedef struct l LIST;

struct t
{
	struct t *next[CHARS];
	LIST *start;
	LIST *end;
	int is_word;
};
typedef struct t TRIE;
TRIE *root;
struct d
{
	char *word;
	int len;
	int label;
};
typedef struct d DICTIONARY;
DICTIONARY dictionary[20002];
int dict_count;
char dic[100002];
struct m
{
	LIST *start;
	LIST *end;
	int count;
};
typedef struct m MAP;
MAP map[100005];

int my_strlen(char *ch)
{
	int len = 0;
	while (*ch)
	{
		ch++;
		len++;
	}
	return (len);
}

void my_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int my_strcmp(char *ch1, char *ch2)
{
#ifdef DEBUG
	printf("ch1 = %s ch2 = %s", ch1, ch2);
#endif
	while (*ch1 && *ch2)
	{
		if (*ch1 != *ch2)
			break;
		ch1++;
		ch2++;
	}
#ifdef DEBUG
	printf(" return = %d\n", *ch1 - *ch2);
#endif
	return (*ch1 - *ch2);
}

LIST *get_list_node(int index)
{
	LIST *node;
	node = (LIST *)malloc(sizeof(LIST));
	node->index = index;
	node->next = NULL;
	return (node);
}
TRIE *get_trie_node()
{
	int i;
	TRIE *node;
	node = (TRIE *)malloc(sizeof(TRIE));
	node->is_word = 0;
	node->start = NULL;
	node->end = NULL;
	for (i = 0; i < CHARS; i++)
		node->next[i] = NULL;
	return (node);
}

void init()
{
	dict_count = 1;
	root = get_trie_node();
}
int my_compare(DICTIONARY a, DICTIONARY b)
{
	int cmp;
	if (a.len == b.len)
	{
		cmp = my_strcmp(a.word, b.word);
		if (cmp == 0)
			return (a.label < b.label);
		return (cmp < 0);
	}
	return (a.len < b.len);
}

void merge(int l, int m, int h)
{
	int n1, n2;
	int i, j, k;
	DICTIONARY *arr1, *arr2;
	n1 = m - l + 1;
	n2 = h - m;
	arr1 = (DICTIONARY *)malloc(sizeof(DICTIONARY) * n1);
	arr2 = (DICTIONARY *)malloc(sizeof(DICTIONARY) * n2);
	for (i = 0; i < n1; i++)
		arr1[i] = dictionary[l + i];
	for (j = 0; j < n2; j++)
		arr2[j] = dictionary[m + j + 1];
	i = j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (my_compare(arr1[i], arr2[j])) {
			dictionary[k] = arr1[i];
			i++;
		}
		else {
			dictionary[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		dictionary[k] = arr1[i];
		i++;
		k++;
	}
	while (j < n2) {
		dictionary[k] = arr2[j];
		j++;
		k++;
	}
	free(arr1);
	free(arr2);
}

void my_sorting(int l, int h)
{
	int mid;
	if (l < h) {
		mid = (l + h) / 2;
		my_sorting(l, mid);
		my_sorting(mid + 1, h);
		merge(l, mid, h);
	}
}

void insert_trie(char *ch, int id)
{
	TRIE *temp;
	LIST *node;
	int index;
	temp = root;
	while (*ch) {
		index = *ch - 'a';
		if (!temp->next[index])
			temp->next[index] = get_trie_node();
		temp = temp->next[index];
		ch++;
	}
	temp->is_word = 1;
	if (!temp->start) {
		node = get_list_node(id);
		temp->start = node;
		temp->end = node;
	}
	else {
		node = get_list_node(id);
		temp->end->next = node;
		temp->end = node;
	}
}


void search_trie(char *ch,int idx)
{
	TRIE *temp;
	LIST *head;
	LIST *node;
	int qid;
	int index;
	temp = root;
	while (*ch) {
		index = *ch - 'a';
		if (temp->next[index] != NULL) {
			temp = temp->next[index];
			head = temp->start;
			while(head) {
				qid = head->index;
				if(map[qid].count<10 && ! (map[qid].end && map[qid].end->index == idx)) {
					if(!map[qid].start) {
						node = get_list_node(idx);
						map[qid].start = node;
						map[qid].end = node;
						map[qid].count++;
					}else {
						node = get_list_node(idx);
						map[qid].end->next = node;
						map[qid].end = node;
						map[qid].count++;
					}
				}
				head = head->next;
			}
		}
		else 
			break;
		ch++;
	}
}

int main()
{
	
	int i, qid, j, k;
	LIST *head;
	int N, Q, len, t;
	int tot,tot_qid;
	init();
	t = scanf("%d", &N);
	i = 0;
	while (N--) {

		t = scanf("%s", dic);
		len = my_strlen(dic);
		dictionary[i].word = (char *)malloc(sizeof(char)*(len+1));
		my_strcpy(dictionary[i].word,dic);
		dictionary[i].label = dict_count;
		dictionary[i].len = len;
		i++;
		dict_count++;
	}
	tot = i;
	my_sorting(0, tot - 1);
#ifdef DEBUG
	for (i = 0; i < tot; i++)
		printf("str = %s len = %d label = %d\n", dictionary[i].word, dictionary[i].len,
			   dictionary[i].label);
#endif
	t = scanf("%d", &Q);
	i = 0;
	while (Q--) {
		t = scanf("%s", dic);
		insert_trie(dic,i);
		/* for (j = 0; j < dic[j] != '\0'; j++)
		// {
		// 	insert_trie(dic + j, i);
		// }
		*/
		i++;
	}
	tot_qid = i;
	for (i = 0; i < tot; i++) {
		len = dictionary[i].len;
		for (j = 0; j < len; j++) {
			search_trie(dictionary[i].word + j,dictionary[i].label);
		}
	}
	for(i=0;i<tot_qid;i++) {
		if(map[i].count==0)
			printf("-1");
		else {
			head = map[i].start;
			printf("%d",head->index);
			head = head->next;
			while(head) {
				printf(" %d",head->index);
				head = head->next;
			}
		}
		printf("\n");
	}
	return (0);
}
