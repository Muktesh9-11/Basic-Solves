#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0){
    int a,b,x;
    cin>>a>>b;
    x=a&b;
    cout<<(a^x)+(b^x)<<endl;
    }
}