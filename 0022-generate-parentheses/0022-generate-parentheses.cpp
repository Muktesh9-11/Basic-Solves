class Solution {
public:

    vector<string>answer;

    void backtrack(int o,int c,string current){
        if(o==0 && c==0){
            answer.push_back(current);
            return;
        }

        if(o>0) backtrack(o-1,c,current+"(");

        if(c>o){
            backtrack(o,c-1,current+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        
        backtrack(n,n,"");
        return answer;
    }
};