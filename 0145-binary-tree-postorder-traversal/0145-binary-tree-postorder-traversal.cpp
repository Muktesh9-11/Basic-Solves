/*
 *
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

    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root==NULL) return{};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()){
            TreeNode* top = s.top();
            s.pop();
            ans.push_back(top->val);
            if(top->left != NULL){
                s.push(top->left);
            }
            if(top->right != NULL){
                s.push(top->right);
            }
        }
        reverse(ans.begin(),ans.end());

        return ans;

    }
};