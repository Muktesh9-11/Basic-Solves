class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Check if endWord exists in wordList
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // Add beginWord to the wordList
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> adj(n);

        // Build the adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = 0;
                for (int k = 0; k < beginWord.size(); k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        diff++;
                    }
                }
                if (diff == 1) { // If words differ by exactly one character
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // BFS to find the shortest path
        queue<pair<int, int>> q; // Pair of (index in wordList, depth)
        vector<int> vis(n, 0);

        int beginIndex = n - 1; // Index of beginWord in wordList
        q.push({beginIndex, 1});
        vis[beginIndex] = 1;

        while (!q.empty()) {
            int current = q.front().first;
            int depth = q.front().second;
            q.pop();

            // Check if we reached the endWord
            if (wordList[current] == endWord) {
                return depth;
            }

            // Explore neighbors
            for (int neighbor : adj[current]) {
                if (!vis[neighbor]) {
                    q.push({neighbor, depth + 1});
                    vis[neighbor] = 1;
                }
            }
        }

        return 0; // No transformation sequence found
    }
};
