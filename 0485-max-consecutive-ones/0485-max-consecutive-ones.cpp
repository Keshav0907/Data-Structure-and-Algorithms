class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
//         int i = 0;
//         int j = 0;
//         int ans = INT_MIN;
//         int zeroCount = 0;
        
//         while(j < nums.size()) {
            
//             if(nums[j]==0) zeroCount++;
//             if(zeroCount > 0) {
//                 while(zeroCount > 0) {
//                     if(nums[i]==0) {
//                         zeroCount--;
//                     }
//                     i++;
//                 }
//             }
//             ans = max(ans,j-i+1);
//             j++; 
//         }
//         return ans;
        
        int maxLength = 0;
        int cnt = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                cnt++;
            } else {
                cnt = 0;
            }
            maxLength  = max(maxLength,cnt);
        }
        return maxLength;
    }
};