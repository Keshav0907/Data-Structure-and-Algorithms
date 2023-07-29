class Solution {
public:
    int majorityElement(vector<int>& nums) {
      
        int count = 0;
        int ele;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(count==0) {
                count = 1;
                ele = nums[i];
            } else if(ele==nums[i]) {
                count++;
            } else {
                count--;
            }
            
        }
        count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(ele==nums[i]) {
                count++;
            }
        }
      
        if(count > nums.size()/2) return ele;
        
        return -1;
    }
};