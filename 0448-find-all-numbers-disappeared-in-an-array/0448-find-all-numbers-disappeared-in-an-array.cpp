class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        
        for(int i=0; i<nums.size();) {
            
            int correct_idx = nums[i]-1;
            
            if(nums[i]!=nums[correct_idx]) {
                swap(nums[i],nums[correct_idx]);
            } else {
                i++;
            }
        }
        
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=i+1) {
                ans.push_back(i+1);
            }
        }
        
        return ans;
        
    }
};