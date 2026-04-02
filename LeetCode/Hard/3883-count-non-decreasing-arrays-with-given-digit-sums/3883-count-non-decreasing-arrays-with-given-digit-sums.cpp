#define ll long long
#define pb push_back

class Solution {
public:

    const ll MOD = 1e9+7;
    vector<vector<int>> pref;
    int n;
    int calcsum(int i){
        int sum = 0;
        while(i>0){
            sum += i%10;
            i/=10;
        }
        return sum;
    }

    int solve(vector<int>&digitSum, int i, int s, vector<vector<int>>&dp){
        if(i==n){
            return 1;
        }
        if(s>5000) return 0;

        if(dp[i][s] != -1) return dp[i][s];

        //vector<int>&temp = pref[digitSum[i]];

        //auto it = lower_bound(temp.begin(),temp.end(),prev);
        ll cnt = 0;

        if(digitSum[i] == calcsum(s)){
            cnt = (cnt+solve(digitSum,i+1,s,dp))%(MOD);
        }

        cnt = (cnt+solve(digitSum,i,s+1,dp))%MOD;

        return dp[i][s] = cnt;

    }

    int countArrays(vector<int>& digitSum) {
        n = digitSum.size();
        //pref.assign(51,vector<int>());

        //for(int i=0;i<=5000;i++){
        //    int sum = calcsum(i);
        //    pref[sum].pb(i);
        //}

        vector<vector<int>> dp(n+1,vector<int>(5001,-1));

        return solve(digitSum,0,0,dp);
    }
};