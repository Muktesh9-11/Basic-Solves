#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<ll> hor(n,0);
        vector<ll> ver(m,0);

        ll temp = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp += (ll)grid[i][j];
            }
            hor[i] = temp;
        }

        temp = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp += (ll)grid[j][i];
            }
            ver[i] = temp;
        }

        for(int i=0;i<n;i++){
            if(hor[i] == (hor[n-1] - hor[i])){
                return true;
            }
        }
        for(int i=0;i<m;i++){
            if(ver[i] == (ver[m-1] - ver[i])){
                return true;
            }
        }

        return false;
    }
};