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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL) return paths;
        dfs(root, to_string(root->val), paths);
        return paths;
    }
    
    void dfs(TreeNode* root, string path, vector<string> &paths){
       
        if(root -> left == NULL && root -> right == NULL) {
            paths.push_back(path);
            return;
        }
        if(root->left != NULL) dfs(root->left, path + "->" + to_string(root->left->val), paths);
        if(root->right != NULL) dfs(root->right, path + "->" + to_string(root->right->val) , paths);
    }
};