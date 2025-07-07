#define ll long long
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        int total = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> left(n+1), right(n+1);

        for(int mask =0; mask<(1<<n); mask++){
            int cnt =0, lsum=0, rsum =0 ;
            for(int i=0;i<n;i++){
                if(mask& (1<<i)){
                    cnt++;
                    lsum+= nums[i];
                    rsum+= nums[n+i];
                }
            }
            left[cnt].push_back(lsum);
            right[cnt].push_back(rsum);
        }

        for (int i = 0; i <= n; ++i) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        for(int i=0;i<=n;i++){
            for(int lsum : left[i]){
                int target = total/2 - lsum;
                auto &vec = right[n-i];

                auto idx = lower_bound(vec.begin(),vec.end(),target);
                if(idx != vec.end()){
                    int rsum = *idx;
                    int sum1 = lsum+rsum;
                    int sum2 = total - sum1;
                    ans = min(ans, abs(sum1-sum2));    
                }
                if(idx != vec.begin()){
                    idx -= 1;
                    int rsum = *idx;
                    int sum1 = lsum+rsum;
                    int sum2 = total - sum1;
                    ans = min(ans, abs(sum1-sum2));    
                }
            }
        }

        return ans;
        
    }
};