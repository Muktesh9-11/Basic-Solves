#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;

#define mod (ll) (1e9+7)
typedef long long ll;

ll power(ll n,ll k){
    if(k==0) return 1;
    ll answer=power(n,k-1);
    answer%=mod;
    answer*=n;
    answer%=mod;
    //ll x=1e9+7;
    return answer;
}
int main(){
    int t;
    cin>>t;
    while(t-->0){
    
    ll n,k;
    cin>>n>>k;
    cout<<power(n,k)<<endl;


    }
}