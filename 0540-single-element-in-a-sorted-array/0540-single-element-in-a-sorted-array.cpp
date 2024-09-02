class Solution {
public:
    int ans;
    int solve(vector<int>& arr,int low,int high){
        int mid=(low+high)/2;
        if(low>high) return -1;
        if((mid == 0 || arr[mid] != arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] != arr[mid + 1])) return arr[mid];
        else if(mid%2==0 && arr[mid]==arr[mid+1]) return solve(arr,mid+1,high);
        else if(mid%2!=0 && arr[mid]==arr[mid-1]) return solve(arr,mid+1,high);
        else return solve(arr,low,mid-1);
    }

    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return solve(nums,0,n-1);
    }
};