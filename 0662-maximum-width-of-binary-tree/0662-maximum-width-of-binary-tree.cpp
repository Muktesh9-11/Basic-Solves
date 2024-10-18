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
    int ans=0;
    void solve(TreeNode* root){
        if(root==NULL) return;
        queue<pair<TreeNode*,long long> > q;
        q.push({root,0});
        while(!q.empty()){
            int size= q.size();
            long long idx_set = q.front().second;
            int first , last;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                long long current_idx = q.front().second - idx_set;
                q.pop();

                if(i==0) first = current_idx;
                if(i==size-1) last = current_idx;
                if(temp -> left != NULL) q.push({temp->left , current_idx*2 +1});
                if(temp -> right != NULL) q.push({temp->right , current_idx*2 +2}); 

            }
            ans = max(ans,(last-first +1));
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};