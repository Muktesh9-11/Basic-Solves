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

    vector<tuple<int,int,int>> vec;
    map<int,int> mpp;
    void solve(TreeNode* root, int cnt, int depth){
        if(root==NULL) return;
        
        solve(root->right, cnt+1, depth-1);
        if(mpp[depth]==0){
            vec.push_back({depth,cnt,root->val});
        }
        mpp[depth]++;
        solve(root->left, cnt-1, depth-1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        solve(root,0,0);
        sort(vec.begin(),vec.end(), greater<tuple<int,int,int>>());

        vector<int> ans;
        ans.push_back(get<2>(vec[0]));
        for(int i=1;i<vec.size();i++){
            if(get<0>(vec[i]) != get<0>(vec[i-1])){
                ans.push_back(get<2>(vec[i]));
            }
        }
        return ans;
    }
};