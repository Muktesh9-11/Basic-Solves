//  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool check(vector<int>& nums) {
        int temp=0;
        int n= nums.size();
            for(int i = 0; i < n-1; i++){
        if(nums[i] > nums[(i+1)]){
            if(nums[i]<nums[n-1] || nums[0]<nums[i+1] || nums[0]<nums[n-1]){
                return false;
            }
            ++temp;
        }
    }

    return (temp <= 1);
}
    };