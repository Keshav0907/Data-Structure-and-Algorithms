class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int left = 0;
        int right = 1;
        
        while(left<nums.size() && right<nums.size()) {
            
            while(left<nums.size() && nums[left]%2==0) {
                left+=2;
            }
            
            while(right<nums.size() && nums[right]%2==1) {
                right+=2;
            }
          
            if(left<nums.size() && right<nums.size()) swap(nums[left],nums[right]);
          
        }
        return nums;
    }
};