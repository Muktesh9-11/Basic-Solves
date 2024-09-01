class Solution {
public:
    int i;
    bool solve(vector<int>& arr,int low,int high, int target){
        int mid=(low+high)/2;
        if(low>high) return false;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) return solve(arr,mid+1,high,target);
        else return solve(arr,low,mid-1,target);
    }

    void check(vector<vector<int>>& arr,int low,int high,int target){
        int mid=(low+high)/2;
        if(low>high) return;
        if(arr[mid][0]<=target){
            i=mid;
            return check(arr,mid+1,high,target);
        }
        return check(arr,low,mid-1,target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=-1;
        check(matrix,0,m-1,target);
        if(solve(matrix[i],0,n-1,target)) return true;
       /* for(int i=0;i<m;i++){
            if(solve(matrix[i],0,n-1,target))return true;
        }*/

        return false;
    }
};