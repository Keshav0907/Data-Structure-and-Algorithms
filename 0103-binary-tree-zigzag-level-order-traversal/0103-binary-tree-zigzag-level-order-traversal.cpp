class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)return {};
        vector<vector<int>> ans;
        vector<int> v;
        int n,k=0;
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        while(!q.empty()){
            n = q.size();
            v.clear();
            while(n--){
                p = q.front();
                q.pop();
                v.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }if(p->right){
                    q.push(p->right);
                }
            }
          

            if(k==1)reverse(v.begin(),v.end());
            ans.push_back(v);
            if(k==0){k=1;}
            else {k=0;}
        }
        return ans;
    }
};