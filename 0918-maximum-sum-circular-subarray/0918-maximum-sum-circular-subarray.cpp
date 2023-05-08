class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int curr_min_sum = 0;
        int curr_max_sum = 0;
        int arrSum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            
            curr_min_sum += nums[i];
            curr_max_sum +=nums[i];
            arrSum += nums[i];
            
            minSum = min(curr_min_sum,minSum);
            maxSum = max(curr_max_sum,maxSum);
            
            if(curr_min_sum > 0) {
                curr_min_sum = 0;
            } 
            if(curr_max_sum < 0){
                curr_max_sum = 0;
            }
            
        }
        
        if(arrSum==curr_min_sum) {       // if all val are negative
         return maxSum;   
        }
        
        return max(maxSum,arrSum-minSum);
    }
};