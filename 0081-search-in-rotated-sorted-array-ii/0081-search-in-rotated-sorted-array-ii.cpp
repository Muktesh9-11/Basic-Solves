class Solution {
public:

    bool solve(vector<int>& arr,int low,int high,int target){
        int mid=(low+high)/2;
        if(low>high) return false;
        if(arr[mid]==target) return true;
        if(arr[low]<arr[mid]){
            if(arr[low]<=target && arr[mid]>target) return solve(arr,low,mid-1,target);
            else return solve(arr,mid+1,high,target);
        }
        else if(arr[low]==arr[mid] || arr[mid]==arr[high]){
            if(arr[low]==target || arr[high]==target) return true;
            return solve(arr,low+1,high-1,target);
        }
        else{
            if(arr[mid]<target && arr[high]>=target) return solve(arr,mid+1,high,target);
            else return solve(arr,low,mid-1,target);
        }
    }

    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,0,n-1,target);
    }
};