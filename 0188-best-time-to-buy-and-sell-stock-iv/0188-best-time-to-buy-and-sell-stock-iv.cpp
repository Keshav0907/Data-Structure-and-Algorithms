class Solution {
public:
    int f(int ind , int bs , vector<int>& prices,  vector<vector<vector<int>>>& dp , int t,int k)
    {
        if(t==k) return 0;
        if(ind>=prices.size()) return 0;
        if(dp[ind][bs][t]!=-1) return dp[ind][bs][t];
        int notTake = f(ind+1 , bs , prices ,  dp,t,k);
        int take =0;
        if(bs==0)
        {
            take = f(ind+1 , 1 , prices ,  dp , t,k) - prices[ind];
        }
        else
        {
            take = prices[ind]+f(ind+1 , 0 , prices ,  dp , t+1,k);
        }
        return dp[ind][bs][t]=max(take , notTake);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(2 , vector<int>(k,-1)));
        return f(0,0,prices,dp,0 ,k);
    }
};