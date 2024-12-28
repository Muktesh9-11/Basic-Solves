#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1: uncolored, 0: color A, 1: color B

        // Iterate over all nodes to handle disconnected components
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // If not yet colored
                queue<int> q;
                q.push(i);
                color[i] = 0; // Assign color A to the starting node

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            // Assign opposite color to the neighbor
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            // If neighbor has the same color, it's not bipartite
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
