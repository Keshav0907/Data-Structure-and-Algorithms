class Solution {
public:
    
    long solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp) {
        
        if(i>j) return 0;
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        int ans = INT_MIN;
        
        for(int k=i; k<=j; k++) {
            
            int cost = (nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums,dp) + solve(k+1,j,nums,dp));
            ans = max(cost,ans);
            
        }
        
        return dp[i][j] = ans;
        
        
    }

    
    int maxCoins(vector<int>& nums) {
        
      int size = nums.size();
      nums.push_back(1);
      nums.insert(nums.begin(),1);
      vector<vector<int>> dp(size+1,vector<int>(size+1,-1));
        
      return solve(1,size,nums,dp);
        
        
        
    }
};