#include<stdio.h>

struct t{
    struct t *next[4];
    char end[2];
};
typedef struct t TRIE;
TRIE *root;
TRIE  buffer[300000];
int buffer_count;
int get_int[130];
char get_char[4];
int max_level;
char data1[305];
char data2[305];
char ans[305];

int my_strlen(char *ch)
{
    int len=0;
    while(*ch) {
        len++;
        ch++;
    }
    return(len);
}

TRIE *get_trie_node()
{
    int i;
    TRIE *node;
    node = &buffer[buffer_count++];
    for(i=0;i<4;i++)
        node->next[i] = NULL;
    node->end[0] = node->end[1] = 0;
    return(node);
}

void init()
{
    get_char[0] = 'a';
    get_char[1] = 'c';
    get_char[2] = 'g';
    get_char[3] = 't';
    get_int['a'] = 0;
    get_int['c'] = 1;
    get_int['g'] = 2;
    get_int['t'] = 3;
    buffer_count = 0;
    root = get_trie_node();
    max_level = 0;
}

int insert_trie(char *ch,int k)
{
    TRIE *temp;
    int index,i;
    temp = root;
    i=0;
    while(*ch) {
        index = get_int[*ch];
        if(!temp->next[index])
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        temp->end[k] = 1;
        if(temp->end[0] && temp->end[1]) {
            if(max_level < (i+1))
                max_level = i+1;
        }
        ch++;
        i++;
    }
}

void search_trie(TRIE *root,int level)
{
    int i;
    if(!root)
        return;
    if(level == max_level && root->end[0] && root->end[1]) {
        ans[level]= '\0';
        printf("%s\n",ans);
    }
    for(i=0;i<4;i++) {
        if(root->next[i]) {
            ans[level] = get_char[i];
            search_trie(root->next[i],level+1);
        }
    }
}

int main()
{
    int first=0;
    int i,len;
    while(gets(data1)) {
        gets(data2);
        init();
        len = my_strlen(data1);
        for(i=0;i<len;i++) 
            insert_trie(data1+i,0);
        len = my_strlen(data2);
        for(i=0;i<len;i++)
            insert_trie(data2+i,1);
        
        if(first)
            printf("\n");
        first = 1;
        if(max_level)
            search_trie(root,0);
        else 
            printf("No common sequence.\n");
        gets(data1);
    }
    return(0);
}