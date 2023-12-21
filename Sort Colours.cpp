
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

/*
time complexity of O(N),
doesnt use merge sort OR sort library [O(nlogn)].

or using hashing to count freq. of 0s, 1s, 2s. [O(2n)]
*/
