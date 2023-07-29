class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       
        int freq =   nums.size()/3;
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(auto it: nums) {
            mpp[it]++;
        }
        
        for(auto it : mpp) {
            if(it.second>freq) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};