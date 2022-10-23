#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int D,d,p,q;
	    cin>>D>>d>>p>>q;
	    //long long int k=0;
	    long long int sum=0;
	    long long int c=D/d;
	    long long int e=D%d;
	    
	    sum+=(p*d*c)+(q*d*c*(c-1))/2+(p+c*q)*(e);
	    cout<<sum<<endl;
	}
	return 0;
}
