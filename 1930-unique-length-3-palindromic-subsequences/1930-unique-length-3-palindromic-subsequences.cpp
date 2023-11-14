class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
      
       unordered_map<char,vector<int>> mpp;
       
       for(int i=0; i<s.length(); i++) {
           mpp[s[i]].push_back(i);
       }
        
       int ans = 0;
        
       for(auto p : mpp) {
           
           auto v = p.second;
           unordered_set<int> st;
           if(v.size() >=2) {
               
               for(int j=v[0]+1; j<v.back();j++) {
                   
                   st.insert(s[j]);      
                   
               }
               
               ans += st.size();
           }
           
           
           
           
       }
         
        
        return ans;
        
    }
};

