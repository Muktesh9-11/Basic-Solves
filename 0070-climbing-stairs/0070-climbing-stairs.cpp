class Solution {
public:
    int ans = 0;
    void solve(int n){
        int prev1=2,prev2=1;
        if(n==1) {
            //prev2 = 1;
            ans = 1;
            return;
        }
        if(n==2) {
            //prev1 = 2;
            ans = 2;
            return;
        }
        for(int i=3;i<=n;i++){
            ans = prev2 + prev1;
            prev2 = prev1;
            prev1 = ans;
        }
    }
    int climbStairs(int n) {
        solve(n);
        return ans;
    }
};