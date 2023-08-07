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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        
        while(!q.empty()) {
            int size = q.size();
            int Min = q.front().second;
            int first,last;
            
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                int currentId = q.front().second - Min;
                q.pop();
                if(i==0) first = currentId;
                if(i==size-1) last = currentId;
                if(node->left) {
                    q.push({node->left,2LL*currentId+1});
                }
                if(node->right) {
                    q.push({node->right,2LL*currentId+2});
                }
            }
            ans = max(ans,last-first+1);
        }
            
        
        return ans;
    }
};