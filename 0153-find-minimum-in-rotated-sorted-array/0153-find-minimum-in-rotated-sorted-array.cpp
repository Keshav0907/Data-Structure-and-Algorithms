class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int N = nums.size();
        
        int start = 0;
        int end = N-1;
        
        while(start < end) {
            
            int mid = start + (end-start)/2;
            
            if(nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        
        }
        
        return nums[start];
        
    }
};