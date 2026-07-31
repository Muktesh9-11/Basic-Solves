class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int st= intervals[0][0] , end = intervals[0][1];
        vector<vector<int>> ans;
        ans.push_back({st,end});

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= end && intervals[i][1] > end){
                end = intervals[i][1];
                int sz = ans.size();
                ans[sz-1][1] = end;
                continue;
            }
            if(intervals[i][0] > end){
                st = intervals[i][0];
                end = intervals[i][1];

                ans.push_back({st,end});
            }

        }

        return ans;

    }
};