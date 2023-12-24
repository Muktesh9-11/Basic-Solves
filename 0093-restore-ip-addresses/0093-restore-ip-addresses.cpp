class Solution {
public:
    
    vector<string> answer; 

    bool check(string s){
        //stoi returns sub string after removing leading zeros
        int number=stoi(s);
        string actualString = to_string(number);
        return (s==actualString && number<=255);
    }

    void backtrack(int n,int index,int parts,string &s,string current){
        if(index==n || parts==4){
            current.pop_back();
            if(index==n && parts==4) answer.push_back(current);
            return;
        }

        for(int len=1;len<=3;len++){
            if(check(s.substr(index,len)) && index+len<=n){
                backtrack(n,index+len,parts+1,s,current+s.substr(index,len)+".");
                //backtrack(s,n,parts,i++,current+=s[i]);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        backtrack(n,0,0,s,"");
        return answer;
    }
};