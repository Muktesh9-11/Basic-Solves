class Solution {
public:
    int ans=0;
    void solve(int node, vector<int>&visited,vector<vector<int>>&isConnected){
        visited[node]=1;
        for(int i=0;i<isConnected[node].size();i++){
                if(isConnected[node][i]==1 && !visited[i]){
                    solve(i,visited,isConnected);
                }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n+1,0);
        //visited[0]=1;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                solve(i,visited,isConnected);
            }
        }
        return ans;
    }
};