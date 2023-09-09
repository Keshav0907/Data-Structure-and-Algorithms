class Solution {
public:
    
    int solve(int idx,int n,vector<int> &dp,vector<int> &stoneValue) {
        
        if(idx>=n) return 0;
        int diff = INT_MIN;
        if(dp[idx]!=-1) return dp[idx];
        
        diff = max(stoneValue[idx]-solve(idx+1,n,dp,stoneValue),diff);
        if(idx+1 < n) {
            diff = max(stoneValue[idx]+stoneValue[idx+1]-solve(idx+2,n,dp,stoneValue),diff);
        }
        if(idx+2 < n) {
            diff = max(stoneValue[idx]+stoneValue[idx+1]+stoneValue[idx+2] - solve(idx+3,n,dp,stoneValue),diff);
        }
        
        return dp[idx]=diff;
    }
    
    
    string stoneGameIII(vector<int>& stoneValue) {
     
        int n = stoneValue.size();
        vector<int> dp(n+1,-1);
        int result = solve(0,n,dp,stoneValue);
        if(result==0) {
            return "Tie";
        } else if(result > 0) {
            return "Alice";
        }
        
        return "Bob";
    }
};