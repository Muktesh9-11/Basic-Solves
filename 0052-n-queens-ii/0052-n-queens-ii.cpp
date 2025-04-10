class Solution {
public:
    //vector<vector<string>>combinations;
    int count = 0;
    vector<string>current;

    bool check(int index,int i,int n){
            //check free column
            for(int j=0;j<n;j++){
                if(current[j][i]=='Q') return false;
            }

            //check free diagonal
            for(int a=index,b=i;a>=0 && b>=0;a--,b--){
                if(current[a][b]=='Q') return false;
            }
            for(int a=index,b=i;a>=0 && b<n;a--,b++){
                if(current[a][b]=='Q') return false;
            }
            return true;
    }
    void backtrack(int index,int n){
        if(index==n){
            count++;
            //combinations.push_back(current);
            return;
        }

        for(int i=0;i<n;i++){
            if(check(index,i,n)){
                current[index][i]='Q';
                backtrack(index+1,n);
                current[index][i]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        current.assign(n,string(n,'.'));
        backtrack(0,n);
        return count;
        //return combinations.size();
    }
};