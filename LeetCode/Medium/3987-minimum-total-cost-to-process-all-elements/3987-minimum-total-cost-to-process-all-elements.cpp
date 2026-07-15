#define ll long long
class Solution {
public:

    const int mod = 1000000007;

    int minimumCost(vector<int>& nums, int k) {
        __int128 avail = k;
        __int128 cost = 0;
        __int128 cnt = 1;
        ll n = nums.size();
        for(ll i=0;i<n;i++){
            if(nums[i] <= avail){
                avail -= nums[i];
                continue;
            }

            __int128 need = nums[i] - avail;
            __int128 times = (need + k - 1) / k;
            //ll subs = cnt * (cnt-1)/2;
            __int128 newcnt = cnt + times;
            __int128 add =
                    (__int128)newcnt * (newcnt - 1) / 2
                    - (__int128)cnt * (cnt - 1) / 2;
            cost = (cost + (__int128)(add)%mod) % mod;

            avail += k*times;

            cnt = newcnt;

            // while(avail<nums[i]){
            //     avail += k;
            //     cost = (cost + cnt)%mod ;
            //     cnt += 1;
            // }  

            avail -= nums[i];
        }

        return (int)cost;
    }
};