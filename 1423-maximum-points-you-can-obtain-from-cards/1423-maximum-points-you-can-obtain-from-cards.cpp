class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int ans = 0;
        for(int i=0;i<k;i++){
            ans+=arr[i];
        }
        int temp = ans;
        int i = k-1;
        int j = arr.size()-1;
        while(i>=0){
            temp -= arr[i];
            temp += arr[j];
            i--;
            j--;
            ans = max(temp,ans);
        }

        return ans;
    }
};