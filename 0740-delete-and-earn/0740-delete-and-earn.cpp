class Solution {
public:
    
     int helper(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return nums[0];
        vector<int> dp(size);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2; i<size; i++) {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
       
        return dp[size-1];
    
    }
    int deleteAndEarn(vector<int>& nums) {
        
        int maxElement = *max_element(nums.begin(),nums.end());
        vector<int> res(maxElement+1,0);
        
        for(int i=0; i<nums.size(); i++) {
            res[nums[i]] += nums[i];
        }
            
        
        return helper(res);
    }
};