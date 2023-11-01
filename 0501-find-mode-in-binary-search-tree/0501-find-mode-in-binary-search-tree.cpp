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
    
    vector<int> result;
    int currNum = 0;
    int currFreq = 0;
    int maxFreq = 0;
    
    void inOrder(TreeNode* root) {
        
        if(root==NULL) return;
        inOrder(root->left);
        if(root->val==currNum) {
            currFreq++;
        } else {
            currNum = root->val;
            currFreq = 1;
        }
        
        if(currFreq > maxFreq) {
            result = {};
            maxFreq = currFreq;
        }
        
        if(currFreq==maxFreq) {
            result.push_back(currNum);
        }
        inOrder(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
     
        inOrder(root);
        return result;
        
    }
};