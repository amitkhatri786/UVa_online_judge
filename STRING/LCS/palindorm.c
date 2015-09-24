#include<stdio.h>
#include<string.h>

void print_lcs(char path[][100],char str1[],int i,int j);

int main()
{

    char str1[100]={0};
    char str2[100]={0};
    int LCS[100][100]={0};
    char path[100][100]={0};
    int i,j;
    int len1,len2;

    scanf("%s",str1);
    scanf("%s",str2);
    len1 = strlen(str1);
    len2 = strlen(str2);

    for(i=0;i<=len1;i++)
	LCS[i][0] = 0;

    for(i=0;i<=len2;i++)
	LCS[0][i] = 0;

    for(i=1;i<=len1;i++)
    {
	for(j=1;j<=len2;j++)
	{
	    if(str1[i-1] == str2[j-1])
	    {
		LCS[i][j] = 2 + LCS[i-1][j-1];
		path[i][j] = '\\';
	    }
	    else
	    {
		if(LCS[i-1][j] >= LCS[i][j-1])
		{
		    LCS[i][j] = LCS[i-1][j];
		    path[i][j] = '|';
		}
		else
		{
		    LCS[i][j] = LCS[i][j-1];
		    path[i][j] = '-';
		}
	    }
	}
    }

    for(i=0;i<=len1;i++)
    {
	for(j=0;j<=len2;j++)
	    printf("%d ",LCS[i][j]);
	printf("\n");
    }
    printf(" ");
    for(i=0;i<len2;i++)
	printf("%c ",str2[i]);
    printf("\n");
    for(i=1;i<=len1;i++)
    {
	printf("%c ",str1[i-1]);
	for(j=1;j<=len2;j++)
	    printf("%c ",path[i][j]);
	printf("\n");
    }

    print_lcs(path,str1,len1,len2);
    printf("\n");
    return(0);

}

void print_lcs(char path[][100],char str1[],int i,int j)
{
    // printf("i= %d,j= %d\n",i,j);
    if(i == 0 || j == 0)
	return;
    if(path[i][j]== '\\')
    {
	print_lcs(path,str1,i-1,j-1);
	printf("%c ",str1[i-1]);
    }
    else if(path[i][j] == '|')
	print_lcs(path,str1,i-1,j);
    else
	print_lcs(path,str1,i,j-1);

}

