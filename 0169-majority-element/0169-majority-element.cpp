class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
           unordered_map<int,int> mpp;
        int ans = INT_MAX;
    
    for(auto x: nums) {
        mpp[x]++;
    }
    
    for(auto it: mpp) {
        if(it.second > nums.size()/2){
            ans = it.first;
        }
    }
    
    return ans;
        
    }
};