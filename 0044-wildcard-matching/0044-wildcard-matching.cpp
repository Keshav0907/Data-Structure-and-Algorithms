class Solution {
public:
    
//     int ifMatched(int i,int j,string s,string p,vector<vector<int>> &dp) {
        
//         if(i<0 && j<0) {
//             return true;
//         }
        
//         if(i<0 && j>=0) {
//             for(int k=0;k<=j; k++) {
//                 if(p[k]!='*') {
//                     return false;
//                 }
            
//             }
//             return true;
//         }
        
//         if(i>=0 && j<0) {
//             return false;
//         }
//         if(dp[i][j]!=-1) {
//             return dp[i][j];
//         }
//         if(s[i]==p[j] || p[j]=='?') {
//             return dp[i][j] = ifMatched(i-1,j-1,s,p,dp);
//         }  
//         if(p[j]=='*'){
//             return dp[i][j] = ifMatched(i,j-1,s,p,dp) || ifMatched(i-1,j,s,p,dp);
//         } else {
//                 return false;
//         }
        
    
        
//     }
//   bool isAllStars(string & S1, int i) {

//   // S1 is taken in 1-based indexing
//   for (int j = 1; j <= i; j++) {
//     if (S1[j - 1] != '*')
//       return false;
//   }
//       return true;
//   }
  
//   bool wildcardMatching(string & S1, string & S2) {

//   int n = S1.size();
//   int m = S2.size();

//   vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

//   dp[0][0] = true;

//   for (int j = 1; j <= m; j++) {
//     dp[0][j] = false;
//   }
//   for (int i = 1; i <= n; i++) {
//     dp[i][0] = isAllStars(S1, i);
//   }

//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= m; j++) {

//       if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
//         dp[i][j] = dp[i - 1][j - 1];

//       else {
//         if (S1[i - 1] == '*')
//           dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

//         else dp[i][j] = false;
//       }
//     }
//   }

//   return dp[n][m];

// }
//     bool isMatch(string s, string p) {
//         // return ifMatched(m-1,n-1,s,p,dp);
//         return wildcardMatching(p,s);
//     }
    
      bool isMatch(string s2, string s1) {

        int n = s1.size(), m = s2.size();
    
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        dp[0][0] = 1;
        for(int i = 1; i<=n; i++){
                bool b = true;
                for(int k = 0; k<i; k++){
                    if(s1[k] != '*'){
                        b = false;
                        break;
                    }
                }
                if(b) dp[i][0] = 1;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){         
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(s1[i-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];     
            }
        }

        return dp[n][m];
    }
};