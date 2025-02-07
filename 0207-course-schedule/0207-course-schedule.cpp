class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        int m = pr.size();
        vector<int> indeg(numCourses,0);
        vector<int> vis(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<m;i++){
            adj[pr[i][1]].push_back(pr[i][0]);
            indeg[pr[i][0]]++;
        }

        queue<int>q;
        int count = 0;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count++;
            for(auto it : adj[temp]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        return count == numCourses;
    }
};


