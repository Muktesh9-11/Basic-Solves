class Solution {
public:

    int n;
    void solve(vector<int>&nums, vector<int>&dp, int i){
        if(i>=n){
            return;
        }


        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        solve(nums,dp,i+1);

    }

    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n,0);
        if(n==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        solve(nums,dp,2);

        return dp[n-1];
    }
};