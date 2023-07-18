class Solution {
public:
    
//     int maxScore(int index,int buy,vector<int> &prices,int n,vector<vector<int>> &dp) {
//         if(index==n) return 0;
//         int profit = 0;
//         if(dp[index][buy]!=-1) {
//             return dp[index][buy];
//         }
//         if(buy) {
//             profit = max(-prices[index]+maxScore(index+1,0,prices,n,dp),maxScore(index+1,1,prices,n,dp));
//         } else {
//             profit = max(prices[index]+maxScore(index+1,1,prices,n,dp),maxScore(index+1,0,prices,n,dp));
//         }
        
//         return dp[index][buy] = profit;
//     }
    
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for(int index=prices.size()-1; index>=0; index--) {
          for(int buy=0; buy<=1; buy++) {
            int profit = 0;
               if(buy) {
                   profit = max(-prices[index]+dp[index+1][0] ,dp[index+1][1]);
               } else {
                   profit = max(prices[index]+dp[index+1][1],dp[index+1][0]);
              }
              dp[index][buy] = profit;
       }
    }
        // return maxScore(0,1,prices,prices.size(),dp);
        return dp[0][1];
    }
};