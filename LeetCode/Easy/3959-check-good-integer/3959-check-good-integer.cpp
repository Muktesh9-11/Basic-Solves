class Solution {
public:
    bool checkGoodInteger(int n) {
        long long ds = 0, ss = 0;
        while(n>0){
            int d = n%10;
            ss += d;
            ds += (d*d);
            n/=10;
        }
        return ds-ss >= 50;
    }
};