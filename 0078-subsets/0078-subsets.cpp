class Solution {
public:
    
    void solve(vector<int> nums,int i,vector<vector<int>> &res,vector<int> &op)    {
        
        if(i==nums.size()) {
            res.push_back(op);
            return;
        }
        
        // vector<int> op1 = op;
        // vector<int> op2 = op;
        op.push_back(nums[i]);
        solve(nums,i+1,res,op);
        op.pop_back();
        solve(nums,i+1,res,op);
        
       
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> ans;
        solve(nums,0,res,ans);
        return res;
    }
};