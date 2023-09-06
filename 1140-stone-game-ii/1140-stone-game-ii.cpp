class Solution {
public:
    
    int n;
    int dp[2][101][101];
    int solve(int i,int person,vector<int> &piles,int M) {
        
        if(i>=n)
            return 0;
        
        if(dp[person][i][M]!=-1) return dp[person][i][M];
        
        int result = person==1 ? -1 : INT_MAX;
        int stones = 0;
        for(int x=1; x<=min(2*M,n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person) {
                result = max(result,stones + solve(i+x,!person,piles,max(M,x)));
            } else {
                result = min(result,solve(i+x,!person,piles,max(M,x)));
            }
            
        }
        return dp[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,piles,1);
    }
};