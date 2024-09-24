class Solution {
public:

    vector<string> arr;

    void solve(string s,int left,int right){
        if(left==0 && right==0){
            arr.push_back(s);
            //return;
        }
        if(left>0) {
            solve(s+'(',left-1,right);
        }
        //left++;
        if(right>left){
            solve(s+')',left,right-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("",n,n);
        return arr;

    }
};