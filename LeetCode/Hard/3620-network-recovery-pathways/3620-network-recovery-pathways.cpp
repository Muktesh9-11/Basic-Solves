#define ll long long
#define pb push_back
class Solution {
public:

    bool dijk(ll & mid, int src, int target, ll& k, vector<vector<pair<int,int>>>&adj){
        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        // min heap: distance, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.push({0, src});
        while(!pq.empty()){
            // pop from priority queue
            auto [d, node] = pq.top();
            pq.pop();

            // discard if distance is greater than previous distance found
            if(d > dist[node]) continue;
            // target reached
            if(node == target) return true;
    
            for(auto& [v, w]: adj[node]){       // scan neighbours
                if(w < mid) continue;           // edge weight < mid
                int new_dist_v = d + w;
                if(new_dist_v > k) continue;    // new distance of v > total distance allowed
                if(new_dist_v < dist[v]){       // better distance found to neighbour v
                    dist[v] = d + w;            // update distance of v
                    pq.push({dist[v], v});      // puch to pq
                }
            }
        }
        return false;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int maxEdge = 0;
        for(auto & e : edges){
            int u = e[0], v = e[1], w = e[2];

            if(online[u] && online[v]){
             adj[u].pb({v,w}); 
                maxEdge = max(maxEdge,w);
            }
        }

        ll l=0, h= maxEdge, ans = -1;
        while(l<=h){
            ll mid = l+(h-l)/2;
            if(dijk(mid,0,n-1,k,adj)){
                ans = mid;
                l = mid+1;
            }
            else h = mid - 1;
        }

        return ans;
        
    }
};