class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
       int left = 0;
       int right =nums.size()-2;
        
        while(left <= right) {
            
            int mid = left + (right-left)/2;
            if(nums[mid]==nums[mid^1]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
            
        }
        
        return nums[left];
    }
};

  