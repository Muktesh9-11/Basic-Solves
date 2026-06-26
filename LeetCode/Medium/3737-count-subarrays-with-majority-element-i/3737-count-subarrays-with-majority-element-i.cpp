class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == target) cnt++;
            pref[i] = cnt;
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=i; j<n;j++){
                if(pref[j] - (i==0 ? 0 : pref[i-1]) > (j-i+1)/2) ans++;
            }
        }

        return ans;
    }
};