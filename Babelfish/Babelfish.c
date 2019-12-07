#include<stdio.h>
#include<malloc.h>
#define MAP_SIZE    10007

struct d{
    char ori[11];
    char lan[11];
    struct d *next;
};
typedef struct d DATA;
DATA *map[10010]={NULL,};

void my_strcpy(char *dest,char *src)
{
    while(*src){
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}
int my_strcmp(char *a,char *b)
{
    while(*a && *b && *a==*b){
        a++;
        b++;
    }
    return(*a-*b);
}

unsigned long int calculate_hash(char *ch)
{
    unsigned long int h = 5381;
    while(*ch){
        h = (h<<5)+(*ch+h);
        ch++;
    }
    return(h%MAP_SIZE);
}

DATA *get_list_node(char *ori,char *lang)
{
    DATA *node;
    node = (DATA *)malloc(sizeof(DATA));
    my_strcpy(node->ori,ori);
    my_strcpy(node->lan,lang);
    node->next = NULL;
    return(node);
}

void insert_in_hash(char *ori,char *lang,int hash)
{
    DATA *head,*node;
    head = map[hash];
    node= get_list_node(ori,lang);
    node->next = head;
    map[hash] = node;
}

void search_hash(char *ch)
{
    DATA *head;
    int hash = calculate_hash(ch);
    head = map[hash];
    while(head){
        if(my_strcmp(head->lan,ch)==0){
            printf("%s\n",head->ori);
            break;
        }
        head=head->next;
    }
    if(!head)
        printf("eh\n");
}

int main()
{
    char ch[11];
    char ch1[11];
    char ss[30];
    
    int hash;
    while (1)
    {
        gets(ss);
        if (ss[0] == '\0')
            break;
        sscanf(ss,"%s %s",ch,ch1);
        hash = calculate_hash(ch1);
        insert_in_hash(ch,ch1,hash);
    }
    while(scanf("%s",ch)!=EOF){
        search_hash(ch);
    }
    return(0);
}