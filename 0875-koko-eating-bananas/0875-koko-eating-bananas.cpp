class Solution {
public:
    long long int ayush=INT_MAX;
    void solve(long long int low,long long int high,vector<int> &piles,long long int h,long long int n){
        long long int mid= (low+high)/2;
        long long int temp=0;
        if(low>high) return;
        for(long long int i=0;i<n;i++){
            temp+=calc(piles[i],mid);
        }
        
        //if(temp==h) ayush=min(mid,ayush);
        if(temp>h) return solve(mid+1,high,piles,h,n);
        else {
            ayush=min(mid,ayush);
            return solve(low,mid-1,piles,h,n);
        }

    }

    long long int calc(long long int x,long long int k){
        if(x%k==0) return x/k;
        else return (x/k)+1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long int n=piles.size();
        solve(1,piles[n-1],piles,h,n);
        return ayush;
        
    }
};