class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();
        //function for counting gain across all indices such that gain>=x
        auto countTerms = [&](long long x) {
            long long cnt = 0;

            for (int i = 0; i < n; i++) {
                if (value[i] < x) continue;

                cnt += (value[i] - x) / (long long)decay[i] + 1;
                if (cnt >= m) return cnt;
            }

            return cnt;
        };

        long long lo = 1, hi = 1e9, threshold = 0;
        //binary search on threshold
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (countTerms(mid) >= m) {
                threshold = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        long long sum = 0;
        long long used = 0;
        //adding values > threshold to the answer
        for (int i = 0; i < n; i++) {
            long long a = value[i];
            long long d = decay[i];

            if (a <= threshold) continue;
            long long cnt = (a - (threshold + 1)) / d + 1;

            used += cnt;

            long long last = a - (cnt - 1) * d;

            // arithmetic series sum
            sum += cnt * (a + last) / 2;
        }

        //filling remaining with values = threshold
        long long remaining = m - used;
        sum += remaining * threshold;

        return (int)(sum % MOD);
    }
};