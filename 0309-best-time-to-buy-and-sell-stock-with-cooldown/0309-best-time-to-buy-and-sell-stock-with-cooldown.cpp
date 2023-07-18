class Solution {
public:
    
    int maxCost(int index,int buy,int prev,vector<int> prices,int n, vector<vector<vector<int>>> &dp) {
        
        if(index==n) {
            return 0;
        }
        if(prev==0) {
            return dp[index][buy][prev] = maxCost(index+1,buy,1,prices,n,dp);
        }
        if(dp[index][buy][prev]!=-1) return dp[index][buy][prev];
        int price;
        if(buy) {
            price = max(-prices[index]+maxCost(index+1,0,1,prices,n,dp),maxCost(index+1,1,1,prices,n,dp));
        } else {
            price = max(prices[index]+maxCost(index+1,1,0,prices,n,dp),maxCost(index+1,0,1,prices,n,dp));   
        }
        return dp[index][buy][prev] = price;
    }
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int>(2,-1)));
        
        return maxCost(0,1,1,prices,prices.size(),dp);
        
    }
};