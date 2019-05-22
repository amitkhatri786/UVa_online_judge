#include<stdio.h>
#include<malloc.h>

/*#define DEBUG */

struct t{
    struct t *next[4];
    int prefix;
    int is_word;
};
typedef struct t TRIE;
TRIE *root;
TRIE buffer[500000];
int buffer_count;
char data[1001];
char str[1001];
char ans[1001];
int ans_count;
int max;
int max_prefix;

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
    while(*src) {
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
    node = &buffer[buffer_count++];
    for(i=0;i<4;i++)
        node->next[i] = NULL;
    node->is_word = 0;
    node->prefix = 0;
    return(node);
}

void init()
{
    buffer_count = 0;
    root = get_trie_node();
}

void insert_trie(char *ch)
{
    TRIE *temp;
    int index;
    temp = root;
#ifdef DEBUG
    printf("%s -->%s \n",__func__,ch);
#endif
    while(*ch) {
        if (*ch == 'A')
            index = 0;
        else if (*ch == 'C')
            index = 1;
        else if (*ch == 'G')
            index = 2;
        else if (*ch == 'T')
            index = 3;
        if(temp->next[index]==NULL)
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        temp->prefix++;
        ch++;
    }
    temp->is_word++;
}

void search_trie(TRIE *root,int level)
{
    int i;
    if(!root)
        return;
    if (root->prefix>=2) {
        str[level]= '\0';
#ifdef DEBUG
        printf("%s, %d level = %d\n",str,root->prefix,level);
#endif
        if(level == max) {
            if(root->prefix > max_prefix) {
                max = level;
                max_prefix = root->prefix;
#ifdef DEBUG
                printf("ans = %s and str = %s\n",ans,str);
#endif
                my_strcpy(ans,str);
                ans_count = root->prefix;
            }
        } else if(level > max) {
                max = level;
                max_prefix = root->prefix;
                my_strcpy(ans,str);
                ans_count = root->prefix;
        }
    }
    for(i=0;i<4;i++) {
        if(root->next[i]) {
            switch(i) {
            case 0:
                str[level] = 'A';
                break;
            case 1:
                str[level] = 'C';
                break;
            case 2:
                str[level] = 'G';
                break;
            case 3:
                str[level] = 'T';
                break;
            }
            search_trie(root->next[i],level+1);
        }
    }
}

int main()
{
    int T;
    int x;
    int i,len;
    x = scanf("%d",&T);
    while(T--) {
        init();
#ifdef DEBUG
        printf("==========Test case =======\n");
#endif
        x = scanf("%s",data);
#ifdef DEBUG
    printf("data = %s\n",data);
#endif
        len = my_strlen(data);
        for(i=0;i<len;i++) {
            insert_trie(data + i);
        }
        max = -1;
        max_prefix = -1;
        search_trie(root,0);
        if(max == -1)
            printf("No repetitions found!\n");
        else {
            printf("%s %d\n",ans,ans_count);
        }
    }
    return(0);

}
