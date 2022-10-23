// Problem Link: https://www.codingninjas.com/codestudio/problems/allocate-books_1090540 


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isPossible(vector<int> arr,int n,int m,int mid){
            int studentCount=1; 
            int pageSum=0; 
            for(int i=0;i<n;i++){
                if(pageSum+arr[i]<mid){
                    pageSum=pageSum+arr[i]; 
                }
                else{
                    studentCount++; 
                    if(studentCount>m || arr[i]>mid){
                        return false; 
                    }
                    pageSum=arr[i];       //next student ke liye count karna chalu kar denge  
                }
            }
            return true; 
        }

        int allocateBooks(vector<int>& arr,int n,int m){
            int s=0,sum=0; 
            for(int i=0;i<n;i++){
                sum+=arr[i]; 
            } 
            int e=sum; 
            int ans=-1; 
            while(s<=e){
                int mid=s+(e-s)/2; 
                if(isPossible(arr,n,m,mid)){
                    ans=mid; 
                    e=mid-1; 
                }
                else{
                    s=mid+1; 
                }
            }
            return ans; 
        }
}; 

int main(){
    int n=4,m=4; 
    vector<int> v={5,17,100,11}; 
    // int n=4,m=2; 
    // vector<int> v={12,34,67,90};  
    Solution ob;  
    cout<<ob.allocateBooks(v,n,m)<<endl;
    return 0;
}