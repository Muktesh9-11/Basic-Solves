#define ll long long
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        ll n = nums.size();

        vector<ll> suff(n);

        set<ll> s;

        for(int i=0;i<=n;i++){
            s.insert(i);
        }

        for(int i=n-1; i>= 0; i--){
            if(s.find(nums[i]) != s.end()) s.erase(nums[i]);
            suff[i] = *s.begin();
        }

        vector<int> ans;
        set<ll>st;
        for(int i=0;i<=suff[0];i++){
            st.insert(i);
        }

        ll curr = suff[0];
        for(int i=0;i<n;i++){
            st.erase(nums[i]);
            ll mexval = *st.begin();

            if(mexval >= curr){
                ans.push_back(mexval);
                st.clear();

                if(i<n-1){
                    curr = suff[i+1];
                    for(int j = 0;j<=curr;j++){
                        st.insert(j);
                    }
                }
            }
        }
        return ans;
        
    }
};