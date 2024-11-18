class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        map<pair<int,int>,int> mpp;
        queue<pair<int,int>> q;

        int cntor = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) cntor++;
                mpp[{i,j}]=0;
            }
        }

        int cnt=0;
        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
        for(int t=0;t<sz;t++){
            pair<int,int> pr = q.front();
            q.pop();
            int i = pr.first;
            int j = pr.second;
            if(i+1<m && grid[i+1][j]==1){
                q.push({i+1,j});
                grid[i+1][j]=2;
                flag++;
                cntor--;
            }
            if(j+1<n && grid[i][j+1]==1){
                q.push({i,j+1});
                grid[i][j+1]=2;
                flag++;
                cntor--;
            }
            if(i-1>=0 && grid[i-1][j]==1){
                q.push({i-1,j});
                grid[i-1][j]=2;
                flag++;
                cntor--;
            }
            if(j-1>=0 && grid[i][j-1]==1){
                q.push({i,j-1});
                grid[i][j-1]=2;
                flag++;
                cntor--;
            }
        }
        if(flag!=0) cnt++;
        }

        if(cntor>0) return -1;
        return cnt;
    }
};