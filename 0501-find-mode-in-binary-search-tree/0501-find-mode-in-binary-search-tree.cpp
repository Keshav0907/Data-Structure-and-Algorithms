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
    
    void inOrder(TreeNode* root,unordered_map<int,int> &mpp) {
        
        if(root==NULL) return;
        
        inOrder(root->left,mpp);
        mpp[root->val]++;
        inOrder(root->right,mpp);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mpp;
        vector<int> vec;
        int maximum = 0;
        inOrder(root,mpp);
        
        for(auto it: mpp) {
            maximum = max(maximum,it.second);
        }
        
        for(auto it : mpp) {
            if(it.second==maximum) vec.push_back(it.first);
        }
        
        return vec;
        
    }
};