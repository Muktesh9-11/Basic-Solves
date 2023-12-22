
// Combination Sum 2 (Q. 40 leetcode)

// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>>combinations;
    vector<int>sum;

    void backtrack(vector<int>&freq,int target,int index){

        if(target==0){
            combinations.push_back(sum);
            return;
        }
        if(index==freq.size() || target<index){
            return;
        }

        //when element is not chosen
        backtrack(freq,target,index+1);
        
        //when choosing the element
        if(freq[index]>0){
            freq[index]--;
        sum.push_back(index);
        backtrack(freq,target-index,index);
        sum.pop_back();
            freq[index]++;
        }

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>freq(51,0);
        for(auto &i : candidates){
            freq[i]++;
        }
        backtrack(freq,target,1);
        return combinations;
    }
};