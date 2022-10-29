
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int x=0,rest;
long long n;
cin>>n;
while(n!=0)
{rest=n%10;
n=n/10;
if(rest==7 || rest==4)
x++;
}
if(x==7 || x==4)
cout<<"YES";
else
cout<<"NO";
return 0;
}