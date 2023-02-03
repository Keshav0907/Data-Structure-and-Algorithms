class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> ans;
        
        if(s.length()<10) {
            return ans;
        }
        
        unordered_map<string,int> mpp;
        
         
        for(int i=0; i<=s.length()-10; i++) {
            string substring = s.substr(i,10);
                mpp[substring]++;
        }   
        
        for(auto it: mpp) {
            if(it.second>1) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};