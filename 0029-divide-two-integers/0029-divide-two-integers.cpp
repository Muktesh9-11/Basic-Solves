class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        if(dividend==-2147483648 && divisor==-1) return 2147483647;
        return dividend/divisor;
    }
};