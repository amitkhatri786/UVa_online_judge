#include <iostream>  
#include <queue>  
#include<stdio.h>

using namespace std;  

struct compare  
{  
    bool operator()(const int& l, const int& r)  
    {  
	return l > r;  
    }  
};  

int main()  
{  
    priority_queue<int,vector<int>, compare > pq;  
    int x;
    int t;
    int n,i;
    int cost;
    int sum=0;
    while(scanf("%d",&n))
    {   
	if(n==0)
	    break;
	cost =0;
        sum =0;
	for(i=0;i<n;i++)
	{
	    t = scanf("%d",&x);
	    pq.push(x);
	}  
	while ( !pq.empty() )  
	{  
	    cost = cost + pq.top(); 
            pq.pop();
            cost = cost + pq.top();
            pq.pop();
	    pq.push(cost);
            sum = sum + cost;
	    if(pq.size()==1)
		break;
           cost=0;
	}  
	printf("%d\n",sum);
       while(!pq.empty())
         pq.pop();
    }
    return(0);
}  
