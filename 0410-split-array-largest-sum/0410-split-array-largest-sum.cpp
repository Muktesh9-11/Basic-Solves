class Solution {
public:

    int sum=INT_MAX;

    void solve(vector<int>& arr,int low,int high,int k){
        int mid=(low+high)/2;
        if(low>high) return;
        if(check(arr,mid,k)) {
            sum=min(sum,mid);
            return solve(arr,low,mid-1,k);
        }
        else return solve(arr,mid+1,high,k);
    }

    bool check(vector<int>& arr,int mid,int k){
        int count=1,temp=0;
        for(int i=0;i<arr.size();i++){
            if(temp+arr[i]>mid){
                count++;
                temp=0;
            }
            temp+=arr[i];
        }
        //if(sum!=0) count++;

        return count<=k;
    }

    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        int low= *max_element(arr.begin(),arr.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        solve(arr,low,high,k);
        return sum;
    }
};