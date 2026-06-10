class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int minval = INT_MAX, maxval = INT_MIN;
        for(int i=0;i<n;i++){
            minval = min (minval, nums[i]);
            maxval = max(maxval, nums[i]);
        }

        return (long long)(maxval - minval)*(long long)k;
    }
};