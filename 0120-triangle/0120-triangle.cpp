class Solution {
public:
    int ans = INT_MAX;
    int solve(vector<vector<int>>triangle , int h, int i, int j,int sum,vector<vector<int>>&dp){
        if(i>=h || j>i){
            return INT_MAX;
        }

        if(i==h-1){
            return triangle[i][j];
        }

        //sum+= triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(triangle,h,i+1,j,sum,dp);
        int diag = solve(triangle,h,i+1,j+1,sum,dp);

        dp[i][j] = min(down, diag) + triangle[i][j];

        return dp[i][j];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();

        vector<vector<int>>dp(h,vector<int>(h,-1));

        //return solve(triangle,h,0,0,0,dp);
        //return ans;

        for(int i=0;i<h;i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0){
                    dp[i][j] = triangle[i][j];
                    continue;
                }

                if(j==0) dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j==i) dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else dp[i][j] = min( dp[i-1][j], dp[i-1][j-1] ) + triangle[i][j];

            }
        }

        for(auto it : dp[h-1]){
            ans = min(ans,it);
        }

        return ans;

    }
};