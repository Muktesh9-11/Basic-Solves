class Solution {
public:
int rev(int n){
        int rev = 0;
        while(n!=0){
            rev*=10;
            rev+= n%10;
            n/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int rnum = rev(nums[i]);
            if(mpp.find(nums[i]) != mpp.end()){
                ans = min(ans,abs(i-mpp[nums[i]]));
            }
            mpp[rnum] = i;
        }
        if(ans == INT_MAX) return -1;

        return ans;
    }
};