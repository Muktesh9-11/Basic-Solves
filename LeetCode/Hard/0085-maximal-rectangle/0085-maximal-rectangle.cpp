class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> left(m, vector<int>(n, -1));
        vector<vector<int>> right(m, vector<int>(n, -1));

        vector<vector<int>> heights(m, vector<int>(n,0));

        for(int i=0;i<n;i++) if(matrix[0][i] == '1') heights[0][i] = 1;

        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                if(matrix[i][j] == '1'){
                    heights[i][j] = 1 + heights[i-1][j];
                }
            }
        }

        stack<int> st1,st2;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                while(!st1.empty() && heights[i][j] <= heights[i][st1.top()]){
                    st1.pop();
                }
                while(!st2.empty() && heights[i][n-j-1] <= heights[i][st2.top()]){
                    st2.pop();
                }

                left[i][j] = st1.empty() ? -1 : st1.top();
                right[i][n-j-1] = st2.empty() ? n : st2.top();

                st1.push(j);
                st2.push(n-j-1);
            }
            st1 = stack<int>();
            st2 = stack<int>();
        }

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int width = right[i][j] - left[i][j] -1;
                ans = max(ans, width*heights[i][j]);
            }
        }

        return ans;

    }
};