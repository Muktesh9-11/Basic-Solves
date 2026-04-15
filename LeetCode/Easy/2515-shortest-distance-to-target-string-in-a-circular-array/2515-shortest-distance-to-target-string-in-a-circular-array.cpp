class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int idx = startIndex;

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(words[(idx+i)%n] == target || words[(idx-i+n)%n] == target){
                ans = min(ans,i);
                break;
            }
        }

        if(ans == INT_MAX) return -1;
        return ans; 

    }
};