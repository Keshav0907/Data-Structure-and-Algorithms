class Solution {
public:
    
     int maxRob(vector<int>& nums) {
        int size = nums.size();

        vector<int> dp(size);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2; i<size; i++) {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
       
        return dp[size-1];
        
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> temp1,temp2;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
            
        }
        return max(maxRob(temp1),maxRob(temp2));
    }
};