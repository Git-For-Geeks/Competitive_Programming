#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l,temp;
    l=s.length();
    for(int i=0;i<l;i+=2){
        for(int j=0;j<l-i-2;j+=2){
                 if(s[j]>s[j+2]){
                        temp = s[j];
                        s[j] = s[j+2];
                        s[j+2] = temp;
 
                }
        }
 
    }
    cout<<s;
   return 0;
 
}
