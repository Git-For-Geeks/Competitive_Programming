// Problem Link: https://practice.geeksforgeeks.org/problems/square-root/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int floorSqrt(long long int x) {
        long long int ans=1;
        long long int s=1;
        long long int e=x; 
        while(s<=e){
            long long int m=s+(e-s)/2; 
            if(m*m <= x){
                s=s+1; 
                ans=m; 
            }
            else{
                e=m-1; 
            }
        }
        return ans; 
    }
};


int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
