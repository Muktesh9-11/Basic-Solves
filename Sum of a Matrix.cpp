
//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/N

#include<bits/stdc++.h>
using namespace std;
void func(int i,int j,int r,int c,vector<vector<int> > &m1,vector<vector<int> > &m2){
    if(i>=r) return;

    if(j==c-1){
        cout<<m1[i][j]+m2[i][j]<<endl;
        func(i+1,0,r,c,m1,m2);
        return;
    }
    cout<<m1[i][j]+m2[i][j]<<" ";
    func(i,j+1,r,c,m1,m2);
    
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int> >m1(r,vector<int>(c)),m2(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m1[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m2[i][j];
        }
    }
    func(0,0,r,c,m1,m2);
}