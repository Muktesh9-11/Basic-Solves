class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> lmaxval(n);
        lmaxval[0] = nums[0];
        vector<int> rmaxval(n);
        rmaxval[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            lmaxval[i] = max(lmaxval[i-1], nums[i]);
            rmaxval[n-i-1] = max(rmaxval[n-i], nums[n-i-1]); 
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int left = i-k<0 ? INT_MIN : lmaxval[i-k];
            int right = i+k>=n ? INT_MIN : rmaxval[i+k];

            ans = max(ans, nums[i]+max(left,right));
        }

        return ans;
    }
};