class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> st(nums1.begin(),nums1.end());
        vector<int> ans;
        
        for(auto el : nums2) {
            
            if(st.find(el)!=st.end()) {
                st.erase(el);
                ans.push_back(el);
            }
            
        }
        
        return ans;
    }
};