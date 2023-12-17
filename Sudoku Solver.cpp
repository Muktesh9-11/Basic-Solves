
//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:

    bool check(int i,int j,int c,vector<vector<char>> &board){
        for(int k=0;k<9;k++){
            if(board[k][j]==c || board[i][k]==c) return false;
        }
        for(int ki=i-i%3 ; ki<i-i%3+3 ; ki++){
            for(int kj=j-j%3 ; kj<j-j%3+3 ; kj++){
                if(board[ki][kj]==c) return false;
            }
        }
        return true;
    }

    bool solve(int i,int j,vector<vector<char>> &board){
        if(i==9) return true; //end of grid (board is fully filled)
        if(j==9){       //end of row
            return solve(i+1,0,board);
        }

        if(board[i][j]!='.'){
            return solve(i,j+1,board);
        }
        for(char c='1';c<='9';c++){
            if(!check(i,j,c,board)) continue;
            //check if c is possible at i,j
            board[i][j]=c;

            if(solve(i,j+1,board)) return true;

            board[i][j]='.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};