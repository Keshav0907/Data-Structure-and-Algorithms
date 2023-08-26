class Solution {
public:
    
    bool static comp(vector<int> &a,vector<int> &b) {
    
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
     
        sort(pairs.begin(),pairs.end(),comp);
        int count = 1;
        
        int sec = pairs[0][1];
        for(int i=1; i<pairs.size(); i++) {
            
            if(sec < pairs[i][0]) {
                count++;
                sec = pairs[i][1];
            }
            
        }
        return count;
    }
};