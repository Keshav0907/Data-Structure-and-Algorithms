class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
     
        int n = nums.size()/2;
        unordered_map<int,int> mpp;
        for(auto el : nums) {
            
            mpp[el]++;
            if(mpp[el]==n) {
                return el;
            }
            
        }
        
        return -1;
    }
};