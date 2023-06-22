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
    
    void countNodes(TreeNode* root,int &count,int val) {
        
        if(root==NULL) return;
        
        if(root->val >= val) {
            count++;
            val = root->val;
        }
        
        countNodes(root->left,count,val);
        countNodes(root->right,count,val);
        
    }
        
    int goodNodes(TreeNode* root) {
     
        if(!root) return 0;
        int count = 0;
        
        countNodes(root,count,root->val);
        
        return count;
      
    }
};