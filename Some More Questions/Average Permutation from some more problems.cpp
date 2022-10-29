#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll tc;
    cin >> tc;

    while (tc--)
    {
        
int n;
	    cin>>n;
	    int arr[n];
	    if(n==1){
	        cout<<1<<endl;
	    }
	    else if(n==2){
	        cout<<1<<" "<<2<<endl;
	    }
	    else if(n==3){
	        cout<<3<<" "<<1<<" "<<2<<endl;
	    }
	    else if(n==4){
	        cout<<4<<" "<<1<<" "<<2<<" "<<3<<endl;
	    }
	    else{
	        cout<<n<<" "<<n-2<<" ";
	        for(int i=1;i<n-3;i++){
	            cout<<i<<" ";
	        }
	        cout<<n-3<<" "<<n-1<<endl;
	    }
    }

    return 0;
}