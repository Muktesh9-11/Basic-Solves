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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL) return 0;

        int left = solve(root->left) + root->val;
        int right = solve(root->right) + root->val;
        ans= max(ans, (left+right)-root->val);
        if(left<0 || right<0){
            if(left<0) left=0;
            if(right<0) right=0;
        } 
        return max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;

        solve(root);
        return ans;
    }
};