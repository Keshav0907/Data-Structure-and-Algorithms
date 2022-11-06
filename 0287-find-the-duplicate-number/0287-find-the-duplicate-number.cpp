class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int i=0;
        while(i < nums.size()){
            
            int correctIdx = nums[i]-1;
            if(nums[i]!=nums[correctIdx]) {
                swap(nums[i],nums[correctIdx]);
            } else {
                i++;
            }
            
        }
        
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=i+1) {
                return nums[i];
            }
        }
        
        return -1;
        
    }
};