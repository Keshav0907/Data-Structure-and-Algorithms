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
    void preorder(TreeNode* root, string &ans){
        if(root==NULL) return;

        ans += to_string(root->val);
        // return if root is the leaf node
        if(root->left==NULL && root->right==NULL) return;

        ans.push_back('(');
        preorder(root->left, ans);
        ans.push_back(')');

        // Put opening parenthesis if right subtree exists
        if(root->right) ans.push_back('(');
        preorder(root->right, ans);
        // Put closing parenthesis if right subtree exists
        if(root->right) ans.push_back(')');
    }

    string tree2str(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }
};