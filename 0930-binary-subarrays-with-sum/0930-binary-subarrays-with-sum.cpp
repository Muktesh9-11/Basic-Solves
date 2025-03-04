class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0, ans = 0;
        int l = 0, r = 0;
        int n = nums.size();

        while(r<n){
            count += nums[r];
            if(count == goal){
                ans++;
                int i = l;
                while(nums[i] ==0 && i<r){
                    ans++;
                    i++;
                }
            }
            if(count>goal && l<r){
                count -= nums[l];
                l++;
                count -= nums[r];
                //r--;
                continue;

            }
            r++;
            
        }
        return ans;
    }
};