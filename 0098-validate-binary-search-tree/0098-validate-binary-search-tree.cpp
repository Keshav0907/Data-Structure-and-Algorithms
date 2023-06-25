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
//     bool isValidBST(TreeNode* root) {
        
//         if(root==NULL) return false;
//         bool left = isValidBST(root->left);
//         bool right = isValidBST(root->left);
        
//         if(root->left!=NULL and root->right!=NULL) {
            
//             if(root->left->val <root->val and root->right->val > root->val) {
//                 return true;
//             }
            
//         } else if(root->left!=NULL) {
            
//             return root->left->val < root->val;
            
//         } else if(root->right!=NULL){
//             root->right->val > root->val;
//         }   
//         return left and right;
        
        
//     }
    
       bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};