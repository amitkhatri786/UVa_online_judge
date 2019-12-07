#include<stdio.h>
#include<malloc.h>

#define MAP_SIZE    10079

struct d{
    char t_name[31];
    int count;
};
typedef struct d DATA;
DATA data[10001];
int data_count;
int total_tree;
struct l {
    int id;
    struct l *next;
};
typedef struct l LIST;
LIST *map[MAP_SIZE+1];
int count;

void init()
{
    int i;
    LIST *cur,*temp;
    for(i=0;i<MAP_SIZE;i++){
        cur = map[i];
        while(cur){
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        map[i] = NULL;
    }
    total_tree = 0;
    count=0;
}

LIST *get_list_node(int id)
{
    LIST *node;
    node = (LIST *)malloc(sizeof(LIST));
    node->id = id;
    node->next = NULL;
    return(node);
}
int my_strlen(char *ch)
{
    int len =0;
    while(*ch){
        len++;
        ch++;
    }
    return(len);
}

int my_strcmp(char *a,char *b)
{
    while(*a && *b && *a==*b){
        a++;
        b++;
    }
    return(*a-*b);
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

unsigned long int calculate_hash(char *ch)
{
    unsigned long int hash=5381;
    int c;
    while(*ch){
        c = *ch;
        hash = (hash<<32 + hash)+ c;
        ch++;
    }
    return(hash%MAP_SIZE);
}

void insert_in_map(char *ch)
{
    unsigned int hash = calculate_hash(ch);
    LIST *cur;
    LIST *node;
    cur = map[hash];
    while(cur) {
        if(my_strcmp(data[cur->id].t_name,ch)==0) {
            data[cur->id].count++;
            break;
        }
        cur = cur->next;
    }
    if(cur==NULL){
        cur = map[hash];
        my_strcpy(data[total_tree].t_name,ch);
        data[total_tree].count = 1;
        node = get_list_node(total_tree);
        node->next = cur;
        map[hash] = node;
        total_tree++;
    }
}
int my_comprator(DATA a,DATA b)
{
    int x;
    x = my_strcmp(a.t_name,b.t_name);
    if(x==0)
        return 0;
    if(x>0)
        return(1);
    if(x<0)
        return(-1);
}

void heapify(int i,int N)
{
    int largest = i;
    DATA temp;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<N && my_comprator(data[l],data[largest])<0)
        largest = l;
    if(r<N && my_comprator(data[r],data[largest])<0)
        largest = r;
    if(largest != i){
       temp = data[largest];
        data[largest] = data[i];
        data[i] = temp;
        heapify(largest,N);
    }
}

void heap_sort(int N)
{
    int i;
    for(i=N/2-1;i>=0;i--)
        heapify(i,N);
}

void print_data(int N)
{
    int i;
    DATA temp;
    for(i=N-1;i>=0;i--){
        printf("%s %.4f\n",data[0].t_name,(float)data[0].count*100/count);
        temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        heapify(0,i);
    }
}

int main()
{
    int T;
    char str[31];
    char ch[31];
    int level = 0;
    int i;
    scanf("%d\n\n",&T);
    while(T--){
        init();
        while(gets(ch)) {
            if(my_strlen(ch)==0)
                break;
            insert_in_map(ch);
            count++;
        }
        /*printf("==============Before sort %d==============\n",count);
        for(i=0;i<total_tree;i++)
            printf("%s %d\n",data[i].t_name,data[i].count);*/
        heap_sort(total_tree);
        /*printf("==============After sort %d================================\n",count);*/
        print_data(total_tree);
        if(T>0)
            printf("\n");
        
    }
    return(0);
}


#if 0
struct t{
    int is_word;
    struct t *next[53];
};
typedef struct t TRIE;
TRIE buffer[500000];
int count_buf;
TRIE *root;
int total_tree;

TRIE *get_trie_node()
{
    int i;
    TRIE *node;
    node = &buffer[count_buf++];
    node->is_word =0;
    for(i=0;i<53;i++)
        node->next[i] = NULL;
    return(node);
}

void init()
{
    count_buf = 0;
    total_tree =0;
    root = get_trie_node();
}

void insert_trie(char *ch)
{
    int index;
    TRIE *temp = root;
    while(*ch){
        if(*ch>=65&& *ch<=90)
            index = *ch -'A';
        else if(*ch == ' ')
            index = 26;
        else if(*ch>=97 && *ch <= 122)
            index = 27 + *ch -'a';

        if(!temp->next[index])
            temp->next[index] = get_trie_node();
        temp = temp->next[index];
        ch++;
    }
    temp->is_word++;
}

void print_trie(TRIE *root,char str[],int level)
{
    int i;
    if(!root)
        return;
    if(root->is_word) {
        str[level] = '\0';
        printf("%s %.4f\n",str,(float)root->is_word*100/total_tree);
    }
    for(i=0;i<53;i++) {
        if (root->next[i]) {
            if (i >= 0 && i <= 25)
                str[level] = 'A' + i;
            else if (i == 26)
                str[level] = ' ';
            else if (i >= 27 && i <= 52)
                str[level] = 'a' + i -27;
            print_trie(root->next[i],str,level+1);
        }
    }
}



int main()
{
    int T;
    char str[31];
    char ch[31];
    int level = 0;
    scanf("%d\n\n",&T);
    while(T--){
        init();
        while(gets(ch)) {
            if(strlen(ch)==0)
                break;

                insert_trie(ch);
                total_tree++;

        }
        level=0;
        print_trie(root,str,level);
        if(T>0)
            printf("\n");
        
    }
    return(0);
}
#endif