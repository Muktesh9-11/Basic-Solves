class Solution {
public:

    int solve(vector<int>& nums,int low,int high,int target){
        int mid=(low+high)/2;
        if(low>high) return -1;
        else if(target==nums[mid]){
            return mid;
        }
        else if(target<nums[mid]){
            return solve(nums,low,mid-1,target);
        }
        return solve(nums,mid+1,high,target);
    }

    int search(vector<int>& nums, int target) {
        return solve(nums,0,nums.size()-1,target);
    }
};