/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<tuple<int,int,int>> vec;
    void solve(TreeNode* root,int cnt,int depth){
        if(root==NULL) return;
        solve(root->left,cnt-1,depth+1);
        vec.push_back({cnt,depth,root->val});
        solve(root->right,cnt+1,depth+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        sort(vec.begin(),vec.end());
        int n = get<0>(vec[vec.size()-1]) - get<0>(vec[0]) +1;
        vector<vector<int>>ans(n);
        int sz = abs(get<0>(vec[0]));
        for(int i=0;i<vec.size();i++){
            
            ans[get<0>(vec[i]) + sz].push_back(get<2>(vec[i]));
            //sort(ans[vec[i].first + sz].begin(),ans[vec[i].first + sz].end());
        }
        return ans;
    }
};