class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int zeroCount = 0;
        
        while(j < nums.size()) {
            
            if(nums[j]==0) {
                zeroCount++;
            }
            
            if(zeroCount > k) {
                while(zeroCount > k) {
                    if(nums[i]==0) {
                        zeroCount--;
                    }
                    
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};