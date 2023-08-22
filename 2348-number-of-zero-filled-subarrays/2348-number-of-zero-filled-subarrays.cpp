class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     
        long long count = 0;
        int n = nums.size();
        int j=0;
        int i=0;
        while(j < n) {
            
            if(nums[j]!=0) {
                i = j+1;
            }
            
         count += (j-i+1);
         j++;
        }
        
        return count;
    }
};