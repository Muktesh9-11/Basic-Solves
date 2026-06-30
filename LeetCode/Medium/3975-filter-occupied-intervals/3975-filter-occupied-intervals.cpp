class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intr, int fs, int fe) {
        int n = intr.size();
        vector<vector<int>> ans;

        sort(intr.begin(), intr.end());

        ans.push_back(intr[0]);

        // Merge intervals
        for(int i = 1; i < n; i++) {
            int currst = intr[i][0];
            int currend = intr[i][1];

            int now = ans.size() - 1;

            if(currst <= ans[now][1] + 1) {
                ans[now][1] = max(ans[now][1], currend);
            }
            else {
                ans.push_back({currst, currend});
            }
        }

        // Remove free interval
        for(int i = 0; i < ans.size(); i++) {
            int st = ans[i][0];
            int end = ans[i][1];

            // Completely inside free interval
            if(st >= fs && end <= fe) {
                ans.erase(ans.begin() + i);
                i--;
            }

            // Free interval splits occupied interval into two parts
            else if(st < fs && end > fe) {
                ans[i][1] = fs - 1;
                ans.insert(ans.begin() + i + 1, {fe + 1, end});
                i++; // skip newly inserted interval
            }

            // Right part removed
            else if(st < fs && end >= fs && end <= fe) {
                ans[i][1] = fs - 1;
            }

            // Left part removed
            else if(st >= fs && st <= fe && end > fe) {
                ans[i][0] = fe + 1;
            }
        }

        return ans;
    }
};