class Solution {
public:

    vector<pair<int,int>> adds = {{1,1},{1,0},{0,1},{-1,1},{1,-1},{-1,0},{0,-1},{-1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid.size() ==1 && grid[0][0] == 0) return 1;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        map<pair<int,int>,int> vis;
        pair<int,int> src = {0,0};
        queue<pair<int,int>> q;
        q.push(src);
        vis[{0,0}] = 1;
        int count =0;
        //int ans = INT_MAX;
        while(!q.empty()){
            int sz = q.size();
            count++;
            for(int i =0;i<sz;i++){
                pair<int,int> node = q.front();
                q.pop();
                for(int i=0;i<adds.size();i++){
                    int x = adds[i].first + node.first;
                    int y = adds[i].second + node.second;
                    if(x>=0 && x<n && y>=0 && y<n){
                        if(x==(n-1) && y==(n-1)){
                            return count+1;
                        }
                        else if(grid[x][y] == 0){
                            if(!vis[{x,y}]){
                                q.push({x,y});
                                vis[{x,y}] = 1;
                            }
                        }
                    } 
                }
            }
        }
        return -1;

    }
};