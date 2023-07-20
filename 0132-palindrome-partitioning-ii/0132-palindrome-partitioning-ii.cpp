// class Solution {
// public:
    
//     bool isPalindrome(string &s,int i,int j) {
      
//         while(i<=j) {
//             if(s[i]!=s[j]) {
//                 return false;
//             }
//             i++;
//             j--;
//         }
        
//         return true;
//     }
    
//     int f(int i,int n,string &s,vector<int> &dp) {
//         if(i==n) return 0;
//         int minCost = INT_MAX;
//         if(dp[i]!=-1) return dp[i];
//         for(int j=i; j<n; j++) {
//             if(isPalindrome(s,i,j)) {
//                int cost = 1+f(j+1,n,s,dp);
//                 minCost = min(minCost,cost);
//             }
//         }
//         return dp[i]=minCost;
//     }
//     int minCut(string s) {
//         vector<int> dp(s.length(),-1);
//         return f(0,s.length(),s,dp)-1;
//     }
    


// };

class Solution {
public:
    bool isPalindrome(int i, int j, string& s)
    {
        while(i < j) 
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = (int)s.size();
        vector<int> dp(n+1,0);

        for(int i = n-1; i >= 0; i--)
        {
            int mini = INT_MAX;

            for(int j = i; j < n; j++)
            {
                if(isPalindrome(i,j,s)) 
                {
                    int cost = 1 + dp[j+1];
                    mini = min(mini,cost);
                }
            }

            dp[i] = mini;
        }

        return dp[0]-1;
    }
};