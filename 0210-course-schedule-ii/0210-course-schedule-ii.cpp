class Solution {
public:
    
    bool dfs(int i,vector<int>&vis,vector<int>&ans,vector<vector<int>>arr,vector<int>&pathVis){
        vis[i] = 1;
        pathVis[i] = 1;

        for(auto it : arr[i]){
            if(!vis[it]){
                if(dfs(it,vis,ans,arr,pathVis) == true){
                    return true;
                }
            }
            else if(pathVis[it]) return true;
        }

        pathVis[i] = 0;
        ans.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prer) {
        vector<int> ans;
        vector<vector<int>> arr(numCourses);

        for(auto it : prer){
            arr[it[0]].push_back(it[1]);
        }
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,ans,arr,pathVis) == true){
                    return {};      // if bool dfs == true cycle is found
                }
            }
        }
        return ans;
    }
};