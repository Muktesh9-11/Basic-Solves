class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int>vis(n,0);

        for(int i =0 ; i<n;i++){
            if(lights[i] == 0) continue;

            int v = lights[i];
            vis[ (i-v >= 0 ? i-v : 0) ] += 1;
            if(i+v < n-1) vis[i+v+1] += -1;
        }

        for(int i = 1;i<n;i++){
            vis[i] += vis[i-1];
        }

        int ans = 0;

        //for(auto it : vis) cout<<it<<" ";
        int i=0,j=0;
        while(j<n){
            if(vis[j] == 0){
                cout<<j<<" ";
                ans++;
                j+=3;
                i=j;
            }
            else{
                j++;
                i = j;
            }
        }

        return ans;

    }
};