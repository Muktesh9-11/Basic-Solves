
// Using Backtracking

//https://leetcode.com/problems/combination-sum/

class Solution {
public:

    vector<vector<int>>combinations;
    vector<int>sum;

    void backtrack(vector<int>candidates,int target,int index){

        if(target==0){
            combinations.push_back(sum);
            return;
        }
        if(index==candidates.size() || target<0){
            return;
        }

        backtrack(candidates,target,index+1);
        
        sum.push_back(candidates[index]);
        backtrack(candidates,target-candidates[index],index);
        sum.popback();

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0);
        return combinations;
    }
};



