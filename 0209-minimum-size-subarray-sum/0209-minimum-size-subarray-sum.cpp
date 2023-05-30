class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int sum = 0;
        
       while(j < nums.size()) {
         
           sum += nums[j];
           
           if(sum==target) {
               ans = min(ans,j-i+1);
           } else if(sum > target) {
             
               while(sum >= target) {
             
                   ans = min(ans,j-i+1);
                   sum = sum - nums[i];
                   i++;
                   
               }
               
           }
           
           j++;
           
        }
        
        return ans==INT_MAX ? 0 : ans;
        
    }
};