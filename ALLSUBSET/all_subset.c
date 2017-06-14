#include<stdio.h>

int main() 
{
	int p[20], N = 5;

	for (int i = 0; i < N; i++) 
		p[i] = i;

	for (int i = 0; i < (1 << N); i++)  // number of all subset is 2^N i.e. 2^5 = 32
	{
		for (int j = 0; j < N; j++)
			if (i & (1 << j))  // if bit j is on
				printf("%d ", p[j]);   // this is part of set

		printf("\n");

	}
	return(0);
}
