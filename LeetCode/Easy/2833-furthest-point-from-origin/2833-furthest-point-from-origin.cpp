class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntl = 0;
        int cntr = 0;
        int cntu = 0;
        int n = moves.size();
        for(int i=0;i<n;i++){
            if(moves[i] == 'L') cntl++;
            else if(moves[i] == 'R') cntr++;
            else cntu++;
        }

        return (max(cntl,cntr) + cntu) - min(cntl,cntr);
    }
};