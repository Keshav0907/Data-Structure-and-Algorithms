class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> mpp;
        
        for(int i=0; i<s.length(); i++) {
            mpp[s[i]] = i;
        }
        
        vector<int> ans;
        int prev = -1;
        int maxi  = 0;
        for(int i=0;i<s.length(); i++) {
            maxi = max(maxi,mpp[s[i]]);
            if(i==maxi) {
                ans.push_back(maxi - prev);
                prev =  maxi;
            } 
        }
        
        return ans;
    }
};