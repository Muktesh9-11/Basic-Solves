class Solution {
public:

    bool check(int i, int j, vector<vector<int>>&grid){
        int row1=0,row2=0,row3=0;
        int col1=0,col2=0,col3=0;
        int di1=0,di2=0;
        vector<int> vis(10,0);
        //memset(grid, 0, sizeof(grid));
        for(int i1=i;i1<i+3;i1++){
            for(int j1=j;j1<j+3;j1++){
                int num = grid[i1][j1]; 
                if(num>9 || num<1 || vis[num]){
                    return false;
                }
                else{
                    vis[num] = 1;
                }
            }
        }
        row1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        row2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
        row3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]; 

        col1 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
        col2 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
        col3 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];

        di1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        di2 = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

        if(row1==15 && row2==15 && row3==15 && col1==15 && col2==15 && col3==15 && di1==15 && di2==15){
            return true;
        }
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n<3 || m<3) return 0;

        int ans = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(check(i,j,grid)){
                    ans++;
                }
            }
        }

        return ans;
    }
};