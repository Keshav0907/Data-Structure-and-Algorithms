class Solution {
public:
    int arrangeCoins(int n) {
        
//         int i=1;
//         while(n > 0) {
//             if(n - i >= 0) {
//                 n -=i;
//                 i++;
//             }else {
//                 break;
//             }
//         }
//         return i-1;
        
        long left = 0;
        long right = n;
        while(left <= right) {
            
            long mid = left + (right-left)/2;
            long curr = mid*(mid+1)/2;
            
            if(curr==n) {
                return (int)mid;
            }
            
            if(n < curr) {
                right = mid-1;
            } else {
                left = mid+1;
            }
            
        }
        
        return right;
        
    }
};