/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* helper(TreeNode* root,int toSearch) {
        
        if(!root) return NULL;
        
        if(root->val > toSearch) {
            return helper(root->left,toSearch);
        } else if(root->val < toSearch) {
            return helper(root->right,toSearch);
        }
        return root;
    }
    
    void findPath(TreeNode* root,TreeNode* tofind,vector<int> & vec) {
        
        if(root==NULL) return;
        
        vec.push_back(root->val);
        if(root->val < tofind->val) {
            findPath(root->right,tofind,vec);
        } else if(root->val > tofind->val) {
            findPath(root->left,tofind,vec);
        } else {
            return;
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<int> path1;
//         findPath(root,p,path1);
//         vector<int> path2;
//         findPath(root,q,path2);
//         int m= path1.size();
//         int n= path2.size();
        
//         int index;
//         if(m <= n) {
//             index = m-1;
//         } else {
//             index = n-1;
//         }
        
//         int toSearch  = -1;
//         while(index >= 0) {
//             if(path1[index]==path2[index]) {
            
//                 toSearch = path1[index];
        
//                 break;
//             }
//             index--;
//         }
//               return helper(root,toSearch);
        
        if(root==NULL or root==p or root==q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL) return right;
        if(right==NULL) return left;
           
        return root;
        
    }
};