#include<stdio.h>

char line[1000];
int map[128];

int main()
{
    int i;
    int max=-1;
    while(gets(line)){
        if(!line[0])
            break;
        for(i=65;i<123;i++){
            map[i] = 0;
        }
        i= 0;
        max = -1;
        while(line[i]){
            if((line[i]>=65 && line[i]<=90) ||(line[i]>=97 && line[i]<=122)){
                map[line[i]]++;
                if(max<map[line[i]])
                    max = map[line[i]];
            }
            i++;
        }
        for(i=65;i<123;i++){
            if(map[i]==max){
                printf("%c",i);
            }
        }
        printf(" %d\n",max);
    }
    return(0);
}