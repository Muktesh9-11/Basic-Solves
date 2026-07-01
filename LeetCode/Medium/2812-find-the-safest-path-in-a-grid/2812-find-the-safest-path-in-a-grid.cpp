class Solution {
public:

    int n;

    vector<pair<int,int>> move = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>>mdist;

    bool check(vector<vector<int>>& grid, int i, int j, int dist, vector<vector<int>> & vis){

        if(vis[i][j]) return false;

        if(mdist[i][j] < dist) return false;

        if(i == n-1 && j == n-1){
            return true;
        }

        vis[i][j] = 1;

        for(auto &it : move){
            int x = i + it.first;
            int y = j + it.second;

            if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && mdist[x][y] >= dist){
                if(check(grid, x, y, dist, vis)){
                    return true;
                }
            }
        }

        return false;
        
    }

    int bs(vector<vector<int>>& grid, int low, int high){
        if(low > high) return high;

        int mid = low + (high- low)/2;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        if(check(grid, 0, 0, mid, vis)){
            return bs(grid, mid+1, high);
        }
        else{
            return bs(grid, low, mid-1);
        }
        
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        mdist.resize(n, vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    mdist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto &[dx,dy] : move){
                int nx = x + dx;
                int ny = y + dy;

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if(mdist[nx][ny] > mdist[x][y] + 1){
                    mdist[nx][ny] = mdist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        //for(int i=0;i<n;i++){
        //    for(int j=0;j<n;j++){
        //        if(grid[i][j] == 1){
        //            mdist[i][j] = 0;
        //            continue;
        //        }
        //        else{
        //            for(auto & it : thieves){
        //                int dist = abs(i - it.first) + abs(j - it.second);
        //                mdist[i][j] = min(mdist[i][j], dist);
        //            }
        //        }
        //    }
        //}

        return bs(grid, 0, 2*n);
    }
};