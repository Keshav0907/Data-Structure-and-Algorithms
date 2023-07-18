class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int maximumProfit = 0;
       int minLeft = prices[0];
       
       for(int i=1; i<prices.size(); i++) {
           int cost = prices[i] - minLeft;
           maximumProfit = max(maximumProfit,cost);
           minLeft = min(minLeft,prices[i]);
       }
        
       return maximumProfit;
    }
};