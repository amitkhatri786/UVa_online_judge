/* This program require Next lexicographic permutation of string */

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int main()
{
    char arr[51]={0};
    int len;

    while(scanf("%s",arr))
    {
	if(arr[0]=='#')
	    break;
	else
	{
	    len = strlen(arr);
	    if(next_permutation(arr,arr+len))
		printf("%s\n",arr);
	    else
		printf("No Successor\n");
	}

    }
    return(0);
}

