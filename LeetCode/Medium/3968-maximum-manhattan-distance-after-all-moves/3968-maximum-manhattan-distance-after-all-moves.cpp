class Solution {
public:
    int maxDistance(string moves) {
        int cnt = 0;
        int xval = 0;
        int yval = 0;

        for(char c : moves){
            if(c == 'U') yval++;
            if(c == 'D') yval --;
            if(c == 'L') xval--;
            if(c == 'R') xval++;
            if(c == '_') cnt++;
        }

        return abs(xval)+abs(yval)+cnt;
    }
};