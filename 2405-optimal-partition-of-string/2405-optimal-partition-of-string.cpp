class Solution {
public:
    int partitionString(string s) {
        
        int count = 0;
        unordered_map<char,int> mpp;
        
        for(int i=0; i<s.length(); i++) {
            
            if(mpp.find(s[i])!=mpp.end()) {
                count++;
                mpp.clear();
            } 
            mpp[s[i]]++;
        }
        
        return count+1;
    }
};