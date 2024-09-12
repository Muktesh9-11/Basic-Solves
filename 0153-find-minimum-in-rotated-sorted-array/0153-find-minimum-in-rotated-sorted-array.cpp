class Solution {
public:

int solve(vector<int>&nums,int low,int high,int target){

        // {4,5,6,7,0,1,2}
        // {6,7,0,1,2,4,5}
        int mid=(low+high)/2;
        if(low>high) return target;
        target=min(nums[mid],target);
        //if(nums[mid]==target) return mid;
        if(nums[low]<=nums[mid] && nums[mid]>=nums[high]){
            return solve(nums,mid+1,high,target);
        }
        else if(nums[low]>=nums[mid]){
            return solve(nums,low,mid-1,target);
        }
        else return solve(nums,low,mid-1,target);
    }

    int findMin(vector<int>& nums) {
        int target=INT_MAX;
        int n=nums.size();
        return solve(nums,0,n-1,target);
    }
};