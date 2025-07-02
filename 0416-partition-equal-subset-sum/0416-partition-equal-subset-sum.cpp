class Solution {
public:

    bool solve(vector<int>nums, int n, int i, int target, vector<vector<int>> &dp){
        if(target == 0) return true;

        if(target < 0 || i>=n) return false;

        if (dp[i][target] != -1) return dp[i][target];
        int temp = target - nums[i];
        return solve(nums,n,i+1, temp,dp) || solve(nums,n, i+1, target,dp);
 
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums) sum += x;

        if(sum%2 != 0 ) return false;

        int target = sum/2;

        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        //return solve(nums,n,0,target,dp);
        dp[0][0] = true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                if(j==0) {
                    dp[i][j] = true;
                    continue;
                }
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = dp[i-1][j-nums[i]];
                }

                dp[i][j] = notTake || take;
            }
        }

        return dp[n-1][target];

    }
};