#include<stdio.h>

void merge(int array[],int temp[],int left,int mid, int right);
void mergesort(int array[],int temp[],int left,int right);

int main()
{
    int array[100]={0};
    int temp[100]={0};
    int n;
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++)
	scanf("%d",&array[i]);

    mergesort(array,temp,0,n-1);

    for(i=0;i<n;i++)
	printf("%d ",array[i]);
    printf("\n");
    return(0);
}

void mergesort(int array[],int temp[],int left,int right)
{
    int mid;
//	printf("left = %d, right = %d mid = %d\n",left,right,(left+right)/2);
    if(right>left)
    {
	mid = (left+right)/2;
	mergesort(array,temp,left,mid);
	mergesort(array,temp,mid+1,right);
	merge(array,temp,left,mid+1,right);
    }
}

void merge(int array[],int temp[],int left,int mid, int right)
{
    int temp_pos=left;
    int l = left;
    int r = mid;
    int i;
    printf("left = %d, right = %d mid = %d\n",left,right,mid);
    while(l<mid && r <= right)
    {
	if(array[l] > array[r])
	{
	    temp[temp_pos] = array[r];
	    temp_pos++;
	    r++;
	}
	else
	{
	    temp[temp_pos] = array[l];
	    temp_pos++;
	    l++;
	}
    }
    while(l<mid)
    {
	temp[temp_pos] = array[l];
	temp_pos++;
	l++;
    }
    while(r<=right)
    {
	temp[temp_pos] = array[r];
	temp_pos++;
	r++;
    }
    for(i=left;i<=right;i++)
	array[i] = temp[i];

}

