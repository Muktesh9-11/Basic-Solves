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
        int ans = 0;
        int sum = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            level ++;
            int tempsum = 0;

            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                //if(node == NULL) continue;
                tempsum += node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

            }

            if(tempsum > sum){
                ans = level;
                sum = tempsum;
            }

        }

        return ans;
    }
};