class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
           for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] += min(matrix[i-1][max(j-1, 0)], 
                                     min(matrix[i-1][j], 
                                              matrix[i-1][min(j+1, cols-1)]));
        }
    }

    int minSum = INT_MAX;
    for (int num : matrix[rows-1]) {
        minSum = min(minSum, num);
    }

    return minSum;
    }
};