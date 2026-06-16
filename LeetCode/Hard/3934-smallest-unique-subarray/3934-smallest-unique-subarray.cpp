#define ll long long
class Solution {
public:

    ll n;
    long long prime = 1000000007;
    vector<long long> powers;

    bool check(vector<int>&nums, ll sz){
        map<ll,ll> mpp;

        ll val = 0;

        // FIX 1: build hash consistently
        for(ll i = 0; i < sz; i++){
            val = (val * 10 + nums[i]) % prime;
        }

        mpp[val]++;

        ll left = 0, right = sz;

        while(right < n){

            // FIX 2: remove leftmost digit
            val = (val - nums[left] * powers[sz-1]) % prime;
            if(val < 0) val += prime;

            // FIX 3: shift and add new digit
            val = (val * 10 + nums[right]) % prime;

            mpp[val]++;

            left++;
            right++;
        }

        for(auto& it : mpp){
            if(it.second == 1) return true;
        }

        return false;
    }
    

    int solve(vector<int>&nums, ll low, ll high){
        if(low > high) return low;

        ll mid = low + (high-low)/2;

        if(check(nums, mid)){
            return solve(nums, low, mid-1);
        }
        
        return solve(nums, mid+1, high);
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();

        powers.resize(n+1,1);
        for(ll i=1;i<=n;i++)
            powers[i] = (powers[i-1]*10)%prime;

        return solve(nums, 1, n);

    }
};