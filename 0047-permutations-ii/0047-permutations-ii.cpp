class Solution {
public:
    
    void solve(int index,vector<int> nums,set<vector<int>> &s) {
        
        if(index==nums.size()) {
            s.insert(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++) {
            
            swap(nums[index],nums[i]);
            solve(index+1,nums,s);
            
        }
        
        
        
        
        
    }
    
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res;
        set<vector<int>> s;
        solve(0,nums,s);
        
        for(auto vec : s) {
            res.push_back(vec);
        }
        
        return res;
        
    }
};