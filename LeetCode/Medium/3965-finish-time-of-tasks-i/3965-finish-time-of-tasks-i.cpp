#define ll long long
class Solution {
public:

    ll solve(int node, vector<vector<int>>& adj, vector<int> & bt){
        if(adj[node].size() == 0) return bt[node];

        ll mini = LLONG_MAX, maxi = LLONG_MIN;

        for(auto & it : adj[node]){
            ll weight = solve(it, adj, bt);
            mini = min(mini, weight);
            maxi = max(maxi, weight);
        }

        ll fin = maxi + (maxi-mini + bt[node]);

        return fin;
    }

    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        return solve(0,adj,baseTime);
    }
};