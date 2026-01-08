#define ll long long
class Solution {
public:

//vector<vector<vector<ll>>> dp;
ll dp[16][2][2];

    ll solve(string s, ll idx, bool tight, bool started){
        if(idx == s.size()){
            if(started) return 1;
            else return 0;
        }

        if(dp[idx][tight][started] != -1) return dp[idx][tight][started];

        ll cnt = 0;
        ll limit = (tight == 1) ? s[idx]-'0' : 9;

    
        for(int i=0;i<=limit;i++){
            if(started && i==0) continue;

            if(started || i!=0){
                cnt += solve(s, idx+1, tight && (i ==limit), true);
            }
            else{
                cnt += solve(s, idx+1, tight && (i ==limit), false);
            }
        }

        return dp[idx][tight][started] = cnt;
    }

    long long countDistinct(long long n) {
        string ri = to_string(n);

        //dp.resize(16,vector<vector<ll>>(2,vector<ll>))
        memset(dp,-1,sizeof(dp));

        ll ans = solve(ri,0,1,0);
        //cout<<ans<<endl;
        //ll sz = ri.size();
        //if(sz > 1)
        //for(int i=1;i<=sz-1;i++){
        //    ans += pow(9,i);
        //}

        return ans;
    }
};