#define pb push_back
#define ll long long

class Solution {
public:

    int n;
    int dfs(vector<vector<int>>&adj, int node, vector<int> &vis){
        //if(adj[node].size() == 1) return 0;

        int depth = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                depth = max(depth, 1 + dfs(adj,it,vis));
            }
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        n = edges.size()+1;
        vector<vector<int>> adj(n+1);   

        for(auto& it : edges){
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }

        vector<int> vis(n+1,0);
        vis[1] = 1;

        int depth = dfs(adj,1,vis);

        ll ans = 1;
        for(int i=1; i<depth; i++){
            ans = (ans*2)%(1000000007);
        }

        return ans;

    }
};