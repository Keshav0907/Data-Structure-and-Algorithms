class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        vector<int> charMap(26,0);
        int maxFreq = 0;
        int i=0;
        int j=0;
        int result = 0;
        
        while(j < answerKey.length()) {
            
            charMap[answerKey[j]-'A']++;
            maxFreq = max(maxFreq,charMap[answerKey[j]-'A']);
            if(j-i+1 - maxFreq > k) {
                charMap[answerKey[i]-'A']--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        
        
        return result;
    }
};