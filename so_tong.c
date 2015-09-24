#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt);

int main()
{
	char *str1;
	char *str2,*str3;
	char *res;
	int L,N;
	int i;
	scanf("%d",&N);
	while(N--)
	{

		scanf("%d",&L);
		str1 = (char *) malloc (L+1);
		str2 = (char *) malloc (L+1);
		str3 = (char *) malloc (2*L+1);

		scanf("%s",str1);
		str1[strlen(str1)]='\0';
		scanf("%s",str2);
		str2[strlen(str2)]='\0';
		strcat(str3,str2);
		strcat(str3,str2);
		//printf("%s\n",str3);
		KMPSearch(str1,str3);
		free(str1);
		free(str2);
	}
	return(0);
}

void KMPSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix values for pattern
	int *lps = (int *)malloc(sizeof(int)*M);
	int j  = 0;  // index for pat[]

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0;  // index for txt[]
	while(i < N)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			printf("%d\n", i-j);
			break;
			j = lps[j-1];
		}

		// mismatch after j matches
		else if(pat[j] != txt[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if(j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
	free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)
{
	int len = 0;  // lenght of the previous longest prefix suffix
	int i;

	lps[0] = 0; // lps[0] is always 0
	i = 1;

	// the loop calculates lps[i] for i = 1 to M-1
	while(i < M)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if( len != 0 )
			{
				// This is tricky. Consider the example AAACAAAA and i = 7.
				len = lps[len-1];

				// Also, note that we do not increment i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
