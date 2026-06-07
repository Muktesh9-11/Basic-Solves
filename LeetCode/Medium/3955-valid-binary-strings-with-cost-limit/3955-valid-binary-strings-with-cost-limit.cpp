#define pb push_back
class Solution {
public:

    vector<string> ans;
    int N,K;
    void solve(int idx, int st, string s, int cost){
        if(idx == N){
            if(cost<=K) ans.pb(s);
            return;
        }

        if(cost > K) return;

        if(st == 0){
            solve(idx+1, 1, s+"1", cost+idx);
            solve(idx+1, 0, s+"0", cost);
        }
        else{
            solve(idx+1, 0, s+"0", cost);
        }

    }

    vector<string> generateValidStrings(int n, int k) {
        N = n;
        K = k;
        solve(0,0,"",0);
        return ans;
    }
};