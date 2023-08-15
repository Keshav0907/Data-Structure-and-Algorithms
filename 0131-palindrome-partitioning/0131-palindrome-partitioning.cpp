class Solution {
public:
    
    
    bool isPalindrome(string s,int i,int j) {
        
        while(i <= j) {
            if(s[i++]!=s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    void f(int index,vector<string> &path,vector<vector<string>> &res,string s) {
         
        if(index==s.size()) {
            res.push_back(path);
            return;
        }
         
        for(int i=index; i<s.length(); i++) {
            
            if(isPalindrome(s,index,i)) {
                path.push_back(s.substr(index,i-index+1));
                f(i+1,path,res,s);
                path.pop_back();
                
            }
            
        }
            
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        
        vector<string> path;
        
        f(0,path,res,s);
        
        return res;
        
    }
};