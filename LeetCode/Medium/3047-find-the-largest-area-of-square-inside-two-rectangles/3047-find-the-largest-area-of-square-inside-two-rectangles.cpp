#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        ll n = bl.size();

        ll ans = 0;

        for(int i=0;i<n-1;i++){

            int xa1 = bl[i][0], ya1 = bl[i][1];
            int xa2 = tr[i][0], ya2 = tr[i][1];

            for(int j=i+1; j<n;j++){

                int xb1 = bl[j][0], yb1 = bl[j][1];
                int xb2 = tr[j][0], yb2 = tr[j][1];

                if(xb1 > xa2 || xb2 < xa1) continue;
                if(yb1 > ya2 || yb2 < ya1) continue;

                vector<int> xarr = {xa1,xa2,xb1,xb2};
                sort(xarr.begin(),xarr.end());
                vector<int> yarr = {ya1,ya2,yb1,yb2};
                sort(yarr.begin(),yarr.end());
                ll intrx = abs(xarr[1] - xarr[2]);
                ll intry = abs(yarr[1] - yarr[2]);

                ll side = min(intrx,intry);
                ll ar = side*side;

                ans = max(ans, ar);
            }
        }

        return ans;
    }
};