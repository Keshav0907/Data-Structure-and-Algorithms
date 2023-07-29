class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        int maxFreq = -1;
        int ans = INT_MAX;;
        for(int i=0; i<nums.size(); i++) {
            
            if((nums[i]&1)==0) {
                 freq[nums[i]]++;   
                  maxFreq = max(maxFreq,freq[nums[i]]);
            }
        
        }
        
        if(freq.size()==0) return -1;
        
        for(auto it : freq) {
            if(it.second==maxFreq) {
                ans = min(it.first,ans);
                
            }
        }        
        
       return ans;
    }
};