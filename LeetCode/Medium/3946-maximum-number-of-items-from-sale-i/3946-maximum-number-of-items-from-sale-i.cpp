class Solution {
public:

    int n;
    vector<vector<int>> itms;

    int solve(vector<int>& facs, int idx, int cost, int used, vector<vector<vector<int>>> & dp){
        if(idx == n){
            return 0;
        }

        if(dp[idx][cost][used] != -1) return dp[idx][cost][used];

        int notpick = solve(facs, idx+1, cost, 0, dp);

        int pick = 0;
        if(itms[idx][1] <= cost){
            if(used == 0) pick = facs[idx]+1 + solve(facs, idx, cost-itms[idx][1], 1, dp);
            else pick = 1 + solve(facs, idx, cost-itms[idx][1], 1, dp);
        }

        return dp[idx][cost][used] = max(notpick, pick);

    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        itms = items;

        vector<int>facs(n,0);
        for(int i=0;i<items.size();i++){
            for(int j=0;j<items.size();j++){
                if(i!=j && items[j][0]%items[i][0]==0)facs[i]++;
            }
        }

        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(budget+1, vector<int>(2,-1)));
        static int dp[1001][1501][2];
        // dp -> dp[index][budget][used] = no. of copies
        for(int b = 0; b <= budget; b++){
            dp[n][b][0] = 0;
            dp[n][b][1] = 0;
        }

        int bdj = budget;

        for(int i = n - 1; i >= 0; i--){
            for(int bdj = 0; bdj <= budget; bdj++) {
                for(int used = 0; used < 2; used++) {
                    int notpick = dp[i + 1][bdj][0];

                    int pick = 0;

                    if(bdj >= items[i][1]) {
                        if(used == 0) {
                            pick = facs[i] + 1 + dp[i][bdj - items[i][1]][1];
                        }
                        else {
                            pick = 1 + dp[i][bdj - items[i][1]][1];
                        }
                    }

                    dp[i][bdj][used] = max(notpick, pick);
                }
            }
        }

        //return solve(facs, 0, budget, 0, dp);
        return dp[0][bdj][0];

    }
};