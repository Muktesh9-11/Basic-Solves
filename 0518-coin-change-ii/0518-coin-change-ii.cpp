#define ll long long 
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
        //vector<vector<ll>>dp(n+1,vector<ll>(amount+1,0));

        vector<int> prev(amount+1,0), curr(amount+1,0);

        for(int j=0;j<=amount;j++) prev[j] = (j%coins[0] == 0); 

        //return solve(coins,amount,0,dp);
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                ll notpick = prev[j];
                ll pick = 0;
                if(coins[i] <= j){
                    pick = curr[j-coins[i]];
                }

                curr[j] = pick+notpick;
            }
            prev=curr;
        }

        return prev[amount];

    }
};