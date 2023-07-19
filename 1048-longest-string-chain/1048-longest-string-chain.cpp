
class Solution {
    
public:
    static bool cmp(string &s1,string &s2) {
    return s1.size() < s2.size();
}
    
   bool ifPossible(string s1,string s2) {
       
       if(s1.size()!=s2.size()+1) return false;
       int first = 0;
       int second = 0;
       while(first < s1.size()) {
           
           if(s1[first]==s2[second]) {
               first++;
               second++;
           } else {
               first++;
           }
           
       }
      
       
       return (first==s1.size() && second==s2.size());
       
   }
    
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n,1);
        
        for(int i=0; i<n; i++) {
            
            for(int j=0; j<i; j++) {
                
            if(ifPossible(words[i],words[j]) && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
            }
                
            }
            maxi = max(dp[i],maxi);
        }
        
     
        
        return maxi;
    }
};