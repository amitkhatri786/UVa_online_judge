#include<stdio.h>

struct t{
    struct t *next[26];
    int is_word;
    int is_mark;
};
typedef struct t TRIE;
TRIE buffer[500000];
int buffer_count;
TRIE *root;
int visited[100];
int tot_count = 0;
char s[20];

int my_strlen(char *ch)
{
    int len = 0;
    while(*ch) {
        len++;
        ch++;
    }
    return(len);
}

void my_trim(char *src,char *dest,int *len)
{
    int i=0;
    int j=0;
    while(src[i]!='\0') {
        if(src[i]!=' ') {
                dest[j] = src[i];
                j++;
        }
        i++;
    }
    *len = j;
    dest[j]='\0';
}


TRIE *get_trie_node()
{
    TRIE *node;
    int i;
    node = &buffer[buffer_count++];
    for(i=0;i<26;i++)
        node->next[i] = NULL;
    node->is_word = 0;
    node->is_mark =0;
    return(node);
}

void init()
{
    buffer_count = 0;
    tot_count = 0;
    root = get_trie_node();
}

void insert_trie(char *ch)
{
    TRIE *temp;
    int index;
    temp = root;
    while(*ch) {
        index = *ch - 'a';
        if(temp->next[index]==NULL)
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        ch++;
    }
    temp->is_word++;
}

void search_word(TRIE *root,int level,int len,char f_query[])
{
    int i;
    int index;
    if(!root)
        return;
    if(root->is_word && root->is_mark==0) {
        s[level] = '\0';
        #ifdef DEBUG
        printf("Ans --> %s\n",s);
        #endif
        tot_count = tot_count + root->is_word;
        root->is_mark = 1;
    }
    for(i=0;i<len;i++) {
        if(visited[i]==0) {
            visited[i] = 1;
            index = f_query[i] - 'a';
            s[level] = f_query[i];
            search_word(root->next[index],level+1,len,f_query);
            visited[i] = 0;
        }
    }
}

void reset_trie(TRIE *root,int len,char f_query[])
{
    int i;
    int index;
    if(!root)
        return;
    if(root->is_word && root->is_mark==1) {
    #ifdef DEBUG
        printf("Ans --> %s\n",s);
    #endif
        root->is_mark = 0;
    }
    for(i=0;i<len;i++) {
        if(visited[i]==0) {
            visited[i] = 1;
            index = f_query[i] - 'a';
            reset_trie(root->next[index],len,f_query);
            visited[i] = 0;
        }
    }
}

int main()
{
    char word[11];
    char query[20];
    char f_query[20];
    int len;
    char c;
    int i,t;
    init();
    while(1) {
        t = scanf("%s",word);
        if(word[0] == '#')
            break;
        insert_trie(word);
    }
    t = scanf("%c",&c);
    while (1) {
        t = scanf("%[^\n]%*c", query);
        if (query[0] == '#')
            break;
        len = 0;
        my_trim(query, f_query, &len);
        tot_count = 0;
        #ifdef DEBUG
        printf("Going to search for %s\n",f_query);
        #endif
        search_word(root, 0, len, f_query);
        reset_trie(root,len,f_query);
        printf("%d\n", tot_count);
    }

    return(0);
}