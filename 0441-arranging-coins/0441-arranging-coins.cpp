class Solution {
public:
    int arrangeCoins(int n) {
        
        int i=1;
        while(n > 0) {
            if(n - i >= 0) {
                n -=i;
                i++;
            }else {
                break;
            }
        }
        return i-1;
        
    }
};