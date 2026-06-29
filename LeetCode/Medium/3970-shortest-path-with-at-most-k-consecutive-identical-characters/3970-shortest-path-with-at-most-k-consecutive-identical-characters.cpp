class Solution {
public:

    //int solve(int node, int n, vector<vector<pair<int,int>>> &adj, vector<int>&vis,
    //string &labels, int k){
    //    if(node == n-1) return adj[node][] 
    //}

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : edges){
            int ui = it[0], vi = it[1], wi = it[2];
            adj[ui].push_back({vi,wi});
        }

        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        dist[0][k] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        // pq -> {weight, {node, count adj chars}}
        pq.push({0,{0,k}});

        while(!pq.empty()){
            auto temp = pq.top();
            int cost = temp.first;
            int node = temp.second.first;
            int cntchr = temp.second.second;
            char currchar = labels[node];
            pq.pop();
            if(cost > dist[node][cntchr]) continue;

            for(auto &it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                char adjchar = labels[adjnode];

                if(adjchar == currchar){
                    if(cntchr>1){
                        if(cost+wt < dist[adjnode][cntchr-1]){
                            dist[adjnode][cntchr-1] = cost+wt;
                            pq.push({dist[adjnode][cntchr-1],{adjnode, cntchr-1}});
                        }
                    }
                    else continue;
                }
                else{
                    if(cost+wt < dist[adjnode][k]){
                        dist[adjnode][k] = cost+wt;
                        pq.push({dist[adjnode][k],{adjnode, k}});
                    }
                }
            }
        }

        int ans = *min_element(dist[n-1].begin(),dist[n-1].end());
        if(ans == INT_MAX) return -1;
        return ans;

        //return solve(0,n,adj,vis,labels,k);

    }
};