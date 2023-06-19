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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         
         if(!root) return new TreeNode(val);
         TreeNode* temp = root;
         TreeNode* temp2 = NULL;
         
         while(temp) {         
             if(temp->val <= val) {
                 temp2 = temp;
                 temp = temp->right;
                 
             } else {
                 temp2 = temp;
                 temp = temp->left;
             }
         }
        
        if(temp2->val <= val) {
            temp2->right = new TreeNode(val);
        } else {
            temp2->left = new TreeNode(val);
        }
        
        return root;
        
    }
};