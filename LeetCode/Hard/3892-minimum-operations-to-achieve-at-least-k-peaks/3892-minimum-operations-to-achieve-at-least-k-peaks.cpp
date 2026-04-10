#define ll long long
class Solution {
public:
    int n;
    ll INF = 1e18;

    ll solve(int i, int end, int j, int k, vector<int>& cost,
             vector<vector<ll>>& dp) {
        
        if (j == k) return 0;
        if (i > end) return INF;

        if (dp[i][j] != -1) return dp[i][j];

        // Skip current
        ll skip = solve(i + 1, end, j, k, cost, dp);

        // Take current
        ll take = INF;
        if (j + 1 <= k) {
            take = cost[i] + solve(i + 2, end, j + 1, k, cost, dp);
        }

        return dp[i][j] = min(skip, take);
    }

    ll eval(vector<int>& nums, int start, int end, int k, vector<int>& cost) {
        int n = nums.size();
        vector<vector<ll>> dp(n + 2, vector<ll>(k + 1, -1));

        return solve(start, end, 0, k, cost, dp);
    }

    int minOperations(vector<int>& nums, int k) {
        n = nums.size();
        if (k > n / 2) return -1;
        if (k == 0) return 0;
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;

        vector<int> cost(n);
        for(int i=0;i<n;i++){
            int left = nums[(i-1+n) % n];
            int right = nums[(i + 1) % n];
            cost[i] = max(0, (max(left, right) + 1 - nums[i]));
        }

        ll ans = INF;

        ans = min(ans, eval(nums, 1, n - 1, k, cost));

        if (k >= 1) {
            ll val = cost[0] + eval(nums, 2, n - 2, k - 1, cost);
            ans = min(ans, val);
        }

        return ans >= INF ? -1 : ans;

    }
};