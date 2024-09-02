class Solution {
public:

    int check(vector<vector<int>>& mat,int n,int m,int col){
        int maxval=-1;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxval){
                maxval=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n= mat.size();
        int m=mat[0].size();
        int low=0;int high=m-1;
        while(low<=high){
            int mid= (low+high)/2;
            int i= check(mat,n,m,mid);
            int left=mid-1>=0?mat[i][mid-1]:-1;
            int right=mid+1<m?mat[i][mid+1]:-1;
            if(mat[i][mid]>left && mat[i][mid]>right){
                return {i,mid};
            }
            else if(mat[i][mid]<left){
                high=mid-1;
            }
            else low=mid+1;
        }
        return {-1,-1};

    }
};