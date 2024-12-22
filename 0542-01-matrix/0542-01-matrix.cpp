#include <vector>
#include <queue>
#include <limits.h>

class Solution {
public:
    vector<pair<int,int>> travel = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> grid(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the grid and queue with zeros
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Perform BFS
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto it : travel) {
                int x = i + it.first;
                int y = j + it.second;

                if(x >= 0 && x < m && y >= 0 && y < n) {
                    if(grid[x][y] > grid[i][j] + 1) {
                        grid[x][y] = grid[i][j] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return grid;
    }
};
