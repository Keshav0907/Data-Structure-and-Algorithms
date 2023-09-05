class Solution {

    private:
    
    bool solve(vector<int> &nums,int i,vector<int> &dp) {
        
        int n = nums.size();
        if(i==nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        
        if(i+1 < n && nums[i+1]==nums[i]) {
            
            if(solve(nums,i+2,dp)) {
                return dp[i]=true;
            }
            
            if(nums[i]==nums[i+2]) {
                
                if(solve(nums,i+3,dp)) {
                    return dp[i]=true;
                }
                
            }
            
        }
        
        if(i+2<n && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2) {
            
            if(solve(nums,i+3,dp)) {
                return dp[i]=true;
            }
        }
        
        return dp[i]=false;
    }
    
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
    }
};