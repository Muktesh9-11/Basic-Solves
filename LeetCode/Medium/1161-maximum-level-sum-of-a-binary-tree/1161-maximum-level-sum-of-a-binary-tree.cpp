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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        int sum = INT_MIN;
        while(!q.empty()){
            level++;
            int tempsum = 0;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                tempsum += node->val;
            }
            if(tempsum > sum) {
                sum = tempsum;
                ans = level; 
            }
        }

        return ans;
    }
};