class Solution {
public:
    int solve(int n,vector<int> &dp) {
        
        int ans = INT_MAX;
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1; i*i<=n ;i++) {
            int  num = i*i;
            int count = 1 + solve(n-num,dp);
            ans = min(ans,count);
        }
        
        return dp[n]=ans;
    }
    
      int numSquares(int n) {
        vector<int> dp(10001,-1);
        return solve(n,dp);
    }
};
