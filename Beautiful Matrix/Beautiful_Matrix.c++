// Problem link --> " https://codeforces.com/problemset/problem/263/A "

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5][5];
    int i,j;
    int ans;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }   

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(a[i][j]==1)
            {
                ans = abs(i-2)+abs(j-2);
                cout<<ans<<endl;
                return 0;
            }
        }
    }
}
