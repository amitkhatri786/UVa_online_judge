#include<stdio.h>
#include<malloc.h>

#define CHARS   26

struct l{
    int index;
    struct l *next;
};
typedef struct l LIST;

struct t{
    struct t *next[CHARS];
    int is_word;
    LIST *start;
};
typedef struct t TRIE;
#if 0
TRIE buffer[250000];
int buffer_count;
LIST l_buffer[700000];
int l_buffer_count;
#endif
TRIE *root;
struct d {
    char word[200];
    int label;
    int len;
};
typedef struct d DATA;
DATA dictionary[20001];
int dic_count;
int ans[20];
int ans_count;


void my_strcpy(char *dest,char *src)
{
    while(*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int my_strlen(char *ch)
{
    int len=0;
    while(*ch){
        len++;
        ch++;
    }
    return(len);
}

int my_strcmp(char *ch1,char *ch2)
{
    while(*ch1 && *ch2) {
        if(*ch1!=*ch2)
            break;
        ch1++;
        ch2++;
    }
    return(*ch1-*ch2);
}

LIST *get_list_node(int index)
{
    LIST *node;
#if 0
    node = &l_buffer[l_buffer_count++];
#else
    node = (LIST *)malloc(sizeof(LIST));
#endif
    node->index = index;
    node->next = NULL;
    return(node);
}

TRIE *get_trie_node()
{
    TRIE *node;
    int i;
#if 0
    node = &buffer[buffer_count++];
#else
    node = (TRIE *)malloc(sizeof(TRIE));
#endif
    for(i=0;i<CHARS;i++)
        node->next[i] = NULL;
    node->is_word = 0;
    node->start = NULL;
    return(node);
}

void init()
{
#if 0
    buffer_count = 0;
    l_buffer_count = 0;
#endif
    root = get_trie_node();
    dic_count = 1;
}

int my_compare(int data,int new_data)
{
#ifdef DEBUG
    printf("my_compare --> %s %s\n",dictionary[data].word,dictionary[new_data].word);
#endif
    if(dictionary[data].len > dictionary[new_data].len)
        return 1;
    if(dictionary[data].len < dictionary[new_data].len)
        return -1;
    if(dictionary[data].len == dictionary[new_data].len) {
        if(my_strcmp(dictionary[data].word,dictionary[new_data].word) > 0)
            return 1;
        if(my_strcmp(dictionary[data].word,dictionary[new_data].word) < 0)
            return -1;
        if(my_strcmp(dictionary[data].word,dictionary[new_data].word) == 0) {
            if (data > new_data)
                return 1;
            if (data < new_data)
                return -1;
            if (data == new_data) {
                return 0;
            }
        }
    }
}

void insert_in_sorted_order(LIST **head,int index)
{
    LIST *node;
    LIST *cur;
    int t,flag =0;
    if(*head == NULL || my_compare((*head)->index,index) >= 0) {
        node = get_list_node(index);
        node->next = *head;
        *head = node;
        return;
    }
    cur = *head;
    while(cur->next!=NULL && (t = my_compare(cur->next->index,index)<0)) {
         cur = cur->next;
    }
    node = get_list_node(index);
    node->next = cur->next;
    cur->next = node;
}

void insert_trie(char *ch,int index)
{
#ifdef DEBUG
    printf("insert_trie --> %s,%d\n",ch,index);
#endif
    TRIE *temp;
    LIST *lnode;
    int idx;
    temp = root;
    while(*ch) {
        idx = *ch - 'a';
        if(!temp->next[idx])
            temp->next[idx] = get_trie_node();
        temp = temp->next[idx];
        insert_in_sorted_order(&temp->start,index);
        ch++;
    }
    temp->is_word = 1;
}

void search_trie(char *ch)
{
#ifdef DEBUG
    printf("search_trie --> %s\n",ch);
#endif
    TRIE *temp;
    LIST *head;
    int index,prev;
    temp = root;
    while(*ch) {
        index = *ch - 'a';
        if(temp->next[index] ==NULL) {
#ifdef DEBUG
            printf("-1\n");
#endif
            ans[ans_count++] = -1;
            return;
        }
        temp = temp->next[index];
        ch++;
    }
    head = temp->start;
    while(head && head->next!=NULL && ans_count!=10) {
        if(head->index != head->next->index) {
#ifdef DEBUG
            printf("%d--> ",head->index);
#endif
            ans[ans_count++] = head->index;
        }
       /*,dictionary[head->index].word, \
        dictionary[head->index].len,dictionary[head->index].label);*/
        head = head->next;
    }
    if(head && ans_count!=10) {
#ifdef DEBUG
        printf("%d",head->index);
#endif
        ans[ans_count++] = head->index;
    }
        /*,dictionary[head->index].word, \
            dictionary[head->index].len,dictionary[head->index].label);*/
    /*printf("\n");*/
}

int main()
{
    char dic[200];
    int i;
    int N,Q;
    int len;
    int t;
    init();
    t = scanf("%d",&N);
    while(N--) {
        t = scanf("%s",dic);
        my_strcpy(dictionary[dic_count].word,dic);
        len = my_strlen(dictionary[dic_count].word);
        dictionary[dic_count].len = len;
        dictionary[dic_count].label = dic_count;  
        for(i=0;dic[i]!='\0';i++) {
            insert_trie(dic + i,dic_count);
        }
        
        dic_count++;
    }
    t = scanf("%d",&Q);
    while(Q--) {
        t = scanf("%s",dic);
        ans_count = 0;
        search_trie(dic);
        for(i=0;i<ans_count;i++) { 
            if(i==ans_count-1)
                printf("%d\n",ans[i]);
            else 
                printf("%d ",ans[i]);
        }
    }
    printf("\n");
    return(0);
}
