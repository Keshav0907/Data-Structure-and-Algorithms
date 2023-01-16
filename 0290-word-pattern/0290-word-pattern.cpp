class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        
        unordered_map<char,string> mpp;
        unordered_map<string,char> mpp2;
        
        int numberOfSpaces = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') {
                numberOfSpaces++;
            }
        }
        
        if(numberOfSpaces!=pattern.length()-1){
            return false;
        }
        
        int i=0;
        
        for(auto ch: pattern) {
            
            string str = "";
            
            while(s[i]!=' ' && i<s.length()) {
                str += s[i];
                i++;
            }
            i++;
            
            if(mpp.find(ch)==mpp.end() && mpp2.find(str)==mpp2.end()) {
                mpp[ch] = str;
                mpp2[str] = ch;
            } else {
                
                if(mpp[ch]!=str && mpp2[str]!=ch) {
                    return false;
                }
                
            }
            
        }
        
        
        
        
        return true;
    }
};