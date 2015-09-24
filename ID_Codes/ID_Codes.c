/* This program require Next lexicographic permutation of string */

#include<stdio.h>
#include<string.h>


int next_permutation(char *ch);

int main()
{
    char arr[51]={0};
    while(scanf("%s",arr))
    {
	if(arr[0]=='#')
	    break;
	else
	{
	    /*		printf("%s\n",arr); */
	    if(!next_permutation(arr))
		printf("No Successor\n");
	    else
		printf("%s\n",arr);
	}

    }
    return(0);
}

int next_permutation(char *ch)
{
    int len;
    int i,j;
    int first_charecter;
    int second_charecter;
    char t;
    len = strlen(ch);
 /*   printf("len =%d\n",len); */
    i = len - 1;
    while(i>0 && ch[i-1] >= ch[i])
	i--;
    if(i<=0)
	return(0);

    first_charecter = i-1;    
    /*    printf("first_charecter= %d\n",first_charecter); */
    i = len - 1;
    while(i>0 && ch[first_charecter] >= ch[i])
	i--;
    second_charecter = i;
    /*  printf("second_charecter= %d\n",second_charecter); */
    t = ch[first_charecter];
    ch[first_charecter] = ch[second_charecter];
    ch[second_charecter] = t;    
    first_charecter++;
    second_charecter = len -1;
    while(first_charecter < second_charecter)
    {
	t = ch[first_charecter];
	ch[first_charecter] = ch[second_charecter];
	ch[second_charecter] = t;    
	first_charecter++;
	second_charecter--;
    }
    return(1);
}

