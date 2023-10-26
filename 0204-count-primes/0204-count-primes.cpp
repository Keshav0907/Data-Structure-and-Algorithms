class Solution {
public:
        int countPrimes(int n) {
        int cnt = 0;  
        vector<bool> isPrime(n+1, true);  

        isPrime[0] = isPrime[1] = false;  
        
     
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;  
               
                for (int j = 2 * i; j < n; j += i) {
                  
                    isPrime[j] = false;
                }
                
            }
        }
        return cnt;  
    }
};