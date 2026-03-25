class Solution {
public:
    vector<string> arr;
    map<pair<int,int>,int> dp;

    bool check(string &a, string &b){
    if(a.size() != b.size()+1) return false;

    int i=0, j=0;
    while(i<a.size()){
        if(j<b.size() && a[i]==b[j]){
            i++; j++;
        } else {
            i++;
        }
    }
    return j==b.size();
}

    int solve(int i, int prev){
        if(i == arr.size()){
            return 0;
        }

        if(dp.count({i,prev})) return dp[{i,prev}];

        int notpick = solve(i+1,prev);
        int pick = 0;
        if(prev==-1 || check(arr[i],arr[prev])){
            pick = 1 + solve(i+1, i);
        }

        return dp[{i,prev}] = max(pick, notpick);

    }

    int longestStrChain(vector<string>& words) {
        arr = words;
        int n = words.size();
        sort(arr.begin(), arr.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n,1);
        int ans = 1;

        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(check(arr[i],arr[prev]) && (dp[i] < dp[prev]+1)){
                    dp[i]= dp[prev]+1;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        //return solve(0,-1);
    }
};