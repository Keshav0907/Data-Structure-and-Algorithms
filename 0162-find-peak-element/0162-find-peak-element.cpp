class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
//         int start = 0;
//         int end  = nums.size()-1;
        
//          while(start<end){
            
//             int midpoint = start + (end-start)/2;
            
//           if(nums[midpoint]<nums[midpoint+1]){
//                 start = midpoint + 1;
//             }else{
//                 end = midpoint;
//             }
     
        
//         }
//         return start;
        
        int n = nums.size();
        if(n==1) {
            return 0;
        }
        
        if(nums[0] > nums[1]) {
            return 0;
        }
        
        if(nums[n-1] > nums[n-2]) {
            return n-1;
        }
        
        
        int low = 1;
        int high = n-2;
        
        while(low<=high) {
            
            int mid = low + (high-low)/2;
            
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            } else {
                if(nums[mid+1] > nums[mid]) {
                    low = mid+1;
                } else {
                    high=  mid-1;
                }
            }
            
        }
        
        return -1;
        
    }
};