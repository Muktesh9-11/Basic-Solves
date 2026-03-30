#define ll long long
class Solution {
public:

    const ll MOD = 1e9+7;

    ll factorial(ll n){
        ll ans=1;
        for(int i=1; i<=n; i++){
            ans = (ans*i) % MOD;
        }
        return ans;
    }

    ll findPow(ll a, ll b){
        if(b==0) return 1;
        ll half = findPow(a,b/2);

        ll result = ((half*half))%MOD;

        if(b%2 == 1){
            result = (result*a)%MOD;
        } 
        return result; 
    }

    ll comb(int n, int r){
        if (r<0 || r>n) return 0;
        if (r==0 || r==n) return 1;
        if (r>n/2) r=n-r;

        ll num = 1, den = 1;
        num = factorial(n);
        den = (factorial(n-r)*factorial(r)) % MOD;

        return (num * findPow(den, MOD-2)) % MOD;
    }
    
    int countVisiblePeople(int n, int pos, int k) {
        if(n-1<k) return 0;

        ll ans = (2 * comb(n-1,k)) % MOD;

        return ans;
        
    }
};