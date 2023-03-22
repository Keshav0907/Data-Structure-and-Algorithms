class Solution {
public:
    
    map<vector<int>,int> mpp;
    
    void solve(vector<int> nums,int i,vector<int> op) {
        
        if(i==nums.size()) {
            mpp[op]++;
            return;
        }
        
        op.push_back(nums[i]);
        solve(nums,i+1,op);
        op.pop_back();
        solve(nums,i+1,op);
           
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> op;
        sort(nums.begin(),nums.end());
        solve(nums,0,op);
        for(auto it : mpp ){
            res.push_back(it.first);
        }
        return res;
    }
};