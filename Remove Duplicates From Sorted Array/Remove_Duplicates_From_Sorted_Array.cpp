#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Remove_duplicate(int a[], int n);

int main()
{
    int n,index;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    index=Remove_duplicate(a, n);

    cout<<"Array After Removing duplicate Elements:\n";
    for(int i=0;i<index;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

//Function to remove duplicates.
int Remove_duplicate(int a[], int n)
{
    //index represent size of array which does not contains duplicate.
    int index = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == a[i + 1])
        {
            continue;
        }
        else
        {
            //storing the last iteration of duplicate element in 'index' location 
            a[index++] = a[i];
        }
    }
    //Adding the last element of the array to the 'index' location.
    a[index++] = a[n - 1];
    return index;
}