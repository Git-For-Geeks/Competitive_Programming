// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int>& nums){
            int maxProfit=0;
            for(int i=1;i<nums.size();i++){
                if(nums[i]>nums[i-1]){ 
                    maxProfit+=nums[i]-nums[i-1]; 
                }
            }
            return maxProfit; 
        }
};

int main(){
    vector<int> p={7,1,5,3,6,4}; 
    Solution obj; 
    cout<<obj.maxProfit(p)<<endl; 
    return 0;
}