class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int idx = 0;
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size());
        
        for(int i=0; i<nums.size(); i++) {
            hash[i] = i;
            for(int j=0; j<i; j++) {
                
                if(nums[i]%nums[j]==0 && 1+dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }    
            }
        }
        
        for(int i=1; i<dp.size(); i++) {
            if(dp[i]>dp[idx]) {
                idx = i;
            }
        }
        
        
        vector<int> temp;
        temp.push_back(nums[idx]);
        while(hash[idx]!=idx) {
            idx = hash[idx];
            temp.push_back(nums[idx]);
            
        }
        
        reverse(temp.begin(),temp.end());
        
        return temp;
        

    }
};