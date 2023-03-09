class Solution {
public:
    
    int mod = 1000000007;
    
    long long power(long long val, long long pow) {
        if(pow==0) {
            return 1;
        }
        
//         long long subProb = power(x,a/2);
//         long long subProbsq = (subProb*subProbsq)%mod;
        
//         if(a&1) {
//             return (x*subProbsq)%mod;
//         }
        
//         return subProbsq%mod;
        if(pow%2==0){
            return power((val*val)%mod,pow/2)%mod;
        }
        else
            return (val*power((val*val)%mod,pow/2))%mod;
    }
    
    int countGoodNumbers(long long n) {
        
        long long pow = n/2;
        long long ans = power(20,n/2);
        
        if(n&1) {
            return ((5*ans)%mod);
        }
        
        return ans%mod;
        
    }
};