#define pb push_back
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        map<int,int>mpp;
        int i,j;
        for(i=0;i<=(k-1);i++){
            mpp[nums[i]]++;
        }
        i = 0;
        j = (i+k-1);
        while(j<n){
            vector<pair<int,int>> temp;
            for(auto it: mpp){
                temp.pb({it.second,it.first});
            }
            sort(temp.begin(),temp.end(),greater<pair<int,int>>());
            int fix = 0;
            for(int it = 0; it<(x<temp.size() ? x: temp.size());it++){
                fix+= (temp[it].first*temp[it].second);
            }
            ans.pb(fix);
            mpp[nums[i]]--;
            i++;
            j++;
            if(j<n) mpp[nums[j]]++;
        }

        return ans;
    }
};