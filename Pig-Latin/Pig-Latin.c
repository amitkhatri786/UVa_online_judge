#include<stdio.h>

char data[1000000000];
char ans[2000000000];


int main()
{
    int i,j;
    char temp;
    while(gets(data)) {
        j = 0;
        for(i=0;data[i]!='\0';) {
            if((data[i] >= 65 && data[i]<=90) || (data[i]>=97&& data[i]<=122)) {
                switch (data[i]) {
                case 'A':
                case 'a':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    while ((data[i] >= 65 && data[i] <= 90) ||(data[i] >= 97 && data[i] <= 122)) {
                        ans[j] = data[i];
                        i++;
                        j++;
                    }
                    ans[j++] = 'a';
                    ans[j++] = 'y';
                    break;
                default:
                    temp = data[i];
                    i++;
                    while ((data[i] >= 65 && data[i] <= 90)||(data[i] >= 97 && data[i] <= 122)) {
                        ans[j] = data[i];
                        i++;
                        j++;
                    }
                    ans[j++] = temp;
                    ans[j++] = 'a';
                    ans[j++] = 'y';
                    break;
                }
            }else {
                ans[j++] = data[i++];
            }
        }
        ans[j] = '\0';
        printf("%s\n",ans);
    }
    return(0);
}