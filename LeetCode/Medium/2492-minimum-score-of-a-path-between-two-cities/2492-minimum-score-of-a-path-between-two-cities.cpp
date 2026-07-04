#define pb push_back
class Solution {
public:

    int ans = INT_MAX;

    void solve(vector<vector<pair<int,int>>> & adj, vector<int>& vis, int node){
        vis[node] = 1;

        for(auto & it : adj[node]){
            int nxtnode = it.first;
            int cost = it.second;

            ans = min(ans,cost);

            if(!vis[nxtnode]){
                solve(adj,vis,nxtnode);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto & it : roads){
            int ui = it[0];
            int vi = it[1];
            int ci = it[2];

            adj[ui].pb({vi,ci});
            adj[vi].pb({ui,ci});
        }

        vector<int> vis(n+1,0);
        solve(adj,vis,1);

        return ans;

    }
};