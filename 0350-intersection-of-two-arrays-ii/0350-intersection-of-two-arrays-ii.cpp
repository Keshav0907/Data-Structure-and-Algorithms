class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

         
        unordered_map<int,int> mpp;
        
        for(auto el : nums1) {
            mpp[el]++;
        }
        vector<int> ans;
        
        for(auto el : nums2) {
            
            if(mpp.find(el)!=mpp.end()) {
                mpp[el]--;
                if(mpp[el]==0) mpp.erase(el);
                ans.push_back(el);
            }
            
        }
        
        return ans;
    }
};