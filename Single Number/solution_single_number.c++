#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    char end;
    int a;
    cin>>noskipws;
    while(end!='\n')
    {
        cin>>a;
        nums.push_back(a);
        cin>>end;
    }

    sort(nums.begin(),nums.end());

    int i;
    for(i=0;i<nums.size();)
    {
        if(nums[i]==nums[i+1])
        {
            i=i+2;
        }
        else
        {
            cout<<nums[i]<<endl;
            return 0;
        }
    }

    return 0;
}