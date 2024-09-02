class Solution {
public:

    int solve(vector<int>& arr,int low,int high,int n){
        int mid=(low+high)/2;
        if(low>high) return -1;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]) return mid;
        else if(arr[mid]>arr[mid-1]) return solve(arr,mid+1,high,n);
        else return solve(arr,low,mid-1,n);
    }

    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        return solve(nums,1,n-2,n);
    }
};