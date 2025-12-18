#define ll long long
#define pb push_back

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strat, int k) {
        int n = prices.size();
        vector<ll> pref(n);
        vector<ll> sums(n);

        pref[0] = prices[0];
        sums[0] = prices[0] * strat[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + prices[i];
            sums[i] = sums[i-1] + (prices[i] * strat[i]);
        }

        ll ans = sums[n-1];

        int i = 0, j = k-1;
        while(j<n){
            ll temp = sums[j] - (i>0 ? sums[i-1] : 0);

            ll fix = sums[n-1];
            fix -= temp;
            fix += (pref[j] - pref[i+(j-i)/2]);

            ans = max(ans,fix); 
            j++;
            i++;
        }

        return ans;


    }
};