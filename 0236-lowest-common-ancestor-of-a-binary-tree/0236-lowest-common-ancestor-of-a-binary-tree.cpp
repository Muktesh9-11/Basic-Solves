/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    //TreeNode* ans=nullptr;
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* parent){
        if(root==NULL) return nullptr;
        if(root->val==p->val || root->val==q->val){
            return root;
        }

        TreeNode* parent1 = solve(root->left,p,q,root);
        TreeNode* parent2 = solve(root->right,p,q,root);

        if(parent1 == NULL) return parent2;
        else if(parent2 == NULL) return parent1;
        else return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q,root);
        //return ans;
    }
};