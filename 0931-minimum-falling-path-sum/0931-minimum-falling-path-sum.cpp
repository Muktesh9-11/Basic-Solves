class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int>dp(n,-1);

        for(int i=0;i<n;i++){
            dp[i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            vector<int> temp(n,-1);
            for(int j=0;j<n;j++){

                if(j==0) temp[j] = min(dp[j], dp[j+1]) + matrix[i][j];
                else if(j==n-1) temp[j] = min(dp[j] , dp[j-1]) + matrix[i][j];
                else temp[j] = min(dp[j] , min(dp[j-1] , dp[j+1])) + matrix[i][j];

            }
            dp = temp;
        }

        int ans = INT_MAX;
        for(auto it : dp){
            ans = min(ans,it);
        }

        return ans;
    }
};