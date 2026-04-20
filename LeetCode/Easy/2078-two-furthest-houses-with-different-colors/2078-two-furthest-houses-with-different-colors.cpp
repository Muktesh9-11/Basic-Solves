class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int l=0,r=n-1;
        while(l<n){
            if(colors[l] != colors[n-1]){
                ans = max(ans,abs(l-(n-1)));
                break;
            }
            if(colors[r] != colors[0]){
                ans = max(ans,abs(r));
                break;
            }
            l++;
            r--;
        }

        return ans;
    }
};