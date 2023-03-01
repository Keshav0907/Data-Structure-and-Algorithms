class Solution {
public:
    int lastRemaining(int n) {
        
        bool left = true;
        int head = 1;
        int step = 1;
        int remain = n;
        
        while(remain >  1) {
            
            if(left || remain&1) {
                head += step;
            }
            
            step *=2;
            remain/=2;
            left=!left;
           
        }
        
        return head;
    }
};