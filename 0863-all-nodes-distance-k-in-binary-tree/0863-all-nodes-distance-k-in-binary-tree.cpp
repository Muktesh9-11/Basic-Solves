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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*> parentmp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left != NULL){
                parentmp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp ->right != NULL){
                parentmp[temp->right] = temp;
                q.push(temp->right);
            }
        }

        map<TreeNode* , bool> visited;
        queue<TreeNode*> que;
        que.push(target);
        visited[target] = true;
        int curr_dist = 0;
        while(!que.empty()){
            int sz = que.size();
            //curr_dist++;
            if(curr_dist++ == k) break;
            for(int i=0;i<sz;i++){
                TreeNode* current = que.front();
                que.pop();

                if(current->left!=NULL && !visited[current->left]){
                    que.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right!=NULL && !visited[current->right]){
                    que.push(current->right);
                    visited[current->right] = true;
                }
                if(parentmp[current] && !visited[parentmp[current]]){
                    que.push(parentmp[current]);
                    visited[parentmp[current]] = true;
                }
            }
        }

        vector<int> ans;
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};