int prime = 1e9+7;
class Solution {
public:
    
    int count(string &s,string &t,int i, int j,vector<vector<int>> &dp) {
      
        if(j==-1) {
            return 1;
        }
        
        if(i==-1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) {
            return dp[i][j] = count(s,t,i-1,j-1,dp) + count(s,t,i-1,j,dp);
        } 
        
        return dp[i][j] = count(s,t,i-1,j,dp);
        
        
    }
    
    int subsequenceCounting(string &s1, string &s2, int n, int m) {
  
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s1[i-1]==s2[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return dp[n][m];
} 
    
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        return subsequenceCounting(s,t,m,n);
    }
};