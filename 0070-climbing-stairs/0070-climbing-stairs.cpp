class Solution {
public:
    int climbStairs(int n) {
        vector<int> hash(n+1,-1);
        hash[0]=1;
        hash[1]=1;
        for(int i=2;i<=n;i++){
            hash[i]=max(hash[i],(hash[i-1]+hash[i-2]));
        }
        return hash[n];
    }
};