#include<stdio.h>

struct l{
    char ch[6];
    int index;
    struct l *next;
};
typedef struct l LIST;
LIST list_buf[100000];
int list_buf_count;

LIST *map[100010] ={NULL};


unsigned long int calculate_hash(char *ch)
{
    int x;
    int hash = 5381;
    while(x = *ch++)
        hash = (hash<<5) + hash + x;
    return(hash%100003);
}

void my_strcpy(char *dest,char *src)
{
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int my_strcmp(char *a,char *b)
{
    while(*a && *b && *a==*b){
        a++;
        b++;
    }
    return(*a - *b);
}

LIST *get_list_node(char *ch,int idx)
{
    LIST *node = &list_buf[list_buf_count++];
    node->index = idx;
    my_strcpy(node->ch,ch);
    node->next = NULL;
    return(node);
}

void insert_map(char *ch,int index)
{
    unsigned long int h;
    LIST *head,*node;
    h = calculate_hash(ch);
    head = map[h];
    node = get_list_node(ch,index);
    node->next = head;
    map[h] = node;
}

int search_map(char *ch)
{
    LIST *head;
    unsigned long int h = calculate_hash(ch);
    head = map[h];
    while(head){
        if(my_strcmp(ch,head->ch)==0)
            return(head->index);
        head = head->next;
    }
    return(0);
}

void pre_process()
{
    char i,j,k,l,m;
    int count=0;
    char ch[6] = {0};
    for(i='a';i<='z';i++){
        ch[0] = i;
        count++;
        insert_map(ch,count);
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            ch[0] = i;
            ch[1] = j;
            count++;
            insert_map(ch,count);
        }
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            for(k=j+1;k<='z';k++){
                ch[0] = i;
                ch[1] = j;
                ch[2] = k;
                count++;
                insert_map(ch, count);
            }
        }
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            for(k=j+1;k<='z';k++){
                for(l=k+1;l<='z';l++){
                    ch[0] = i;
                    ch[1] = j;
                    ch[2] = k;
                    ch[3] = l;
                    count++;
                    insert_map(ch, count);
                }
            }
        }
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            for(k=j+1;k<='z';k++){
                for(l=k+1;l<='z';l++){
                    for(m=l+1;m<='z';m++){
                        ch[0] = i;
                        ch[1] = j;
                        ch[2] = k;
                        ch[3] = l;
                        ch[4] = m;
                        count++;
                        insert_map(ch, count);
                    }
                }
            }
        }
    }
}


int main()
{
    char ch[6];
    int x;
    pre_process();
    while(scanf("%s",ch)!=EOF){
        x = search_map(ch);
        printf("%d\n",x);
    }
    return(0);
}


#ifdef SOLUTION1
struct t{
    struct t *next[26];
    int is_word;
};
typedef struct t TRIE;
TRIE *root;
TRIE trie_buf[100000];
int trie_buf_count=0;

TRIE *get_trie_node()
{
    int i;
    TRIE *node = &trie_buf[trie_buf_count++];
    for(i=0;i<26;i++)
        node->next[i] = NULL;
    node->is_word = 0;
    return(node);
}

void insert_trie(char *ch,int idx)
{
 #ifdef DEBUG
    printf("%s %d\n",ch,idx);
 #endif   
    TRIE *temp=root;
    int index;
    while(*ch) {
        index = *ch - 'a';
        if(!temp->next[index])
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        ch++;
    }
    temp->is_word = idx;
}

int search_trie(char *ch)
{
    int index;
    TRIE *temp = root;
    while(*ch) {
        index = *ch -'a';
        if(!temp->next[index])
            return(0);
        temp = temp->next[index];
        ch++;
    }
    return(temp->is_word);
}

void pre_process()
{
    char i,j,k,l,m;
    int count=0;
    char ch[6] = {0};
    for(i='a';i<='z';i++){
        ch[0] = i;
        count++;
        insert_trie(ch,count);
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            ch[0] = i;
            ch[1] = j;
            count++;
            insert_trie(ch,count);
        }
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            for(k=j+1;k<='z';k++){
                ch[0] = i;
                ch[1] = j;
                ch[2] = k;
                count++;
                insert_trie(ch, count);
            }
        }
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            for(k=j+1;k<='z';k++){
                for(l=k+1;l<='z';l++){
                    ch[0] = i;
                    ch[1] = j;
                    ch[2] = k;
                    ch[3] = l;
                    count++;
                    insert_trie(ch, count);
                }
            }
        }
    }
    for(i='a';i<='z';i++){
        for(j=i+1;j<='z';j++){
            for(k=j+1;k<='z';k++){
                for(l=k+1;l<='z';l++){
                    for(m=l+1;m<='z';m++){
                        ch[0] = i;
                        ch[1] = j;
                        ch[2] = k;
                        ch[3] = l;
                        ch[4] = m;
                        count++;
                        insert_trie(ch, count);
                    }
                }
            }
        }
    }
}

int main()
{
    char ch[6];
    int x;
    root = get_trie_node();
    pre_process();
    while(scanf("%s",ch)!=EOF){
        x = search_trie(ch);
        printf("%d\n",x);
    }
    return(0);
}
#endif