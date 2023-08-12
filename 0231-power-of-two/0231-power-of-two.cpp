class Solution {
public:
    
    int countBits(int n) {
        
        int count = 0;
        
        while(n) {
            count++;
            n = n & (n-1);
        }
        
        
        return count;
        
    }
    
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return countBits(n)==1;
        
    }
};