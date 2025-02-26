class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int a,b;
        int n = arr.size();
        int ans = 0;
        int counta = 0,countb = 0;
        int i = 0,j = 0;

        if(n == 1){
            return 1;
        }
        else if(n==2){
            return 2;
        }

        for(i = 0;i<n;i++){
            if(arr[i] != arr[j]){
                j = i-1;
                counta = 1;
                break;
            }
        }
        countb = i;
        //if(i<n) 
        a = arr[i];
        b = arr[j];
        int k = i+1;
        ans = max(ans,counta+countb);
        while(k<n){
            if(arr[k] == a){
                i = k;
                counta++;
                ans = max(ans,counta+countb);
            }
            else if(arr[k] == b){
                j = k;
                countb++;
                ans = max(ans,counta+countb);
            }
            else{
                if(i<j){
                    countb = j-i;
                    i = k;
                    a = arr[i];
                    counta = 1;
                    ans = max(ans,counta+countb);
                }
                else{
                    counta = i-j;
                    j = k;
                    b = arr[j];
                    countb = 1;
                    ans = max(ans,counta+countb);
                }
            }
            k++;
        }
        return ans;
    }
};