#include<iostream>
using namespace std;
  long long Solve(int arr[], int n){
    
          long long res=0,index=0;
         long long mx=arr[0],nc=0,nums=0;    
        for(int i=1;i<n;i++){
       if(arr[i]>=mx){
           res=res+nc*(mx)-(nums);
           mx=arr[i];
           nc=0;
           nums=0;
           index=i;
          
       }
       else if(arr[i]<mx){
           nc++;
           nums=nums+arr[i];
       }
     
    }
    mx=arr[n-1];
    nc=0;
    int index2;
           nums=0;
    // cout<<index<<" "<<endl;
    for (int i=n-2;i>=index;i--){
        
        if(arr[i]>=mx){
           res=res+nc*(mx)-(nums);
           mx=arr[i];
           nc=0;
           nums=0;
        //   index=i;
          
       }
       else if(arr[i]<mx){
           nc++;
           nums=nums+arr[i];
       }
    }
    return res;
    }

int main()
{   int n=12;
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int height[]={4,2,0,3,2,5};
    cout<<Solve(height,n)<<endl;;
    return 0;
}