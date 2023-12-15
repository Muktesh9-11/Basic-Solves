
//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U

#include<bits/stdc++.h>
using namespace std;

int fxn(int i,int W,int N,int wt[],int val[]){
    if(i==N) return 0;
    if(W>=wt[i]){
        return max(fxn(i+1,W,N,wt,val),fxn(i+1,W-wt[i],N,wt,val)+val[i]);
    }
    else {
        return fxn(i+1,W,N,wt,val);
    }
}

int main(){
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<fxn(0,w,n,wt,val)<<endl;
}