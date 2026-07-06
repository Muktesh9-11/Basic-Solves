class Solution {
public:

    const int mod = 1000000007;
    int n, m1, m2;

    vector<vector<int>> v1;
    vector<vector<int>> v2;

    int solve(int idx, int j1, int j2, string &w1, string &w2, string &target, vector<vector<vector<int>>> & dp){
        if(idx == n){
            if(j1 > 0 && j2 > 0) return 1;
            return 0;
        }

        if(j1 > m1-1 && j2 > m2-1) return 0;

        if(dp[idx][j1][j2] != -1) return dp[idx][j1][j2];

        int ways = 0;
        char c = target[idx];
        auto it1 = lower_bound(v1[c-'a'].begin(), v1[c-'a'].end(), j1);

        for(; it1 != v1[c-'a'].end(); ++it1){
            int pos = *it1;
            ways = (ways + solve(idx+1, pos+1, j2, w1, w2, target, dp)) % mod;
        }

        auto it2 = lower_bound(v2[c-'a'].begin(), v2[c-'a'].end(), j2);

        for(; it2 != v2[c-'a'].end(); ++it2){
            int pos = *it2;
            ways = (ways + solve(idx+1, j1, pos+1, w1, w2, target, dp)) % mod;
        }

        return dp[idx][j1][j2] = ways;
    }

    int interleaveCharacters(string word1, string word2, string target) {
        n = target.size();
        m1 = word1.size();
        m2 = word2.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m1+1, vector<int>(m2+1,-1)));

        v1.assign(26,{});
        v2.assign(26,{});

        for(int i=0;i<m1; i++){
            char c = word1[i];
            v1[c - 'a'].push_back(i);
        }
        for(int i=0;i<m2; i++){
            char c = word2[i];
            v2[c - 'a'].push_back(i);
        }

        return solve(0, 0, 0, word1, word2, target, dp);
    }
};