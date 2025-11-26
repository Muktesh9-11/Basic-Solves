class Solution {
public:
    const int mod = 1e9+7;
    long long ans = 0;
    int m,n;

    int solve(vector<vector<int>>&grid, int i, int j, int k, int sum, vector<vector<vector<int>>>&dp){
        sum = (sum + grid[i][j]) % k;

        if(i == m-1 && j == n-1){
            if(sum % k == 0) return 1;
        }

        if(dp[i][j][sum] != -1) return dp[i][j][sum];

        long long ways = 0;
        if(i+1 < m){
            ways = (ways + solve(grid,i+1,j,k,sum,dp));
        }
        if(j+1 < n){
            ways = (ways + solve(grid,i,j+1,k,sum,dp));
        }

        return dp[i][j][sum] = ways%mod;

    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1))
        );
        //int sum = grid[0][0];
        return solve(grid, 0, 0, k, 0, dp);

        
    }
};