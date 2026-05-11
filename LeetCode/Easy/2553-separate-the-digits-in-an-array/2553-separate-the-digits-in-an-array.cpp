class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int num = nums[i];
            vector<int> temp;
            while(num>0){
                temp.push_back(num%10);
                num/=10;
            }
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                ans.push_back(temp[j]);
            }
        }

        return ans;
    }
};