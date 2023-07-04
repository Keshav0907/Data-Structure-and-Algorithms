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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        
        map<int,int> mpp;
        
        for(int i=0; i<inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        
        return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        
    }
    TreeNode* buildTreePostIn(vector<int> inorder,int inStart,int inEnd,vector<int> postorder,int poStart,int poEnd,map<int,int> &mpp) {
    
    if(poStart>poEnd || inStart>inEnd) return NULL;
    
    TreeNode* root = new TreeNode(postorder[poEnd]);
    
    int inRoot = mpp[postorder[poEnd]];
    int numLeft = inRoot-inStart;
    
    root->left = buildTreePostIn(inorder,inStart,inRoot+1,postorder,poStart,poStart+numLeft-1,mpp);
    root->right = buildTreePostIn(inorder,inRoot+1,inEnd,postorder,poStart+numLeft,poEnd-1,mpp);
    return root;
}
};

