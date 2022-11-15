class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()) {
            return false;
        }
        
        unordered_map<int,int> mpp;
        
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }
        
        int count = mpp.size();
        
        for(int i=0; i<n; i++) {
            mpp[t[i]]--;
            if(mpp[t[i]]==0) {
                count--;
            }
        }
                   
        return count==0;
    }
};