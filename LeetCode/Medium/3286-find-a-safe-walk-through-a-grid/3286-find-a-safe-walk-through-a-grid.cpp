class Solution {
public:

    vector<pair<int,int>> move = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m,n;

    bool solve(vector<vector<int>>& grid, int health, int i, int j, vector<vector<int>>& vis){
        if(i==m-1 && j == n-1){
            if(health >= 1) return true;
        }

        if(vis[i][j] >= health) return false;
        vis[i][j] = health;
        
        bool path = false;
        for(auto [x,y] : move){
            int xi = i+x;
            int yi = y+j;

            if(xi>=0 && xi<m && yi>=0 && yi<n){
                if(grid[xi][yi] == 1){
                    if(health>1) path |= solve(grid, health-1, xi, yi, vis);
                } 
                else{
                    path |= solve(grid, health, xi, yi, vis);
                }
            }
        }

        return path;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        if(grid[0][0] == 1) health--;
        return solve(grid, health, 0, 0, vis);

    }
};