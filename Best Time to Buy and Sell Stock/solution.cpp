#include<bits/stdc++.h>
using namespace std;

int main(){




    int n;
    cout << "Enter the size of the array: "; cin >> n;

    int arr[n];
    
    cout << "Enter all the element of the array: ";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int profit = 0;

    int i=0, j=n-1;

    while(i < j){

        if(arr[i] > arr[j]){
            i++;
        }

        if(arr[i] < arr[j]){

            profit = max(profit, arr[j]-arr[i]);
            j--;
        }

    }

    cout << "Max Profit: " << profit << endl;

    return 0;

}
