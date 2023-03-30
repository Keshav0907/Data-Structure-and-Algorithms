class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = 2*nums.size();
        vector<int> vec(size,0);
        
        for(int i=0; i<nums.size(); i++) {
            vec[i]=nums[i];
            vec[i+nums.size()] = nums[i];
        }
        
        return vec;
    }
};