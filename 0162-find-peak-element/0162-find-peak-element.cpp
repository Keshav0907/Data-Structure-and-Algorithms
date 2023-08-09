class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int start = 0;
        int end  = nums.size()-1;
        
         while(start<end){
            
            int midpoint = start + (end-start)/2;
            
          if(nums[midpoint]<nums[midpoint+1]){
                start = midpoint + 1;
            }else{
                end = midpoint;
            }
     
        
        }
        return start;
    }
};