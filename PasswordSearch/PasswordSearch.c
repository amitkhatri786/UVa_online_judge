#include<stdio.h>

struct t
{
    struct t *next[26];
    int count;
};
typedef struct t TRIE;
TRIE buf[1300000];
int buf_count;
TRIE *root;

char s[1500000];
int max;
char ans[20];
char ans1[20];

void my_strcpy(char *dest,char *src)
{
    while(*src){
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
TRIE *get_trie_node()
{
    int i;
    TRIE *node;
    node = &buf[buf_count++];
    for(i=0;i<26;i++)
        node->next[i] = NULL;
    node->count = 0;
    return(node);
}

void insert_trie(char *ch,char *ch1)
{
    TRIE *temp;
    int index;
    temp = root;
    while(ch!=ch1){
        index = *ch - 'a';
        if(!temp->next[index])
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        ch++;
    }
    temp->count++;
}

void init()
{
    buf_count = 0;
    root = get_trie_node();
    max = -1;
}

void find_max(TRIE *root,int level)
{
    int i;
    if(!root)
        return;
    if(root->count>max){
        max = root->count;
        ans[level] = '\0';
        my_strcpy(ans1,ans);
    }

    for(i=0;i<26;i++){
        if(root->next[i]){
            ans[level] = 'a' + i;
            find_max(root->next[i],level+1);
        }
    }
}

int main()
{
    int i,j;
    int k;
    int N;
    char aux[15];
    int len;
    char *ch;
    while(scanf("%d%s\n",&N,s)!=EOF){
        init();
        len = my_strlen(s);
        ch = s;
        for(i=0;i<=len-N;i++){
            insert_trie((ch+i),(ch+i+N));
        }
        find_max(root,0);
        printf("%s\n",ans1);
    }
    return(0);
}
