class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int n=nums.size();
     int cnt=0;
     int el=0;
     for(int i=0;i<n;i++){
        if(cnt==0){
            cnt++;
            el=nums[i];
        }
        else if(nums[i]==el){
            cnt++;
        }
        else cnt--;
     }
     return el;
    //return -1;
    }
};