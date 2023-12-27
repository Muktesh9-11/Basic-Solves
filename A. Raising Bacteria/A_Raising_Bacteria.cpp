#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    int count=0;
    cin>>x;
    for(int i=0;i<32;i++){
        if((x&1<<i)>0) count++;
    }
    cout<<count;
}