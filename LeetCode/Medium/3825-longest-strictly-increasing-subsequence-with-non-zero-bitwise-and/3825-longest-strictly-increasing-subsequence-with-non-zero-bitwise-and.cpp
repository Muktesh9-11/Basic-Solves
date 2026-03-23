#define pb push_back
class Solution {
public:

    int lis(vector<int>&vec){
        int n = vec.size();

        vector<int> temp;
        //temp.pb(vec[0]);

        for(int i=0;i<n;i++){
            if(temp.empty() || vec[i] > temp.back()){
                temp.pb(vec[i]);
            }
            else{
                auto idx = lower_bound(temp.begin(),temp.end(),vec[i]);
                *idx = vec[i];
            }
        }

        return temp.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int fin = 0;
        for(int i=0;i<32;i++){
            vector<int> vec;
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<i)){
                    vec.pb(nums[j]);
                }
            }
            int ans = lis(vec);
            fin = max(fin,ans);
        }

        return fin;
    }
};