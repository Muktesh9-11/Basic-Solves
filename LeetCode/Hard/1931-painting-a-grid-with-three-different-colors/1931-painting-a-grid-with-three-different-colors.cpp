#define pb push_back
class Solution {
public:

int mod = 1e9+7;
int N,M;

    vector<char> rgb = {'R','G','B'};
    vector<string>states;
    void generateState(string str, int i){
        if(i==M){
            states.pb(str);
            return;
        }
        
        for(auto c : rgb){
            if(i>0 && c == str[i-1]) continue;
            else{
                generateState(str+c,i+1);
            }
        }
    }

    int solve(int idx, int state, vector<vector<int>>&dp){
        if(idx == N){
            return 1;
        }
        string prevstate = states[state];

        if(dp[idx][state] != -1) return dp[idx][state];

        int cnt = 0;
        for(int i=0;i<states.size();i++){
            string nowstate = states[i];
            if(nowstate == prevstate) continue;

            int flag = 0;
            for(int j=0;j<nowstate.size();j++){
                if(nowstate[j] == prevstate[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                cnt = (cnt + solve(idx+1,i,dp))%mod;
            }
        }

        return dp[idx][state] = cnt;
    }

    int colorTheGrid(int m, int n) {
        N = n;
        M = m;
        generateState("",0);

        vector<vector<int>> dp(n,vector<int>(states.size(),-1));
        int ans = 0;
        for(int i=0;i<states.size();i++){
            ans = (ans + solve(1,i,dp))%mod;
        }

        return ans;
    }
};