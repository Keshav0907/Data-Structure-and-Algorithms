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
// class Solution {
// public:
    
//     void traverseTree(TreeNode* root,int d,map<int,vector<int>> &mpp) {
        
//         if(root==NULL) return;
        
//         mpp[d].push_back(root->val);
//         traverseTree(root->left,d-1,mpp);
//         traverseTree(root->right,d+1,mpp);
//     }
    
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
         
//         map<int,vector<int>> mpp;
        
//         int d = 0;
        
//         traverseTree(root,d,mpp);
//         vector<vector<int>> ans;
//         for(auto p : mpp) {
            
//             int key = p.first;
//             vector<int> line = p.second;
//             // sort(line.begin(),line.end());
//             if(key==0) {
//                 sort(line.begin()+1,line.end());
//             }
//             ans.push_back(line);
            
//         }
        
//         return ans;
        
//     }
// };
class Solution {
public:

    

    void traversal(TreeNode* root,int x,int y,map<int,map<int,vector<int>>>&mp){

      if(root==NULL){ return; }
        mp[x][y].push_back(root->val); 

        traversal(root->left,x-1,y+1,mp);
        traversal(root->right,x+1,y+1,mp);

        return; 

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

       map<int, map<int,vector<int>>> mp; 

        traversal(root,0,0,mp); 

         vector<vector<int>>answer; 

         for(auto it= mp.begin();it!=mp.end();it++){

            map<int,vector<int>>temp=it->second;
            vector<int>pusher; 

              for(auto iter=temp.begin();iter!=temp.end();iter++){

                 vector<int>vec=iter->second;
                 sort(vec.begin(),vec.end()); 
                   int size=vec.size();
                   for(int i{0};i<size;i++){
                     pusher.push_back(vec[i]); 
                   }

              }
             answer.push_back(pusher); 
         }

         return  answer; 
        
    }
};