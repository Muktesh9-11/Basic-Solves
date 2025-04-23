class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int currZeroCnt = 0, prevZeroCnt = 0, oneCnt = 0, zeroSeg = 0, mxOnes = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') currZeroCnt++;
            else{
                oneCnt++;
                mxOnes = max(mxOnes,(currZeroCnt+prevZeroCnt));
                if(currZeroCnt != 0){
                    prevZeroCnt = currZeroCnt;
                    zeroSeg++;
                }
                currZeroCnt = 0;
            }
        }
        if(currZeroCnt!=0) zeroSeg++;
        mxOnes = max(mxOnes,currZeroCnt+prevZeroCnt);
        return oneCnt + ((zeroSeg>1)? mxOnes : 0);
    }
};