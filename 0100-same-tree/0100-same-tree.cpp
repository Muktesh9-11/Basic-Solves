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

    //bool ans=true;
    bool solve(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;

        if(p->val != q->val) return false;
       
        return solve(p->left,q->left) && solve(p->right,q->right);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if(p->val != q->val) return false;
        return solve(p,q);
    }
};