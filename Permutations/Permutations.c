#include<stdio.h>

#if 1
#define DEBUG
#endif

void Sorting(char S[],int *len)
{
	int i,j;
	int map[27]={0};
	for(i=0;S[i]!='\0';i++)
		map[S[i]-'a']++;
	j=0;
	for(i=0;i<26;i++)
	{
		while(map[i]--)
			S[j++]='a'+i;
			
	}
	*len = j;
#ifdef DEBUG
	printf("%s len = %d\n",S,j);
#endif

}

#if 0
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
#endif

void factorial_radix(long long int N,int number[],int *number_len)
{
	int i,j;
	int temp;
	i=1;
	j=0;
	while(N != 0)
	{
		number[j] = N%i;
		N = N/i;
		j++;
		i++;
	}
	*number_len = j;
	i=0;
	j = *number_len-1;
	while(i<j)
	{
		temp = number[j];
		number[j] = number[i];
		number[i] = temp;
		i++;
		j--;
	}
#ifdef DEBUG
	for(i=0;i<*number_len;i++)
		printf("%d ",number[i]);
	printf("\n");
#endif

}

void process_factorial_number(char ch[],int len,int number[],int number_len)
{
	int i,j;
	for(i=0;i<number_len;i++)
	{
		printf("%c",ch[number[i]]);
		j = number[i]; 
		while(j < len)
		{
			ch[j] = ch[j+1];
			j++;
		}
		len = len-1;
	}
	if(len>0)
		printf("%s",ch);
	printf("\n");
}

int main()
{

	int T;
	long long int N;
	int len;
	int factorial_number_len;
	scanf("%d",&T);
	while(T--)
	{
		char S[26]={0};
		int factorial_number[70];
		scanf("%s%lld",S,&N);
		Sorting(S,&len);
		factorial_radix(N,factorial_number,&factorial_number_len);
		process_factorial_number(S,len,factorial_number,factorial_number_len);
	}
	return(0);
}


