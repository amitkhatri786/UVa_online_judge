#include<stdio.h>
#include<string.h>

#define N 200
#define WORD_SIZE 10

int diff_word(char *,char *);
int min_distance(int start,int des,int mat[][N],int size);


int distance[N][N]={0};
struct dictionary
{
    char word[WORD_SIZE+1];
}dict[N]={0};

int main()
{

    char temp[WORD_SIZE+1];
    int T;
    char line[WORD_SIZE*2]={0};
    int i,j;
    int mat[N][N]={0};
    int n;
    char t;
    char start[WORD_SIZE+1]={0};
    char end[WORD_SIZE+1]={0};
    int start_pos=0,end_pos=0;
    t= scanf("%d\n",&T);
    while(T--)
    {
	i=0;
	while(1)
	{
	    gets(line);
	    sscanf(line,"%s",dict[i++].word);
	    if(dict[i-1].word[0]=='*')
	    {
		i--;
		break;
	    }
	}
	n = i;
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
		mat[i][j]=0;
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
		if((strlen(dict[i].word) == strlen(dict[j].word)))
		    if(diff_word(dict[i].word,dict[j].word)==1)
		    {
			mat[i][j] = 1;
			mat[j][i] = 1;
		    }
	t = min_distance(start_pos,end_pos,mat,n);
	while(1)
	{
	    if((gets(line))==NULL)
		break;;
	    if(line[0] == '\0')
		break;
	    sscanf(line,"%s %s",start,end);
	    for(i=0;i<n;i++)
		if(strcmp(dict[i].word,start)==0)
		{
		    start_pos = i;
		    break;
		}

	    for(i=0;i<n;i++)
		if(strcmp(dict[i].word,end)==0)
		{
		    end_pos = i;
		    break;
		}
	    if(strcmp(start,end)==0)
		printf("%s %s 0\n",start,end);
	    else
		if(strlen(start) != strlen(end))
		    printf("%s %s -1\n",start,end);
		else
		    printf("%s %s %d\n",start,end,distance[start_pos][end_pos]);
	    end[0] = '\0';
	}
	if(T!=0)
	    printf("\n");
    }
    return(0);
}



int min_distance(int start,int des,int mat[][N],int size)
{
    int i,j,k;
    for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	    distance[i][j]=0;
    for(i=0;i<size;i++)
	for(j=0;j<size;j++)
	{
	    if(i==j)
		distance[i][j] = 0;
	    else
	    {
		if(mat[i][j] == 0)
		    distance[i][j] = 99999;
		else
		    distance[i][j] = mat[i][j];
	    }
	}
    for(k=0;k<size;k++)
	for(i=0;i<size;i++)
	    for(j=0;j<size;j++)
		if(distance[i][j] > distance[i][k] + distance[k][j] )
		    distance[i][j] = distance[i][k] + distance[k][j];
    return(distance[start][des]);
}


int diff_word(char *ch1, char *ch2)
{

    int i,j;
    int diff=0;
    while(*ch1!='\0')
    {
	if(*ch1 != *ch2 )
	    diff++;
	ch1++;
	ch2++;
    }
    return(diff);
}
