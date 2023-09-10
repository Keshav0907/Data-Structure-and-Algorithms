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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        
        vector<vector<int>> vec;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int size = q.size();
             vector<int> ans;
            while(size--) {
                TreeNode* f = q.front();
                q.pop();
                ans.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            
            vec.push_back(ans);
            ans.clear();
        }
        
        return vec;
        
        
    }
};