class Solution {
public:
    
    int lcs(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));


    for(int i=1; i<=n; i++) {

       for(int j=1; j<=m; j++) {
          
          if(str1[i-1]==str2[j-1]) {
              dp[i][j] = 1 + dp[i-1][j-1];
          } else {
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
       
       }
    
    }
    return dp[n][m];
    }
    int minInsertions(string s) {
        
        int n = s.length();
        string b = s;
        reverse(s.begin(),s.end());
        return n-lcs(b,s);
        
    }
};