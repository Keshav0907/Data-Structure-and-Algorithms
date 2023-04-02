class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> leftProduct(nums.size(),0);
        vector<int> rightProduct(nums.size(),0);
        
        leftProduct[0] = 1;
        rightProduct[nums.size() - 1] = 1;
        
        
        for(int i=1; i<nums.size(); i++) {
            leftProduct[i] = leftProduct[i-1]*nums[i-1];
        }
        
        for(int i=nums.size()-2; i>=0; i--) {
            
            rightProduct[i] = nums[i+1]*rightProduct[i+1];
            
        }
        
        vector<int> ans(nums.size(),0);
        
        for(int i=0; i<nums.size(); i++) {
            ans[i] = leftProduct[i]*rightProduct[i];
        }
        
        return ans;
        
        
    }
};
