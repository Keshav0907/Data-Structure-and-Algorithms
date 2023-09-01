class Solution {
public:
    int beautySum(string s) {
        
        int ans = 0;
        int n = s.length();
        
        for(int i=0; i<n; i++) {
           
            map<char,int> mpp;
            for(int j=i; j<n; j++) {
                mpp[s[j]]++;
                int leastFreq = INT_MAX;
                int maxFreq = INT_MIN;
                
                for(auto it : mpp) {
                    leastFreq = min(leastFreq,it.second);
                    maxFreq = max(maxFreq,it.second);
                }
                
                ans += maxFreq-leastFreq;
            }
            
        }
                
        return ans;
    
    }
};