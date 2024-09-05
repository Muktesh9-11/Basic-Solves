class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        if(s.size()==1) return 1;
        vector<int> mpp(256,-1); // no. of characters =256 -> 2^8;
        int ctr=0;
        int l=0,r=0;
        
        while(r<s.size()){
            if(mpp[s[r]] != -1) {
                l = max( mpp[s[r]]+1 , l);
            }
            mpp[s[r]]=r;

            ctr= max(ctr,r-l+1);
            r++;
        }
        return ctr;
    }
};