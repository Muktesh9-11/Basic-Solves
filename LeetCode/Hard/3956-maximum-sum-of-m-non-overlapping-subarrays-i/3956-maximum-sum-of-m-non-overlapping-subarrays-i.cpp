class Solution {
public:
    long long NEG = -4e18;

    long long maximumSum(vector<int>& nums, int m, int l, int r) {

        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for(int i=0;i<n;i++) {
            pref[i+1] = pref[i]+nums[i];
        }

        vector<vector<long long>> dp(m+1,vector<long long>(n+1, NEG));
        //base case
        for(int i=0;i<=n;i++) {
            dp[0][i] = 0;
        }

        long long ans = NEG;

        for(int t=1;t<=m;t++) {

            deque<int> dq;

            for(int i=1;i<=n;i++) {

                //skip i-th position
                dp[t][i] = dp[t][i-1];
                int pos = i-l; // new element entering the window

                if(pos >= 0) {

                    long long val = dp[t - 1][pos] - pref[pos];
                //new value > value at back of deque, remove the last value
                //new value < value at back, directly add the new value
                    while(!dq.empty()) {
                        int last = dq.back(); 
                        if(dp[t - 1][last] - pref[last] >= val)
                            break;

                        dq.pop_back();
                    }

                    dq.push_back(pos);
                }
                //removing the element leaving the window
                while(!dq.empty() && dq.front()<i-r) {
                    dq.pop_front();
                }

                if(!dq.empty()) {
                    int start = dq.front();
                
                    long long candidate = dp[t - 1][start]- pref[start]+ pref[i];
                    dp[t][i] =max(dp[t][i], candidate);
                }
            }

            ans = max(ans, dp[t][n]);
        }

        return ans;
    }
};