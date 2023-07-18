class Solution {
public:
    
    int maxScore(int index,int buy,int numTranx,vector<int> &prices,int n,vector<vector<vector<int>>> &dp) {
        if(index==n) {
            return 0;
        }
        if(numTranx==0) {
            return 0;
        }
        if(dp[index][buy][numTranx]!=-1) return dp[index][buy][numTranx];
        int price;
        if(buy) {
            price = max(-prices[index]+maxScore(index+1,0,numTranx,prices,n,dp),maxScore(index+1,1,numTranx,prices,n,dp));
        } else {
            price = max(prices[index] + maxScore(index+1,1,numTranx-1,prices,n,dp),maxScore(index+1,0,numTranx,prices,n,dp));
        }
        return dp[index][buy][numTranx]=price;
    }
    
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return maxScore(0,1,2,prices,prices.size(),dp);
        
    }
};