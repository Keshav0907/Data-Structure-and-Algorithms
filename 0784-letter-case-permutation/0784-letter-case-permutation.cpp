class Solution {
public:
    vector<string> str;
    unordered_map<string,int> mpp;
    void helper(string s,int i) {
        
        if(i==s.length()) {
            // str.push_back(s);
            mpp[s]++;
            return;
        }
        
        // string s1;
        if(isalpha(s[i])) {
             s[i] = toupper(s[i]);
        }
        
        helper(s,i+1);
        // string s2;
          if(isalpha(s[i])) {
             s[i] = tolower(s[i]);
        }
        helper(s,i+1);
        
    }
    
    vector<string> letterCasePermutation(string s) {
        
        helper(s,0);
        for(auto mp : mpp) {
            str.push_back(mp.first);
        }
        return str;
        
        
    }
};