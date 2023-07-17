class Solution {
public:
    
    string lcs(int m,int n,string str1,string str2) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1; i<m+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        
        int i = m;
        int j = n;
        string str;
        
        while(i>0 && j>0) {
            
            if(str1[i-1]==str2[j-1]) {
                str.push_back(str1[i-1]);
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                
                str.push_back(str1[i-1]);
                i--;
            } else{
                str.push_back(str2[j-1]);
                j--;
            }
            
            
        }
        
        while(i>0){
            str.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0){
            str.push_back(str2[j-1]);
            j--;
        }
        
        reverse(str.begin(),str.end());
        return str;
    }
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        return lcs(m,n,str1,str2);
    }
};