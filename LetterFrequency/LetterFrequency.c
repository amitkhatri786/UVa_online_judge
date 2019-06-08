#include<stdio.h>

struct t{
    struct t *next[26];
    int prefix;
    int is_word;
};
typedef struct t TRIE;
TRIE buffer[200000];
int buffer_count;
TRIE *root;

char data[205];
char data1[205];
char ans[205];
int max_level;
int max_prefix;

TRIE *get_trie_node()
{
    TRIE *node;
    int i;
    node = &buffer[buffer_count++];
    for(i=0;i<26;i++) {
        node->next[i]= NULL;
    }
    node->is_word = 0;
    node->prefix = 0;
    return(node);
}

void init()
{
    buffer_count = 0;
    max_level = 0;
    max_prefix = 0;
    root = get_trie_node();
}
void convert_to_alphabates(char *dest,char *src)
{
    int i;
    int j = 0;
    for(i=0;src[i]!='\0';i++) {
        if(src[i]>= 65 && src[i]<=90)
            dest[j++] = src[i]+32;
        else if(src[i]>=97 && src[i]<=122)
            dest[j++] = src[i];
    }
    dest[j]= '\0';
}

void insert_trie(char *ch)
{
    int index;
    int i=0;
    TRIE *temp;
    temp = root;
    while(*ch) {
        index = *ch - 'a';
        if(!temp->next[index])
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        temp->prefix++;
        if(temp->prefix>=max_prefix) {
            max_prefix = temp->prefix;
            max_level = i+1;
        }
        ch++;
        i++;
    }
}
void print_trie(TRIE *root,int level)
{
    int i;
    if(!root)
        return;
    if(root->prefix == max_prefix && level == max_level) {
    
        ans[level] = '\0';
        printf("%s",ans);
#ifdef DEBUG
        printf("%s %d\n",ans,root->prefix);
#endif
        return;
    }
    for(i=0;i<26;i++) {
        if(root->next[i]) {
            ans[level] = 'a' + i;
            print_trie(root->next[i],level+1);
        }
    }
}

int main()
{
    int i,len;
    int N;
    int t;
    t = scanf("%d",&N);
    getchar();
    while(N--) {
        init();
        gets(data);
        convert_to_alphabates(data1,data);
        for(i=0;data1[i]!='\0';i++)
            insert_trie(data1+i);
#ifdef DEBUG
        printf("max_level = %d and max_prefix = %d\n",max_level,max_prefix);
#endif
        print_trie(root,0);
        printf("\n");
    }
    return(0);

}
