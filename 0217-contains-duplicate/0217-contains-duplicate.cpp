class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> s;
        
        for(auto x : nums) {
            s.insert(x);
        }
        
        return !(s.size()==nums.size());
        
    }
};