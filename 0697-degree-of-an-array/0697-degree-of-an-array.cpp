class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        unordered_map<int,int> fSeen;
        int degree = 0;
        int minLen = INT_MAX;
        
        for(int i=0; i<nums.size(); i++) {
          
            if(fSeen.find(nums[i])==fSeen.end()) fSeen[nums[i]]=i;
            mpp[nums[i]]++;
            if(mpp[nums[i]]>degree) {
                degree = mpp[nums[i]];
                minLen = i-fSeen[nums[i]]+1;
            } else if(mpp[nums[i]]==degree) {
                minLen = min(minLen, i-fSeen[nums[i]]+1);
            }
            
        }
                
       return minLen;
    }
};