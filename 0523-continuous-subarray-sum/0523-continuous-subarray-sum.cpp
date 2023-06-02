class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        int sum = 0;
        mpp[0] = 0;
        for(int i=0; i<nums.size(); i++) {
            
            sum += nums[i];
           
            if(mpp.find(sum%k)==mpp.end()) {
                mpp[sum%k] = i+1;
            } else {
                if(mpp[sum%k] < i) {
                    return true;
                }
            }
            
        }
     
        return false;
        
    }
};