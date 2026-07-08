class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;
        int n = s.size();

        vector<int> nonZeroCount(n + 1, 0);

        vector<int> digits;

        for (int i = 0; i < n; i++) {
            nonZeroCount[i + 1] = nonZeroCount[i];

            if (s[i] != '0') {
                nonZeroCount[i + 1]++;
                digits.push_back(s[i] - '0');
            }
        }

        int k = digits.size();

        vector<long long> prefixValue(k + 1, 0);

        vector<long long> prefixSum(k + 1, 0);

        vector<long long> power10(k + 1, 1);

        for (int i = 0; i < k; i++) {
            prefixValue[i + 1] = (prefixValue[i] * 10 + digits[i]) % MOD;

            prefixSum[i + 1] = prefixSum[i] + digits[i];

            power10[i + 1] = (power10[i] * 10) % MOD;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];

            int left = nonZeroCount[l];

            int right = nonZeroCount[r + 1];

            int len = right - left;

            long long x = (
                prefixValue[right]
                - (prefixValue[left] * power10[len]) % MOD
                + MOD
            ) % MOD;

            long long sum = prefixSum[right] - prefixSum[left];

            answer.push_back((int)((x * sum) % MOD));
        }

        return answer;
    }
};