class Solution {
public:
    int countGoodSubstrings(string s) {
        
        if(s.length() < 3) return 0;
        unordered_map<char,int> mpp;
        int count = 0;
        int i = 0;
        int j = 0;
        
        while(j < s.length()) {
            
            mpp[s[j]]++;
            
            if(j-i+1==3) {
                
                if(mpp.size()==3) {
                    count++;
                }
                
                mpp[s[i]]--;
                if(mpp[s[i]]==0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            
            j++;
        }
       
        return count;
        
    }
};