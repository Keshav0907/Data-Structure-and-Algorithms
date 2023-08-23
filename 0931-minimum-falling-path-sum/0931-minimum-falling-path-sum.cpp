class Solution {
public:
    
    int minSum(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &matrix,int m,int n) {
        
        if(i >=m || j>=n || i<0 || j<0) {
            return 1e9;
        }
        if(i==m-1) {
            return matrix[i][j];
        }
        
        if(dp[i][j]!=-200) {
            return dp[i][j];
        }

        int down = matrix[i][j] + minSum(i+1,j,dp,matrix,m,n);
        int leftDia = matrix[i][j] + minSum(i+1,j-1,dp,matrix,m,n);
        int rightDia = matrix[i][j] + minSum(i+1,j+1,dp,matrix,m,n);
        
        return dp[i][j] = min(leftDia,min(rightDia,down));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-200));
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
          int cost =  minSum(0,i,dp,matrix,m,n);  
          ans = min(ans,cost);
        }
       
        return ans;
                
    }
};