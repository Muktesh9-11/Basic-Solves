//#define push_back pb
class Solution {
public:
    vector<vector<int>> ans;
   //ans.pb({});

    void solve(vector<int>& arr,vector<int>& nums, int i){
        if(i>=nums.size()) ans.push_back(arr);
        if(i<nums.size()){
            arr.push_back(nums[i]);
            solve(arr,nums,i+1);
            arr.pop_back();
            solve(arr,nums,i+1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        //vector<int>arr;
        //int n= nums.size();
        int i=0;
        vector<int>arr;
        solve(arr,nums,i);
        return ans;
    }
};