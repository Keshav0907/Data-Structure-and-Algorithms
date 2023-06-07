class Solution {
public:
    int characterReplacement(string s, int k) {
     
        vector<int> charMap(26,0);
        int maxFreq = 0;
        int i=0;
        int j=0;
        int result = 0;
        
        while(j < s.length()) {
            
            charMap[s[j]-'A']++;
            maxFreq = max(maxFreq,charMap[s[j]-'A']);
            if(j-i+1 - maxFreq > k) {
                charMap[s[i]-'A']--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        
        
        return result;
    }
};