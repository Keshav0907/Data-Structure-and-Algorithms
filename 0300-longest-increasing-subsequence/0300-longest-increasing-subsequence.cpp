class Solution {
public:
    
    int longest(int index,int prevIdx,vector<int> nums,vector<vector<int>> &dp) {
        
        if(index==nums.size()) {
            return 0;
        }
        
        if(dp[index][prevIdx+1]!=-1) return dp[index][prevIdx+1];
        int len = longest(index+1,prevIdx,nums,dp);
   
        if(prevIdx==-1 || nums[prevIdx]<nums[index]) {
            len = max(len,1 + longest(index+1,index,nums,dp));
        }
        
        return dp[index][prevIdx+1] = len;
    }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<vector<int>> dp(nums.size(),vector<int> (nums.size()+1,-1));
    //     return longest(0,-1,nums,dp);
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n + 1, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

};