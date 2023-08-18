class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
     
        int res = INT_MIN;
        int maxCount = INT_MIN;
        
        for(auto ele : divisors) {
            int count = 0;
            
            for(auto ele2 : nums) {
                
                if(ele2%ele==0) {
                    count++;
                }   
                
                if(count > maxCount) {
                    maxCount = count;
                    res = ele;
                }
                
                if(count==maxCount) {
                    res = min(ele,res);
                }
           }
        
        }
        
        return res;
        
    }
};