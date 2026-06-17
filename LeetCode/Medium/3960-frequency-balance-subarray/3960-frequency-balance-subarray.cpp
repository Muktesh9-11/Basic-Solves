class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int,int> cnt;
            unordered_map<int,int> freq;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                int old = cnt[x];

                if (old) {
                    if (--freq[old] == 0)
                        freq.erase(old);
                }

                cnt[x]++;
                freq[old + 1]++;

                bool ok = false;

                if (cnt.size() == 1) {
                    ok = true;
                }
                else if (freq.size() == 2) {
                    auto it = freq.begin();

                    int a = it->first;
                    ++it;
                    int b = it->first;

                    if (min(a, b) * 2 == max(a, b))
                        ok = true;
                }

                if (ok)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};