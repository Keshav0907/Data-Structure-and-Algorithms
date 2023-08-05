class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double ans = INT_MIN;
        
        int i=0;
        int j=0;
        double sum = 0;
        while(j < nums.size()) {
            
            sum += nums[j];
            
            if(j-i+1==k) {
                
                if(sum/k > ans) {
                 ans = sum/(double)k;   
                }
                sum -= nums[i];
                i++;
            }
            
            j++;
        }
        
        return ans;
        
    }
};