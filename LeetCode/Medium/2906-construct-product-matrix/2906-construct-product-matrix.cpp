#define ll long long
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n,vector<int>(m));
        vector<ll> suf(n*m,1);
        vector<ll> pref(n*m,1);

        if(n*m == 1){
            return {{1}};
        }
        
        pref[0] = grid[0][0];
        suf[n*m-1] = grid[n-1][m-1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx = i*m+j;
                if(idx>0) pref[idx] = (pref[idx-1] * grid[i][j])%12345;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int idx = i*m+j;
                if(idx < n*m-1) suf[idx] = (suf[idx+1] * grid[i][j])%12345;
            }
        }

        p[0][0] = suf[1] % 12345;
        p[n-1][m-1] = pref[n*m-2] % 12345;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx = i*m+j;
                if((idx>0) && (idx<n*m-1)) p[i][j] = (pref[idx-1] * suf[idx+1]) % 12345;
            }
        } 

        return p;
    }
};