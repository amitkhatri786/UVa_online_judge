#include<stdio.h>
#include<string.h>

char str[1001];
int freq[128];

struct d{
	int ascci;
	int freq;
};
typedef struct d DATA;
DATA data[130];
int data_count;
DATA arr1[130];
DATA arr2[130];

void init()
{
	int i;
	for(i=0;i<128;i++)
		freq[i] = 0;
	data_count=0;
}

int compare(DATA a,DATA b)
{
	if(a.freq<b.freq)
		return -1;
	else {
		if(a.freq>b.freq)
			return 1;
		if(a.freq==b.freq) {
			if(a.ascci>b.ascci)
				return -1;
			else
				return 1;
		}
	}
}

void merge(int l,int m,int h)
{
	int n1,n2;
	int i,j,k;
	n1 = m - l +1;
	n2 = h - m;
	for(i=0;i<n1;i++)
		arr1[i] = data[l+i];
	for(j=0;j<n2;j++)
		arr2[j] = data[m+j+1];
	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2){
		if(compare(arr1[i],arr2[j])<=0) {
			data[k] = arr1[i];
			i++;
		}else {
			data[k] = arr2[j];
			j++;
		}
		k++;
	}
	while(i<n1) {
		data[k] = arr1[i];
		i++;
		k++;
	}
	while(j<n2) {
		data[k] = arr2[j];
		j++;
		k++;
	}
}

void my_sort(int low,int high)
{
	int mid;
	if(low<high){
		mid = (low+ high)/2;
		my_sort(low,mid);
		my_sort(mid+1,high);
		merge(low,mid,high);
	}
}


int main()
{
	int i;
	int first=0;
	/*while((scanf("%[^\n]s",str))!=EOF) {*/
	while(gets(str)) {
		init();
		if(first)
			printf("\n");
		first = 1;
		for(i=0;str[i]!='\0';i++) {
			freq[str[i]]++;
		}
		for(i=127;i>=0;i--) {
			if(freq[i]) {
#ifdef DEBUG
				printf("char %c i = %d freq = %d\n",i,i,freq[i]);
#endif
				data[data_count].ascci = i;
				data[data_count].freq = freq[i];
				data_count++;
			}
		}
		my_sort(0,data_count-1);
		for(i=0;i<data_count;i++) {
			printf("%d %d\n",data[i].ascci,data[i].freq);
		}
	}
	return(0);
}
