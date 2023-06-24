class Solution {
public:
    
    bool isReverse(string s1, string s2) {
        
        reverse(s1.begin(),s1.end());
        
        // cout << s1 << " " << s2 << endl;;
        return s1==s2;
        
    }
    
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        int count = 0;
        unordered_map<string,int> mpp;
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if(mpp.find(words[i])==mpp.end() && mpp.find(words[j])==mpp.end() && isReverse(words[i],words[j])) {
    
                    mpp[words[i]]++;
                    mpp[words[j]]++;
                    count++;
                }
            }
        }
        
        return count;
        
    }
};