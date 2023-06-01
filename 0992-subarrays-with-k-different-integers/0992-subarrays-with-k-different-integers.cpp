class Solution {
public:
    
    int atMostK(vector<int> &nums,int k) {
        
        int i=0;
        int j=0;
        unordered_map<int,int> mpp;
        int ans = 0;
        
        while(j < nums.size()) {
            
            mpp[nums[j]]++;
            if(mpp.size() <= k){
                ans += (j-i+1);
            } else {
                while(mpp.size()>k) {
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                    i++;
                }
              ans += (j-i+1);  
            } 
            j++;
            
        }
        
        return ans;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
            
        return atMostK(nums,k) - atMostK(nums,k-1);
        
    }
    
};