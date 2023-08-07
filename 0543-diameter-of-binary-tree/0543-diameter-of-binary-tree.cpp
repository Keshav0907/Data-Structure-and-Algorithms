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
    
    class HDpair{
        public :
        int height;
        int diameter;
    };
    
    HDpair dia(TreeNode* root) {
        HDpair p;
        
        if(root==NULL) {
            p.height = p.diameter = 0;
            return p;
        }
        
        HDpair left = dia(root->left);
        HDpair right = dia(root->right);
        
        p.height = max(left.height,right.height)+1;
        
        int d1 = left.height + right.height;
        int d2 = left.diameter;
        int d3 = right.diameter;
        
        p.diameter = max(d1,max(d2,d3));
        
        return p;
            
        
    }
    
    int height(TreeNode* root,int &diameter) {
        
        if(root==NULL) return 0;
        
        int leftHeight = height(root->left,diameter);
        int rightHeight = height(root->right,diameter);
        diameter = max(leftHeight+rightHeight,diameter);
        return  1 + max(leftHeight,rightHeight);
        
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        // HDpair ans = dia(root);
        // return ans.diameter;
        int diameter = 0;
        height(root,diameter);
        return diameter;
        
    }
};