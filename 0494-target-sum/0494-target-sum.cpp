class Solution {
public:
    
    int count(vector<int> nums,int sum) {
        
        int m = nums.size();
        
        vector<vector<int>> dp(m+1,vector<int>(sum+1));
        
        for(int i=0; i<m+1; i++) {
            for(int j=0; j<sum+1; j++) {
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1; i<m+1; i++) {
            for(int j=0; j<sum+1; j++) {
                if(nums[i-1]<=j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        if((sum+target)%2!=0 || sum<target) return 0;
        if((sum+target)/2<0) return 0;
        return count(nums,(sum+target)/2);
    }
};

