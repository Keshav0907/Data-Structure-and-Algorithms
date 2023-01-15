class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int> mpp;
        unordered_map<char,int> mpp2;
        string x = "balloon";
        
        for(auto ch : x) {
            mpp[ch]++;
        }
        
        
        for(auto ch : text) {
            mpp2[ch]++;
        }
        
        int maxi = text.length();
        
        for(auto ch : x) {
            int result = mpp2[ch]/mpp[ch];
            maxi = min(maxi,result);
        }
        
        
        return maxi;
        
        
    }
};