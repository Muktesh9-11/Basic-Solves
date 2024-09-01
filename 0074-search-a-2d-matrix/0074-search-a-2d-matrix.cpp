class Solution {
public:
    bool solve(vector<vector<int>>& matrix,int low,int high,int target,int n){
        int mid=low+(high-low)/2;
        if(low>high) return false;
        int row=mid/n;
        int col=mid%n;
        if(matrix[row][col]==target)return true;
        else if(matrix[row][col]<target) return solve(matrix,mid+1,high,target,n);
        else return solve(matrix,low,mid-1,target,n);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //row= i/n,   column=i%n
        int m=matrix.size();
        int n=matrix[0].size();
        return solve(matrix,0,(n*m)-1,target,n);
    }
};