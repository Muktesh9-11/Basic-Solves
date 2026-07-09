class Solution {
public:

    int n;

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        n = n;
        vector<bool> ans;

        int grp = 1;
        unordered_map<int,int> mpp;
        mpp[0] = grp;
        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                mpp[i] = grp;
            }
            else{
                grp++;
                mpp[i] = grp;
            }
        }

        for(auto & it : queries){
            int ui = it[0];
            int vi = it[1];

            if(mpp[ui] == mpp[vi]){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};