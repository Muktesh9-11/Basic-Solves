class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n-2,vector<int>(m-2,0));

        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int maxval = INT_MIN;
                int x = i+1;
                int y = j+1;
                for(int i1 = x-1;i1<=x+1;i1++){
                    for(int j1=y-1;j1<=y+1;j1++){
                        maxval = max(maxval, grid[i1][j1]);
                    }
                }

                ans[i][j] = maxval;
            }
        }

        return ans;
    }
};