class Solution {
public:
    
    int minCost(int i,int j,int finalRow,vector<vector<int>> &triangle,vector<vector<int>> &dp) {
        
        if(i==finalRow) return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j] + minCost(i+1,j,finalRow,triangle,dp);
        int dia = triangle[i][j] + minCost(i+1,j+1,finalRow,triangle,dp);
        
        return dp[i][j] = min(down,dia);
        
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int finalRow = triangle.size()-1;
        vector<vector<int>> dp(triangle.size(),vector<int> (triangle[finalRow].size(),-1));
        return minCost(0,0,finalRow,triangle,dp);
        
    }
};