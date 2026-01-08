#define pb push_back
class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        
        int findUltimateParent(int node){
            if(parent[node] == node){
                return node;
            }
            
            return parent[node] = findUltimateParent(parent[node]);
        }
        
        void UnionByRank(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void UnionBySize(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,int>> loc;

        for(auto it : points){
            loc.pb({it[0],it[1]});
        }

        int V = points.size();
        vector<pair<int , pair<int,int>>> edges;
        for(int i=0;i<V-1;i++){
            for(int j=i+1;j<V;j++){
                int u = i;
                int v = j;
                int wt = abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second);
                edges.pb({wt,{u,v}});
            }
        }

        sort(edges.begin(),edges.end());

        DisjointSet ds(V);
        int mstwt = 0;

        for(int i=0;i<edges.size();i++){
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                mstwt += wt;
                ds.UnionBySize(u,v);
            }
        }

        return mstwt;
    }
};