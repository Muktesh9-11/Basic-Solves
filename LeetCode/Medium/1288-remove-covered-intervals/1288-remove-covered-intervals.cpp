class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        vector<int> rem(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                auto & it1 = intervals[i];
                auto & it2 = intervals[j];
                int l1 = it1[0], r1 = it1[1];
                int l2 = it2[0], r2 = it2[1];

                if(l1<=l2 && r1>=r2) rem[j]++;
                if(l2<=l1 && r2>=r1) rem[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(rem[i] == 0) ans++;
        }

        return ans;
    }
};