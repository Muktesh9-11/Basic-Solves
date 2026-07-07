class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            int maxi = INT_MIN, mini = INT_MAX;
            while(num > 0){
                int dig = num%10;
                maxi = max(maxi,dig);
                mini = min(mini,dig);
                num/=10;
            }
            int range = maxi - mini;
            if(range == ans) sum += nums[i];
            else if(range > ans){
                ans = range;
                sum = nums[i];
            }

        }

        return sum;

        
    }
};