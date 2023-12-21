
// 131. Palindrome Partitioning

//https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:

    vector<vector<string>>answer;
    vector<string>current;

    bool ispalindrome(string &s,int left,int right){
        for(int i=left;i<=right;i++){
            if(s[i]!=s[right-(i-left)]) return false;
        }
            return true;
    }

    void backtrack(string &s,int index,vector<string> &palindrome){
        if(index==s.size()){
            answer.push_back(palindrome);
            return;
        }

        string temp="";

        for(int i=index;i<s.size();i++){
           temp+=s[i];

           if(ispalindrome(s,index,i)) {
               palindrome.push_back(temp);
               backtrack(s,i+1,palindrome);
               palindrome.pop_back();
           }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s,0,current);
        return answer;
    }
};