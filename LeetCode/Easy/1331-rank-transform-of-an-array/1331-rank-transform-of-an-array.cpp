class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;
        for(auto &it : arr){
            st.insert(it);
        }
        int cnt = 1;
        map<int,int> mpp;
        for(auto &it : st){
            mpp[it] = cnt;
            cnt++;
        }

        vector<int> ans;
        for(auto &it : arr){
            ans.push_back(mpp[it]);
        }

        return ans;
    }
};