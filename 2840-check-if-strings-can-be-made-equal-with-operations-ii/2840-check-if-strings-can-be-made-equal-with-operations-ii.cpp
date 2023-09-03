class Solution {
    
   private:
 
    bool equal(string l1,string l2) {
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end());
        return l1==l2;
    }
    
   public:
    
    bool checkStrings(string s1, string s2) {
        
        string l1 = "";
        string l2 = "";
           
        for(int i=0; i<s1.length(); i+=2) {
            l1 += s1[i];
            l2 += s2[i];
        }
        
        if(!equal(l1,l2)) return false;
        
        l1 = "";
        l2 = "";
        
        for(int i=1; i<s2.length(); i+=2) {
            l1 += s1[i];
            l2 += s2[i];
        }
        
        if(!equal(l1,l2)) return false;
        
        
        return true;
        
    }
};