class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int start = 0;
        while(start < nums.size()){
            int end = start;
            
            while(end < nums.size() && nums[end] == nums[start]) {
                end++;
            }
            int count = end-start;
            if(count == 1) return -1;
            res += count/3;

            if(count%3 != 0) res++;
            start=end;
        }
        return res;
       
    }
};