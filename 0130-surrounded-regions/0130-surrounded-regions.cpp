#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 

    void bfs(vector<vector<char>>& board, vector<vector<char>>& grid, int startX, int startY, vector<vector<int>>& vis) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        q.push({startX, startY});
        vis[startX][startY] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check if the new position is within bounds and not visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] == 'O') {
                    grid[nx][ny] = 'O';
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0 || n == 0) return;

        vector<vector<char>> grid(m, vector<char>(n, 'X')); // Initialize grid with 'X'
        vector<vector<int>> vis(m, vector<int>(n, 0));      // Visited array

        // Mark boundary 'O' cells and start BFS from them
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                grid[i][0] = 'O';
                bfs(board, grid, i, 0, vis);
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                grid[i][n - 1] = 'O';
                bfs(board, grid, i, n - 1, vis);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                grid[0][j] = 'O';
                bfs(board, grid, 0, j, vis);
            }
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) {
                grid[m - 1][j] = 'O';
                bfs(board, grid, m - 1, j, vis);
            }
        }

        // Copy the updated grid back to the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = grid[i][j];
            }
        }
    }
};
