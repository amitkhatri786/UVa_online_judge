#include<stdio.h>

void print(int s[][10],int i,int j);

int main()
{
    int a[10]={30,35,15,5,10,20,25};
    int mat[10][10]={0};
    int s[10][10]={0};
    int i,j,k,L;
    int n;
    int q;
    n= 7;
    for(i=0;i<n;i++)
	mat[i][i]=0;

    for(L=2;L<n;L++)
    {
	for(i=1;i<=n-L+1;i++)
	{
	    j = i+L-1;
	    mat[i][j]=9999999;
	    for(k=i;k<=j-1;k++)
	    {	q = mat[i][k]+mat[k+1][j] + a[i-1]*a[k]*a[j];
		if(q<mat[i][j])
		   {
			 mat[i][j]=q;
			 s[i][j]= k;
			}
	    }
	}
    }
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	    printf("%6d ",mat[i][j]);
	printf("\n");
    }

printf("\n");
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	    printf("%6d ",s[i][j]);
	printf("\n");
    }
	print(s,1,7);
    return(0);
}

void print(int s[][10],int i,int j)
{

    if(i==j)
	printf("A%d",i);
    else
    {
	printf("(");
	print(s,i,s[i][j]);
	print(s,s[i][j]+1,j);
	printf(")");
    }
}
