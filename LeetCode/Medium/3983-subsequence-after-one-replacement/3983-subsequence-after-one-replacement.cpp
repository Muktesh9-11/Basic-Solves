class Solution {
public:

    int m, n;

    bool solve(){
        return true;
    }

    bool canMakeSubsequence(string s, string t) {
        m = s.size();
        n = t.size();
        if(m>n) return false;
        // check -> s is already a subsequence


        vector<int> left(m,n);
        vector<int> right(m,-1);

        int j = 0;
        for(int i=0;i<m;i++){
            while(j<n){
                if(s[i] == t[j]){
                    left[i] = j;
                    j++;              // FIX
                    break;
                }
                j++;
            }
            if(j > n) break;
        }
        
        if(left[m - 1] != n) return true;

        j = n-1;
        for(int i=m-1;i>=0;i--){
            while(j>=0){
                if(s[i] == t[j]){
                    right[i] = j;
                    j--;
                    break;
                }
                j--;
            }
            if(j<0) break;
        }

        for(int k = 0; k < m; k++) {

            int L = (k == 0 ? -1 : left[k - 1]);
            int R = (k == m - 1 ? n : right[k + 1]);

            if(L == n || R == -1) continue;

            // Need at least one position in t between L and R
            // to match the replaced character.
            if(R - L >= 2)
                return true;
        }

        return false;

    }
};