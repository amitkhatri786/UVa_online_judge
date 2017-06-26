#include<stdio.h>


void Sorting(char S[],int *len)
{
	int i,j;
	int map[27]={0};
	for(i=0;S[i]!='\0';i++)
		map[S[i]-'a']++;
	j=0;
	for(i=0;i<26;i++)
	{
		if(map[i] == 1)
			S[j++]='a'+i;
	}
	*len = j;
	/*printf("%s len = %d\n",S,j);*/
}

void next_permutation(char ch[],int len)
{
	int i,j;
	char pivot;
	char temp;
	i = len-1;
	while(i > 0  && ch[i-1] >= ch[i] )
		i--;

	if(i<=0)
	{
	/*	printf("Last permutation\n"); */
		return;
	}
	pivot = ch[i-1];
	j = len-1;
	while(ch[j] <= pivot)
		j--;

	/*swap with pivot element; */
	temp = ch[i-1];
	ch[i-1] = ch[j];
	ch[j] = temp;
	
	/*reverse from ith element */
	j=len-1;
	while(i<j)
	{
		temp = ch[j];
		ch[j] = ch[i];
		ch[i] = temp;
		i++;
		j--;
	}
}


int main()
{

	int T;
	long long int N;
	int len;
	char pivot;
	scanf("%d",&T);
	while(T--)
	{
		char S[26]={0};
		scanf("%s%lld",S,&N);
		Sorting(S,&len);
		if(N==0)
			printf("%s\n",S);
		while(N--)
		{
			next_permutation(S,len);
			printf("%s\n",S);
		}
		
	}
	return(0);
}

