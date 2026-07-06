class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1){
            //if(s1[0] == s2[0]) return 0;
            if(s1[0] != s2[0] && s1[0] == '1') return -1;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(s1[i] == s2[i]) continue;
            else if(s1[i] == '0') ans++;
            else{
                if(i<n-1 && s1[i+1] == '1'){
                    s1[i+1] = '0';
                    ans++;
                }
                else{
                    ans+=2;
                }
            }
        }

        return ans;
    }
};