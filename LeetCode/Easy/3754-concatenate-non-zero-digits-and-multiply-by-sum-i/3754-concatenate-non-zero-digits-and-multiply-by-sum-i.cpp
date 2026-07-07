#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        ll sum = 0;
        ll x = 0;
        ll cnt = 1;
        while(n>0){
            ll fix = n%10;
            if(fix != 0){
                x += fix*cnt;
                cnt*=10;
                sum+=fix;
            }
            n/=10;
        }

        return x*sum;
    }
};