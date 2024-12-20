class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int temp = image[sr][sc];
        image[sr][sc] = color;

        queue<pair<int,int>> q;
        map<pair<int,int>,int> vis;
        q.push({sr,sc});
        //vis[{sr,sc}] = 1;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> pr = q.front();
                int r = pr.first;
                int c = pr.second;
                q.pop();
                if(image[r][c]==color && !vis[{r,c}]){
                    if(r+1<m && image[r+1][c]==temp){
                        image[r+1][c] = color;
                        q.push({r+1,c});
                    }
                    if(r-1>=0 && image[r-1][c]==temp){
                        image[r-1][c] = color;
                        q.push({r-1,c});
                    }
                    if(c+1<n && image[r][c+1]==temp){
                        image[r][c+1]=color;
                        q.push({r,c+1});
                    }
                    if(c-1>=0 && image[r][c-1]==temp){
                        image[r][c-1]=color;
                        q.push({r,c-1});
                    }
                    vis[{r,c}] = 1;
                }
            }
        }
        return image;
    }
};