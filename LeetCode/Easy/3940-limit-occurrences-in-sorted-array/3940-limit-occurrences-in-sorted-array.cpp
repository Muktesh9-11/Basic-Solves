class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]] ++;
            if(freq[nums[i]] <= k){
                ans.push_back(nums[i]);
            }
        }

        //for(int i=0;i<n;i++){
        //    if(freq[nums[i]] > 0){
        //        ans.push_back(nums[i]);
        //        freq[nums[i]] --;
        //    }
        //}

        return ans;
    }
};