#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   int arr[n];
	   for(int i=0;i<n;i++){
	       cin>>arr[i];
	   }
	   int maximum=0;
	   int minimum=arr[0];
	   int d;
	   for(int i=1;i<n;i++){
	       d=arr[i]-minimum;
	       if(d>maximum){
				maximum=d;
		   } 
	       if(arr[i]<minimum){
				minimum=arr[i];
		   }
	   }
	   if(maximum>0){
			cout<<maximum<<endl;
	   }
	   else{
	   		cout<<"UNFIT"<<endl;
		} 
		
	}
	return 0;
}