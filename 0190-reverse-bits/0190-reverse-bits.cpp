class Solution {
public:
    
    bool isSet(int k,int n) {
        
       if(((1<<(k-1))&n)!=0) return true;
        return false;
        
    }
    
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans = 0;
        
        for(int i=1; i<=32; i++) {
            
            if(isSet(i,n)) {
                ans = 1 << (32-i) | ans;
            }
        }
        return ans;
    }
};