class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 2;
        
        // finding first decreasing element
        
        while(i>=0 && nums[i+1] <= nums[i]) {
            i--;
        }
            
            
        if(i >= 0) {
            
            int j = nums.size()-1;
             // find element j which is just greater than element i;
            while(nums[j] <=nums[i]) {
                j--;
            }
            
            swap(nums[j],nums[i]);
            
        }
        
        
          
        
        // reverse the array to right of i index to get next permutation  
        reverse(nums.begin()+i+1 ,  nums.end());
       
        
    }
};