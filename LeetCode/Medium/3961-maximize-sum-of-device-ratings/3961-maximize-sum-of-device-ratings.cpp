#define ll long long
class Solution {
public:

    ll n,m;

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    long long maxRatings(vector<vector<int>>& units) {
        m = units.size();
        n = units[0].size();

        if(n == 1){
            ll cnt = 0;
            for(ll i=0;i<m;i++){
                cnt += units[i][0];
            }
            return cnt;
        }

        for(ll i=0;i<m;i++){
            sort(units[i].begin(), units[i].end());
        }

        sort(units.begin(),units.end(), cmp);

        ll smallestSecondVal = units[0][1];
        ll ssvIdx = 0;
        ll smval = units[0][0];
        
        for(ll i=1;i<m;i++){
            if(units[i][1] < smallestSecondVal){
                smallestSecondVal = units[i][1];
                ssvIdx = i;
            }
            smval = min(smval, (ll)units[i][0]);
        }

        ll sum = 0;
        sum += smval;

        for(ll i=0;i<m;i++){
            if(i == ssvIdx) continue;
            sum += units[i][1];
        }

        return sum;

    }
};