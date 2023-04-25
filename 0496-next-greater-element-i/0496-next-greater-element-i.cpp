class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        
        stack<int> s;
        vector<int> ans;
        vector<int> res;
        unordered_map<int,int> mpp;
        
        for(int i=nums.size()-1; i>=0; i--) {
            
            while(!s.empty() && s.top()<nums[i]) {
                s.pop();
            }
            
            if(s.empty()) {
                ans.push_back(-1);
            } else { 
                
            ans.push_back(s.top());
                
            }
            
            s.push(nums[i]);
            
        }
        
        reverse(ans.begin(),ans.end());
        
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]] = ans[i];
        }
        
        for(auto x : findNums) {
            res.push_back(mpp[x]);
        }
        
        return res;
        
    }
};

