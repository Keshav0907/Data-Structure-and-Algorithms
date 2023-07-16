class Solution {
public:
       int countWays(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &obstacle) {
       
       if(i>=0 && j>=0 && obstacle[i][j]==1) {
           return 0;
       }
  
        if(i==0 && j==0) {
            return 1;
        }
        
        if(i<0 || j<0) {
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = countWays(i,j-1,dp,obstacle) + countWays(i-1,j,dp,obstacle);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return countWays(m-1,n-1,dp,obstacleGrid);
    }
};