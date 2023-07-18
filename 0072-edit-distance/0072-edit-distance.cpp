class Solution {
public:
    
//     int minOps(int i,int j,string s1,string s2,vector<vector<int>> &dp) {
        
//         if(i < 0) {
//             return j+1;
//         }
        
//         if(j < 0) {
//             return i+1;
//         }
        
//         if(s1[i]==s2[j]) {
//             return dp[i][j] = minOps(i-1,j-1,s1,s2,dp);
//         }
        
//         return dp[i][j] = 1 + min(minOps(i-1,j,s1,s2,dp),min(minOps(i-1,j-1,s1,s2,dp),minOps(i,j-1,s1,s2,dp)));    
        
//     }
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0; i<=m; i++) {
            dp[i][0] = i;
        }
        
        for(int j=0; j<=n; j++) {
            dp[0][j] = j;
        }
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
        // return minOps(m-1,n-1,word1,word2,dp);
    }
};