class Solution {
public:

    int maxSpan(vector<int>& bars) {
        if (bars.empty()) return 1;

        int res = 1, streak = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1)
                streak++;
            else
                streak = 1;

            res = max(res, streak);
        }

        return res + 1;
    }   

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int len = min(m+2,n+2);

        int cnt = 0;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int horizontal = maxSpan(hBars);
        int vertical = maxSpan(vBars);

        int side = min(horizontal, vertical);

        return side * side;


    }
};