#include<stdio.h>

char data[205];
char data1[205];
char ans[205];
int freq[200];

void init()
{
    int i;
    for(i=97;i<=122;i++)
        freq[i] = 0;
}

void convert_to_alphabates(char *dest,char *src)
{
    int i;
    int j = 0;
    for(i=0;src[i]!='\0';i++) {
        if(src[i]>= 65 && src[i]<=90) {
            dest[j++] = src[i]+32;
            freq[src[i]+32]++;
        }
        else if(src[i]>=97 && src[i]<=122) {
            dest[j++] = src[i];
            freq[src[i]]++;
        }
        
    }
    dest[j]= '\0';
}


int main()
{
    int i,len;
    int N;
    int t;
    int max;
    t = scanf("%d",&N);
    getchar();
    while(N--) {
        init();
        gets(data);
        convert_to_alphabates(data1,data);
        max = 0;
        for(i=97;i<=122;i++) {
            if(max<freq[i])
                max = freq[i];
        }
        for(i=97;i<=122;i++) {
            if(freq[i]==max)
                printf("%c",i);
        }
        printf("\n");
    }
    return(0);

}
