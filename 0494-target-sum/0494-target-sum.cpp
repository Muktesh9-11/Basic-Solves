class Solution {
public:
    int n;
    int total;
    //int fix;
    int solve(vector<int>arr,int i,int target, vector<vector<int>>&dp){
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }

        if(dp[i][target] != -1) return dp[i][target];

        int notadd = solve(arr,i+1,target,dp);
        int add = 0;
        if(arr[i]<=target) add = solve(arr,i+1,target-arr[i],dp);

        return dp[i][target] = add+notadd;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(),nums.end(),0);
        if (total - target < 0)
        return 0; // Not possible to achieve the target sum
    if ((total - target) % 2 == 1)
        return 0;

        vector<vector<int>>dp(n,vector<int>((total - target) / 2+1,-1));

        return solve(nums,0,(total-target)/2,dp);
    }
};