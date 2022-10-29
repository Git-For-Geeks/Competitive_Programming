// Arrival of the General
 
#include <bits\stdc++.h>
using namespace std;
int main()
{
	int i,a,k=0,x,b=0,c=101,n,j=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
	 	cin>>a;
	 	if(b<a) 
		{
		 	b=a;
		    j=i;
	 	}
	 	if(c>=a)
	 	{
	 		c=a;
	 		k=i;
		}
	}
	x=j+n-1-k;
	if(j>k) x--;
	cout<<x;
}