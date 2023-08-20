class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) {
                 nums[i]=1;
            } else if(nums[i]<0) {
                nums[i]=-1;
            } else {
                return 0;
            }
        }
        
        int res = 1;
        for(auto num : nums) {
            res *= num;
        }

        
        return res>0 ? 1 : -1;
    }
};