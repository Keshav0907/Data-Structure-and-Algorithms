class Solution {
public:
// top-down    
//     bool isPossible(vector<int> nums,int n,int sum) {
        
//         if(sum==0) {
//             return true;
//         }
//         if(n==0) {
//             return false;
//         }
     
//         if(nums[n] <= sum) {
//             return isPossible(nums,n-1,sum) || isPossible(nums,n-1,sum-nums[n]);
//         }
//         return isPossible(nums,n-1,sum);
        
//     }
    
     bool isPossible(vector<int> nums,int n,int sum) {
        
         vector<vector<int>> dp(n+1,vector<int>(sum+1));
         
         for(int i=0; i<n+1; i++) {
             for(int j=0; j<sum+1; j++) {
                 if(i==0) dp[i][j] = false;
                 if(j==0) dp[i][j] = true;
             }
         }
         
         for(int i=1; i<n+1; i++) {
             for(int j=1; j<sum+1; j++) {
                 if(nums[i-1]<=j) {
                     dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                 } else {
                     dp[i][j] = dp[i-1][j];
                 }
             }
         }
      
        return dp[n][sum];
     }
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(auto x : nums) {
            sum += x;     
        }
        
        if(sum%2!=0) {
            return false;
        }
        
        return isPossible(nums,nums.size()-1,sum/2);
     }
};