class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int startPtr = 0;
        int endPtr = nums.size()-1;
        int count = 0;
        
        while(startPtr < endPtr) {
            
            if(nums[startPtr]==val) {
                swap(nums[startPtr],nums[endPtr]);
                // startPtr++;
                endPtr--;
            } else {
                startPtr++;
            }
            
            
        
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=val) {
                count++;
            } else {
                break;
            }
        }
        
        return count;
        
    }
};