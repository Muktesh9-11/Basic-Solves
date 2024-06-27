class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]=i+1;
        }
        for(int i=0;i<nums1.size();i++){
            int num=-1;
            for(int j=mpp[nums1[i]];j<nums2.size();j++){
                if(nums2[j]>nums1[i]){
                    num=nums2[j];
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};