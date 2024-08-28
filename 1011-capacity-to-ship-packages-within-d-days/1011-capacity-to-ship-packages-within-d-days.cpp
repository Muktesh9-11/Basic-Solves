class Solution {
public:
    long long ans=LLONG_MAX;
    void solve(vector<int>& arr,long long low,long long high,long long days){
        long long mid= (low+high)/2;
        if(low>high) return;

        if(check(arr,mid,days)) {
           ans=min(ans,mid);
           //ans=mid;
            return solve(arr,low,mid-1,days);
        }
        else return solve(arr,mid+1,high,days);
    }

    bool check(vector<int>& arr,long long mid,long long days){
        long long cnt=1;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                cnt++;
                sum=0;
            }
            sum+=arr[i];
        }
        return cnt<=days;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int low= *max_element(arr.begin(),arr.end());
        solve(arr,low,INT_MAX,days);
        return ans;
    }
};