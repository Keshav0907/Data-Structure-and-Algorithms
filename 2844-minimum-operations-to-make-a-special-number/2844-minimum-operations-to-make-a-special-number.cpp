class Solution {
 
    private:
    
    int check(string str,char ch1,char ch2) {
        int n = str.size();
        bool ch2Found = false;
        
        for(int i=n-1; i>=0; i--) {
            
            if(str[i]==ch2 && ch2Found==false) {
                ch2Found=true;
            } else if(str[i]==ch1 && ch2Found==true) {
                return n-(i+2);
            }
            
        }
        
        return n;
    }
    
public:
   
    int minimumOperations(string str) { 
        int n = str.length();
        int ans = str.length();
        int zeroCount = 0;
        
        ans = min(ans,check(str,'0','0'));
        ans = min(ans,check(str,'2','5'));
        ans = min(ans,check(str,'7','5'));
        ans = min(ans,check(str,'5','0'));
        
            
        for(int i=0; i<str.length();i++) {
            if(str[i]=='0'){
                zeroCount++;
            }
        }
        ans = min(ans,n-zeroCount);
        return ans;
    }
    
};