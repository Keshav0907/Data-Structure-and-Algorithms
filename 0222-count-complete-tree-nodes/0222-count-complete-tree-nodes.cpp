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
    
    int heightLeft(TreeNode* root) {
        int cnt = 0;
        
        while(root!=NULL) {
            cnt++;
            root = root->left;
        }
        
        return cnt;
    }
    
    int heightRight(TreeNode* root) {
        int cnt = 0;
        
        while(root!=NULL) {
            cnt++;
            root = root->right;
        }
        
        return cnt;
    }
    
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left = heightLeft(root);
        int right = heightRight(root);
        
        if(left==right) {
            return (1<<left)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};