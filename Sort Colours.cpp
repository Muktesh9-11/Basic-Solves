
//https://leetcode.com/problems/sort-colors/

// Using Dutch National Flag Algo.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size();
        int mid=0,low=0,high=n-1;
    // Write your code here
    while (mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    }
};