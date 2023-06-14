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
    
    pair<int,bool> helper(TreeNode* root) {
        
        pair<int,bool> p;
        if(root==NULL) {
            p.first = 0;
            p.second = true;
            return p;
        }
        
        pair<int,bool> left  = helper(root->left);
        pair<int,bool> right = helper(root->right);
        
        p.first = max(left.first,right.first)+1;
        
        if(left.second and right.second and abs(left.first-right.first)<=1) {
            p.second = true;
        } else {
            p.second = false;
        }
        
         return p;
        
}
    
    
    bool isBalanced(TreeNode* root) {
        
        pair<int,bool> ans = helper(root);
        return ans.second;
        
    }
};