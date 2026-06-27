#define pb push_back
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        string s = "";
        for(int i=0;i<n;i++){
            s+= '.';
        }
        ans.pb(s);

        s = "";
        for(int i=0;i<n-1;i++){
            s+= '#';
        }
        s+= '.';

        for(int i=1;i<m;i++){
            ans.pb(s);
        }

        return ans;
    }
};