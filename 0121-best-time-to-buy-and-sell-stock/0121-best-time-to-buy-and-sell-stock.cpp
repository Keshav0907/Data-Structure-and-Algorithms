class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minimumtoLeft = prices[0];
        int cost = 0;
        int maximumProfit = 0;
        int n = prices.size();
        for(int i=1; i<n; i++) {
            cost = prices[i]-minimumtoLeft;
            maximumProfit = max(maximumProfit,cost);
            minimumtoLeft = min(minimumtoLeft,prices[i]);
        }
        
        return maximumProfit;
    }
};