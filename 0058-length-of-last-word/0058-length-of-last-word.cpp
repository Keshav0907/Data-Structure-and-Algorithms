class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length();
        
        int i = n-1;
        
        while(i>=0 && s[i]==' ') {
            i--;
        }
        
        int length = 0;
        
        while(i>=0 && s[i]!=' ') {
            i--;
            length++;
        }
        
        return length;
        
    }
    
    // int lengthOfLastWord(string s) { 
    //     int len = 0, tail = s.length() - 1;
    //     while (tail >= 0 && s[tail] == ' ') { tail--;} 
    //     while (tail >= 0 && s[tail] != ' ') {
    //         len++;
    //         tail--;
    //     }
    //     return len;
    // }
};