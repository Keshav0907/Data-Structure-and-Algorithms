class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int zeroCount = 0;
        
        while(j < nums.size()) {
            
            if(nums[j]==0) zeroCount++;
            if(zeroCount > 0) {
                while(zeroCount > 0) {
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