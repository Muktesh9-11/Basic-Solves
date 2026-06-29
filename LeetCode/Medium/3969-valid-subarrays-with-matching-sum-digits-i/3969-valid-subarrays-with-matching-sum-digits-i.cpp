#define ll long long
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        ll sum = 0;
        ll ans = 0;
        ll n = nums.size();
        for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){
                sum += nums[j];
                ll firstdig = sum%10, lastdig;
                ll temp = sum;
                while(temp > 0){
                    lastdig = temp%10;
                    temp/=10;
                }

                if(firstdig == x && lastdig == x) ans++;

            }
            sum = 0;
        }

        return ans;
    }
};