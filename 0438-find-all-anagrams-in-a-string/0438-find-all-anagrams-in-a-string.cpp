class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        if(p.length() > s.length()) {
            return ans;
        }
        
        vector<int> pHash(26,0);
        vector<int> sHash(26,0);
        
        for(int i=0; i<p.length(); i++) {
            pHash[p[i]-'a'] +=1 ;
            sHash[s[i]-'a'] +=1;
        }
        
         
        int left = 0;
        int right = p.length()-1;
        
        while(right < s.length()) {
            
            if(pHash == sHash) {
                ans.push_back(left);
            }
            right++;
            if(right!=s.length()) {
                sHash[s[right]-'a']++;
            }
            
            sHash[s[left]-'a']--;
            left++;
                
        }
    
        
        
        return ans;
        
    
    }
    

};