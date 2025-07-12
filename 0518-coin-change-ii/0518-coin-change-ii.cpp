class Solution {
public:
    int n;

    int solve(vector<int>coins,int amount, int i,vector<vector<int>>&dp){
        if(i==n){
            if(amount == 0) return 1;
            return 0;
        }
        if(amount<0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int notpick = solve(coins,amount,i+1,dp);
        int pick = 0;
        if(coins[i] <= amount){
            pick = solve(coins,amount-coins[i],i,dp);
        }

        return dp[i][amount] = pick+notpick;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(coins,amount,0,dp);
    }
};