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
    vector<int> vec,vec2;
    
    void traversal2(TreeNode* root) {
              if(root==NULL) {
            vec2.push_back(-1);
                return ;
        }
        
        vec2.push_back(root->val);
         traversal2(root->left);
        traversal2(root->right);
       
        
        
    }
    
    void traversal1(TreeNode* root) {
        
        if(root==NULL) {
            vec.push_back(-1);
                return ;
        }
        
        vec.push_back(root->val);
        traversal1(root->right);
        traversal1(root->left);
        
        
    }
    
    bool helper(TreeNode* left,TreeNode* right) {
        
        if(left==NULL || right==NULL) return left==right;
        if(left->val != right->val) return false;
        
        return helper(left->left,right->right) && helper(left->right,right->left) ;
        
    }
    bool isSymmetric(TreeNode* root) {
         
       
        
//         traversal1(root->left);
//         traversal2(root->right);
        
//         return vec==vec2;
        
        return root==NULL || helper(root->left,root->right);
         
       
        
    }
};