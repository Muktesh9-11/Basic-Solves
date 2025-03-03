class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0;
        map<char,int> mpp;
        int temp = 0;
        int count = 0;
        int fix = 0;
        int n = s.size();

        while(r<n){
            mpp[s[r]] ++ ;
            if(mpp[s[r]] >= count){
                //fix = r;
                count = max(count,mpp[s[r]]);
            }
            //if(s[r] != s[fix]) temp ++;
            if(((r-l+1) - count) > k){
                //if(s[l]!=s[fix])temp--;
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if(temp <= k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};