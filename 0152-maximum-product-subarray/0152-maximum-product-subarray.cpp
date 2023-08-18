class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int res = INT_MIN;
        
        int pref = 1;
        int suff = 1;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            
            pref *= nums[i];
            suff *= nums[nums.size()-i-1];
            
            res = max(pref,max(suff,res));
            
        }
        
        return  res;
    }
};