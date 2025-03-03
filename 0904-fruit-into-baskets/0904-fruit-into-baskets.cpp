class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int l = 0,r=0, maxlen = 0;
        map<int,int> mpp;
        int n = arr.size();

        while(r<n){
            mpp[arr[r]]++;
            if(mpp.size() > 2){
                mpp[arr[l]] -- ;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size() <= 2){
                maxlen = r-l+1;
               // r++;
            }
            r++;
        }
        return maxlen;
    }
};