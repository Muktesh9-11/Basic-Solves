class Solution {
public:
set<int>ans;
map<int,int> safe;
map<int,int> unsafe;

    bool solve(vector<vector<int>>&graph, int n, int node, vector<int>&vis, vector<int>&path){
        if(safe[node]){
            ans.insert(node);
            return true;
        }
        if(unsafe[node]){
            return false;
        }

        vis[node] = 1;
        path[node] = 1;

        //bool x = true;
        for(auto it : graph[node]){
            if(vis[it] && path[it]){
                unsafe[it] = 1;
                unsafe[node] = 1;
                return false;
            }
            else if(unsafe[it]){
                unsafe[node] =1;
                return false;
            }
            else if(!vis[it]){
             if(solve(graph,n,it,vis,path) == false){
                 unsafe[it] = 1;
                 unsafe[node] = 1;
                 return false;
             }
            }
        }

        path[node] = 0;
        safe[node] = 1;
        ans.insert(node);
        return true; 

    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        for(int i = 0;i<n;i++){
            if(graph[i].empty()){
                safe[i] = 1;
                ans.insert(i);
            }
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);

        for(int i=0;i<n;i++){
            if(!safe[i] && !unsafe[i]){
                solve(graph,n,i,vis,path);
            }
        }

        vector<int> final;
        for(auto it : ans){
            final.push_back(it);
        }
        return final;
    }
};