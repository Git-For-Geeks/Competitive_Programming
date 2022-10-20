#include <iostream>
using namespace std;

int findSingleNumber(int arrayElements[], int length)
{
    int res = arrayElements[0];
    for (int i = 1; i < length; i++)
        res = res ^ arrayElements[i];
    return res;
}

int main(){
    int a[] = {2, 3, 5, 4, 5, 3, 4};
    int n = 7;
    cout << findSingleNumber(a,n);
    return 0;
}