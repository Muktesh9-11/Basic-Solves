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
    //map<pair<int,int>,int>mpp;
    bool ans=true;
    void solve(TreeNode* leftroot , TreeNode* rightroot){
        if(!leftroot && !rightroot) {
            return;
        }
        if(!leftroot || !rightroot) {
            ans=false;
            return;
        }
        //if(leftroot->val == rightroot->val) ans=ans&&true;
        if(leftroot->val != rightroot->val) {
            ans=false;
            return;
        }
        solve(leftroot->left,rightroot->right);
        solve(leftroot->right,rightroot->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        solve(root->left , root->right);
        return ans;
    }
};