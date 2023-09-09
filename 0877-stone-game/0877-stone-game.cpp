class Solution {
public:
    
    int solve(int i,int j,vector<int> &piles,vector<vector<int>> &dp) {
        
        if(i>=piles.size()) return 0;
        if(j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int takeI = piles[i] + max(solve(i+2,j,piles,dp),solve(i+1,j-1,piles,dp));
        int takeJ = piles[j] + max(solve(i+1,j-1,piles,dp),solve(i,j-2,piles,dp));
        
        return dp[i][j] = max(takeI,takeJ);
        
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        int sum = 0;
        for(auto el: piles) {
            sum +=el;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        int result = solve(0,n-1,piles,dp);
        int rem = sum - result;
        return result > rem;
    }
};