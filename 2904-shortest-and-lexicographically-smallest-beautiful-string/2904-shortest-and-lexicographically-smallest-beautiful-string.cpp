class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        
         
          int i = 0;
          int j = 0;
          int count = k; 
          int minLength =  INT_MAX;
          string ans = "";
          while(j < s.length()) {
              
              if(s[j]=='1') {
                 count--;
              }
              
              while(count < 0 || s[i]=='0') {
              
                  if(s[i]=='1') count++;
                  i++;
              }
              if(count==0) {
                  
                 if(j-i+1<=minLength) {
                      minLength = j-i+1;
                      string temp = s.substr(i,j-i+1);
                    
                      if(ans.size()==0) {
                          ans = temp;
                      }
                      else if(temp.length() < ans.length()) {
                        ans = temp;  
                      }  else {
                          ans = min(ans,temp);
                      }
                   
                   
                     
                 }
              }
            
              
              j++;
           
          }
          
        return ans;
        
        
    }
};