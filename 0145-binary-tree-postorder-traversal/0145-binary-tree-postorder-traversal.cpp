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

    void solve(TreeNode* root, vector<int>& arr){
        if(root == NULL) return ;
        solve(root-> left , arr);
        solve(root->right, arr);
        arr.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        solve(root, arr);
        return arr;
    }
};