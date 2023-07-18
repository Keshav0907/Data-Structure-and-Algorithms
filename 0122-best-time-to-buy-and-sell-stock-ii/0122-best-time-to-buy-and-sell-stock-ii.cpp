class Solution {
public:
    
    int maxScore(int index,int buy,vector<int> &prices,int n,vector<vector<int>> &dp) {
        if(index==n) return 0;
        int profit = 0;
        if(dp[index][buy]!=-1) {
            return dp[index][buy];
        }
        if(buy) {
            profit = max(-prices[index]+maxScore(index+1,0,prices,n,dp),maxScore(index+1,1,prices,n,dp));
        } else {
            profit = max(prices[index]+maxScore(index+1,1,prices,n,dp),maxScore(index+1,0,prices,n,dp));
        }
        
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return maxScore(0,1,prices,prices.size(),dp);
    }
};