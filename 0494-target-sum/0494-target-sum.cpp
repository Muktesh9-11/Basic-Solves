class Solution {
public:
    int n;
    int total;
    //int fix;
    int solve(vector<int>arr,int i,int target, vector<vector<int>>&dp,int sum){
        if(i == n){
            if(sum == target) return 1;
            return 0;
        }

        if(dp[i][total+sum] != -1) return dp[i][total+sum];

        int add = solve(arr,i+1,target,dp,sum+arr[i]);
        int sub = solve(arr,i+1,target,dp, sum-arr[i]);

        return dp[i][total+sum] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(2*total+1,-1));

        return solve(nums,0,target,dp,0);
    }
};