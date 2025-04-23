class Solution {
public:
    vector<pair<int,int>> side = {{-1,0},{0,1},{0,-1},{1,0}};
    int ans;
    int rows,cols;
    void solve(vector<vector<int>>& heights){

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

        pq.push({0,0,0});

        while(!pq.empty()){
            auto [wt,i,j] = pq.top();
            pq.pop();

            if(i==(rows-1) && j == (cols-1)){
                ans = wt;
                return;
            }

            for(auto it : side){
                int x = i+it.first;
                int y = j+it.second;
                if(x>=0 && x<rows && y>=0 && y<cols){
                    int fix = max(wt,abs(heights[x][y] - heights[i][j]));
                    if(fix<dist[x][y]){
                        dist[x][y] = fix;
                        pq.push({fix,x,y});
                    }
                }
            }
        }


    }


    int minimumEffortPath(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        //int fix = 0;
        //map<pair<int,int>,int> vis;
        //vis[{0,0}] = 1;
        solve(heights);
        return ans;
        
    }
};