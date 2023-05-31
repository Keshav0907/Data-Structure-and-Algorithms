class Solution {
public:
    string minWindow(string s, string t) {
     
        unordered_map<char,int> mpp;
        
        for(auto ch : t) {
            mpp[ch]++;
        }
        
        int count = mpp.size();
        int idx = 0;
        int size = INT_MAX;
        
        int i=0; 
        int j=0;
        while(j < s.length()) {
            
            if(mpp.find(s[j])!=mpp.end()) {
                mpp[s[j]]--;
                if(mpp[s[j]]==0) {
                    count--;
                }
            }
            
            if(count==0) {
                
                if(size > (j-i+1)) {
                    size = j-i+1;
                    idx = i;
                }
                
                while(count==0) {
                    
                if(mpp.find(s[i])==mpp.end()) {
                    i++;
                   if(size > (j-i+1)) {
                    size = j-i+1;
                    idx = i;
               } 
               }
               else {
                  
                   mpp[s[i]]++;
                   if(mpp[s[i]]>0) {
                       i++;
                       count++;
                   }
                   else {
                       
                    i++;
                    if(size > (j-i+1)) {
                    size = j-i+1;
                    idx = i;   
                }
                       
              }
                
            }
          
            
        }
     }
        
       j++; 
   }
        return size==INT_MAX ? "" : s.substr(idx,size);
    }
      

};






