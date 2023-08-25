// class Solution {
// public:
//     double new21Game(int n, int k, int maxPts) {
       
//         if(k==0) return 1.0;
        
//         if(n > k-1+maxPts) return 1.0;
        
//         int maxPoint = k - 1 + maxPts;
//         vector<double> dp(maxPoint+1,0.0);
//         dp[0]=1.0;
//         for(int i=1; i<=maxPoint; i++) {
            
//             for(int pt=1; pt<=maxPts; pt++) {
                
//                 if(i-pt>=0 && i-pt<k) {
                    
//                     dp[i] += dp[i-pt]*(1.0/maxPts);
                    
//                 }
                
                
//             }
            
//         }
        
//         double ans = 0.0;
        
//         for(int i=k; i<=n; i++) {
//             ans += dp[i];
//     }
        
//         return ans;
//     }
    
// };

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (n - k >= maxPts - 1 || k == 0)
            return 1.0;

        vector<double> possibility(n + 1);
        possibility[0] = 1.0;

        double rangeWindowProbability = 1.0;
        double resultProbability = 0.0;

        for (int i = 1; i < n + 1; ++i) {
            possibility[i] = rangeWindowProbability / maxPts;

            if (i < k)  rangeWindowProbability += possibility[i];
            else        resultProbability += possibility[i];

            if (i >= maxPts && i < maxPts + k) 
                rangeWindowProbability -= possibility[i - maxPts];
        }
        
        return resultProbability;
    }
};