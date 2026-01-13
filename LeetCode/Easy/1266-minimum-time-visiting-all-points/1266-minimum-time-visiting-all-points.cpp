class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int nowi = points[0][0] , nowj = points[0][1];
        int ans = 0;
        for(int i=1;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int gapi = abs(nowi-x);
            int gapj = abs(nowj-y);
            int singles = abs(gapi-gapj);
            ans += (singles + min(gapi,gapj));
            nowi = x;
            nowj = y;
        }

        return ans;
    }
};