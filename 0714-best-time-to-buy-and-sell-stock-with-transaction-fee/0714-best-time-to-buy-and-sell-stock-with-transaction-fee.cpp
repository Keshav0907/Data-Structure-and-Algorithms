class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
       
        for(int index=prices.size()-1; index>=0; index--) {
          for(int buy=0; buy<=1; buy++) {
            int profit = 0;
               if(buy) {
                   profit = max(-prices[index]+dp[index+1][0] ,dp[index+1][1]);
               } else {
                   profit = max(prices[index]+dp[index+1][1]-fee,dp[index+1][0]);
              }
              dp[index][buy] = profit;
       }
    }
       
        return dp[0][1];
    }
};