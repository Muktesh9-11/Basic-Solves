class Solution {
public:

    int solve(vector<int>&nums,int low,int high,int target){
        int mid=(low+high)/2;
        if(low>high) return -1;
        if(nums[mid]==target) return mid;
        if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<=nums[mid]) return solve(nums,low,mid-1,target);
            else return solve(nums,mid+1,high,target);
        }
        else{
            if(target>=nums[mid] && target<=nums[high]) return solve(nums,mid+1,high,target);
            else return solve(nums,low,mid-1,target);
        }
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,0,n-1,target);
    }
};