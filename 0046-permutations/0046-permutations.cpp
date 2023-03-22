class Solution {
public:
    
    void solve(int idx,vector<int> &nums,vector<vector<int>> &res) {
        
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,res);    // no need to backtrack in  next step as i do not pass nums by reference
            swap(nums[idx],nums[i]);
        }                               
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        solve(0,nums,res);
        
        return res;
    }
};