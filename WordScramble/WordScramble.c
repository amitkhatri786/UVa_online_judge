#include<stdio.h>

char str[1000];

void my_strrev(char *start,char *end)
{
	char temp;
	while(start<=end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main()
{
	int i;
	char *start,*end;
	while(gets(str)) {
		start = str;
		for(i=0;str[i]!='\0';i++) {
			if(str[i]==' ') {
				end = (str+i-1);
				my_strrev(start,end);
				i++;
				start = (str + i);
			}
		}
		end = (str + i -1);
		my_strrev(start,end);
		printf("%s\n",str);

	}
	return(0);
}
