class Solution {
public:

    bool check(vector<int>& arr,int m, int k, int day){
        int total=0;
        for(int i=0;i<arr.size();i++){
            int count=0;

            while(i<arr.size() && count<k && arr[i]<=day){
                count++;
                i++;
            }

            if(count==k){
                total++;
                i--;
            }
            if(total>=m){
                return true;
            }
        }
        return false;
    }


    int minDays(vector<int>& arr, long long m, long long k) {
        long long x;
        x=m*k;
        long long y= arr.size();
        if(x>y) return -1;
       // int high = max_element(arr.begin(),arr.end());
        int low=1,high=INT_MAX;
        while(low<high){
            int mid=low+(high-low)/2;

            if(check(arr,m,k,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};