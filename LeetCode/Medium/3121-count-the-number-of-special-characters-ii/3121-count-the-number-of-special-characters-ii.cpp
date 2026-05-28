class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,INT_MAX);
        vector<int> upper(26,-1);
        int n = word.size();
        for(int i=0;i<n;i++){
            char c = word[i];
            if(c>='a' && c<='z'){
                lower[c-'a'] = i;
            }
            else{
                if(upper[c-'A'] == -1) upper[c-'A'] = i;
            }
        }

        int ans = 0;
        for(int i=0;i<26;i++){
            if(lower[i] < upper[i]) ans++;
        }

        return ans;
    }
};