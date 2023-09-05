class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            
            sum += nums[i];
            
            if(mpp.find((sum%k+k)%k)!=mpp.end()) {
                count += mpp[(sum%k+k)%k];
            }
            
            mpp[(sum%k+k)%k]++;
        }
        return count;
    }
};