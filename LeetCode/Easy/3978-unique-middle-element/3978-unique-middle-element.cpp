class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        int mid = n/2;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        return mpp[nums[mid]] == 1;
    }
};