class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int result = 0;
     
        for(auto x : left) {
            result = max(x,result);
        }
        
        for(auto x : right) {
            result = max(n-x,result);
        }
        
        return result;
    }
};