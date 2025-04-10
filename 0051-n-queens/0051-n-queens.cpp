class Solution {
public:

    vector<vector<string>> ans;

    bool check(vector<string>curr,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(curr[i][col] == 'Q') return false;
        }
        int i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(curr[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i=row-1;
        j = col+1;
        while(i>=0 && j<n){
            if(curr[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;

    }

    void solve(vector<string>curr,int row,int n){
        if(row==n){
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<n;i++){
            if(check(curr,row,i,n)){
                curr[row][i] = 'Q';
                solve(curr,row+1,n);
                curr[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string dots = "";
        for(int i=0;i<n;i++){
            dots+='.';
        }
        vector<string>curr(n,dots);

        solve(curr,0,n);

        return ans;

    }
};