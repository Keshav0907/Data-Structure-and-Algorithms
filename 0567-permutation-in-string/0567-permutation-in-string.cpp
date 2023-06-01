class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.length() < s1.length()) return false;
        int k = s1.length();
        int i=0;
        int j=0;
        unordered_map<char,int> mpp;
        
        for(auto ch : s1) {
            mpp[ch]++;
        }
        
        int count = mpp.size();
        cout << count;
        while(j < s2.length()) {
            
            if(mpp.find(s2[j])!=mpp.end()) {
               mpp[s2[j]]--;
               if(mpp[s2[j]]==0) { 
                  count--;
               }
            }
            
            if(j-i+1==k) {
                if(count==0) return true;
                if(mpp.find(s2[i])!=mpp.end()) {
                mpp[s2[i]]++;
                if(mpp[s2[i]]==1) {
                    count++;
                }
               
            }
          i++;   
        }
            j++;
        }
        
        return false;
    }
};