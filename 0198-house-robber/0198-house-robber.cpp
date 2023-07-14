// vector<int> dp(101,-1);
class Solution {
public:
    
//     int helper(vector<int> &nums,int i,int size) {
        
//         if(i>=size) return 0;
//         if(i==size-1) return nums[i];
//         if(dp[i]!=-1) return dp[i];
//         return dp[i]=max(nums[i]+helper(nums,i+2,size),helper(nums,i+1,size));
        
//     }
    
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return nums[0];
        vector<int> dp(size);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2; i<size; i++) {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
       
        return dp[size-1];
    }
};