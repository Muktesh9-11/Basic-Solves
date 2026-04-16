#define pb push_back
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> ans(q);

        unordered_map<int,set<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].insert(i);
        }

        for(int i=0;i<q;i++){
            int qidx = queries[i];
            int val = nums[qidx];
            if(mpp[val].size() == 1) {
                ans[i] = -1;
                continue;
            }

            auto it = mpp[val].find(qidx);
            int nextidx;
            auto nxt = next(it);
            if(nxt != mpp[val].end()){
                nextidx = *nxt;
            }
            else nextidx = *mpp[val].begin();

            int previdx;
            if(it != mpp[val].begin()){
                auto prv = prev(it);
                previdx = *prv;
            }
            else previdx = *prev(mpp[val].end());

            int nextgap = min(abs(qidx - nextidx), n-abs(qidx-nextidx));

            int prevgap = min(abs(qidx - previdx), n-abs(qidx-previdx));

            ans[i] = min(nextgap, prevgap);

        }

        return ans;
    }
};