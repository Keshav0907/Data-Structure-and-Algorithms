class Solution {
public:
    int minSwaps(string s) {
        
      
          int count =0;
        int ans = 0;
        
        for(int i=0; i<s.length(); i++) {
            
            if(s[i] == '['){
                count--;
            } else {
                count++;
            }
            
           
            
            ans = max(ans,count);
            
        }
        
        
        
        
        
        
        
        
        
        
        return (ans+1)/2;
    }
};