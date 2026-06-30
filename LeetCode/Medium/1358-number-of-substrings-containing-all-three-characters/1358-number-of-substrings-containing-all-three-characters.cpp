#define pb push_back

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> as;
        vector<int> bs;
        vector<int> cs;

        for(int i=0;i<n;i++){
            if(s[i] == 'a') as.pb(i);
            if(s[i] == 'b') bs.pb(i);
            if(s[i] == 'c') cs.pb(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            
            auto ita = lower_bound(as.begin(), as.end(), i);
            auto itb = lower_bound(bs.begin(), bs.end(), i);
            auto itc = lower_bound(cs.begin(), cs.end(), i);
        
            if(ita == as.end() || itb == bs.end() || itc == cs.end())
                continue;
        
            int finda = *ita;
            int findb = *itb;
            int findc = *itc;

            int all3 = max(finda, max(findb,findc));

            ans += n-all3;
        }

        return ans;
    }
};