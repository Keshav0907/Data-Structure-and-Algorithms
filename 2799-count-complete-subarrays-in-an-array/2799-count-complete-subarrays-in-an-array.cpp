class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());
        int size = st.size();
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            st.clear();
            for(int j=i; j<nums.size(); j++) {
                st.insert(nums[j]);
                if(st.size()==size) ans++;
                
             }
            
        }
        
        
        return ans;
        
    }
};