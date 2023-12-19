
//https://cses.fi/problemset/task/1622

#include<bits/stdc++.h>
using namespace std;

vector<string>allstrings;
void fxn(int idx,int sz,vector<int> &hash,string ans){
    if(idx==sz){
        allstrings.push_back(ans);
        return;
    }

    for(int i=0;i<26;i++){
        if(hash[i]>0){
         hash[i]--;
         fxn(idx+1,sz,hash,ans+char(i+'a'));
         hash[i]++;
        }
    }
}

int main(){
   string s;
   cin>>s;
   vector<int>hash(26);
   for(auto it : s){
    hash[it-'a']++;
   }
   fxn(0,s.size(),hash,"");
   cout<<allstrings.size()<<endl;
   for(int i=0;i<allstrings.size();i++){
    cout<<allstrings[i]<<endl;
}
}

