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

    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root!=NULL)
        {
            inorder(root->left, v);
            if(root->left == NULL && root->right == NULL)
            {
                v.push_back(root->val);
            }
            inorder(root->right,v);
        }
    }

    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int> v,v1;
        inorder(root1,v);
        inorder(root2,v1);
        return v==v1;
    }
};