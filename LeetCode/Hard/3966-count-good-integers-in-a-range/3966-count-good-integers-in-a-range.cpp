#define ll long long

class Solution {
public:

    ll dp[17][2][11][2];
    // dp[idx][tight][prev][started]
    ll K;

    ll solve(string &s, int idx, int tight, int prev, int started) {
        if (idx == s.size()) return started;

        if (!tight && dp[idx][tight][prev][started] != -1)
            return dp[idx][tight][prev][started];

        ll digit = s[idx] - '0';

        ll llimit = 0;
        ll rlimit = (tight ? digit : 9);

        ll ans = 0;

        for (int i = llimit; i <= rlimit; i++) {

            if (!started && i == 0) {
                ans += solve(
                    s,
                    idx + 1,
                    tight && (i == digit),
                    10,
                    0
                );
            }
            else {
                if (prev == 10 || abs(prev - i) <= K) {
                    ans += solve(
                        s,
                        idx + 1,
                        tight && (i == digit),
                        i,
                        1
                    );
                }
            }
        }

        if (!tight)
            dp[idx][tight][prev][started] = ans;

        return ans;
    }

    ll countGood(ll x) {
        if (x < 0) return 0;

        string s = to_string(x);

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 1, 10, 0);
    }

    long long goodIntegers(long long l, long long r, int k) {
        K = k;

        return countGood(r) - countGood(l - 1);
    }
};