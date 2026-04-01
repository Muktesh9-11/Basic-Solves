#define pb push_back
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> arr;
        int n = positions.size();
        for(int i=0;i<n;i++){
            arr.pb({positions[i],i});
        }

        sort(arr.begin(),arr.end());

        stack<pair<int,int>> st;
        vector<int> ans;
        int i = 0;
        while(i<n){
            pair<int,int> now = arr[i];
            //int posi = now.first;
            int idx = now.second;
            if(directions[idx] == 'R'){
                st.push(now);
            }
            else{
                int lhealth = healths[idx];
                while(!st.empty() && lhealth > 0){
            
                        pair<int,int> r = st.top();
                        int ridx = r.second;
                        //int rposi = r.first;
                        int rhealth = healths[ridx];
                        if(rhealth < lhealth){
                            lhealth--;
                            healths[idx]--;
                            healths[ridx] = 0;
                            st.pop();
                        }
                        else if(rhealth > lhealth){
                            healths[ridx]--;
                            if(healths[ridx] == 0) st.pop();
                            lhealth = 0;
                            healths[idx] = 0;
                        }
                        else{
                            st.pop();
                            lhealth = 0;
                            healths[idx] = 0;
                            healths[ridx] = 0;
                        }
                }
            }
            i++;
        }

        for(int i=0;i<n;i++){
            if(healths[i] > 0){
                ans.pb(healths[i]);
            }
        }

        return ans;
    }
};