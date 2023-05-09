class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int lastGoodpos = nums.size()-1;
        
        for(int i=nums.size()-1; i>=0; i--) {
            if(i+nums[i] >= lastGoodpos) {
                lastGoodpos = i;
            }
        }
        return lastGoodpos==0;
    }
};