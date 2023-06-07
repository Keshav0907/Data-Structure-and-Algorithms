class Solution {
public:
    int minFlips(string s) {
        
        int n = s.size();
        s += s;
        
        string s1 = "";
        string s2 = "";
        
        for(int i=0; i<s.size(); i++) {
            s1 += (i%2==0) ?  "0" : "1";
            s2 += (i%2==0) ? "1" : "0";
        }
        
        int ans1 = 0;
        int ans2 = 0;
        int ans = s.size();
        
        for(int i=0; i<s.size(); i++) {
            
            ans1 +=(s1[i]!=s[i]);
            ans2 +=(s2[i]!=s[i]);
            
            if(i >=n) {
                ans1-=(s1[i-n]!=s[i-n]);
                ans2-=(s2[i-n]!=s[i-n]);
            }
            
            if(i >= (n-1)) {
                ans = min(ans,min(ans1,ans2));
            }
        }
        return ans;
        
        
    }
};