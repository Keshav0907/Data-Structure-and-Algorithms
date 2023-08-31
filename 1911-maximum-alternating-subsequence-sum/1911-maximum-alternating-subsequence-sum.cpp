class Solution {
public:
    
    long long solve(int i,vector<int> &nums,int flag,vector<vector<long long>> &dp) {
        
        if(i==nums.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        long long op1 = solve(i+1,nums,flag,dp);
        long long op2;
        if(flag){
            op2 = nums[i] + solve(i+1,nums,!flag,dp);
        } else {
            op2 = -nums[i] + solve(i+1,nums,!flag,dp);
        }
        return dp[i][flag]=max(op1,op2);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        
        return solve(0,nums,1,dp);
        
    }
};