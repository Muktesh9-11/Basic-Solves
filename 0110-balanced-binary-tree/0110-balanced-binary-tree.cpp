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
    int temp=0;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int left = solve(root->left) +1;
        int right = solve(root->right) +1;
        //temp=abs(left-right);
        if(abs(left-right)>1) temp++;
        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int diff = solve(root);
        if(temp!=0){
            return false;
        }
        return true;
    }
};