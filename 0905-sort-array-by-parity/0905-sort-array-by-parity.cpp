class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
     
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right) {
            
            if(nums[right]%2==0) {
                swap(nums[left],nums[right]);
                left++;
            } else {
                right--;
            }
        }
        
        return nums;
    }
};